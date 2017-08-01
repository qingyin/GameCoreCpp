#include "LayerEx.h"


LayerEx::LayerEx(void)
{
	init();
}
LayerEx::~LayerEx(void)
{
}
bool LayerEx::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_bDelete = false;
	Size sizeTotal   = Director::getInstance()->getVisibleSize();
	setContentSize(sizeTotal);
	m_customListener = EventListenerTouchOneByOne::create();
	m_customListener->setSwallowTouches(true);
	m_customListener->onTouchBegan =  CC_CALLBACK_2(LayerEx::onTouchBegan,this);
	m_customListener->onTouchEnded = CC_CALLBACK_2(LayerEx::onTouchEnded,this);

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(m_customListener,this);
	return true;
}
void LayerEx::setSwallowTouches(bool bSwallow)
{
	m_customListener->setSwallowTouches(bSwallow);
}

void LayerEx::setDelete(bool bDelete)
{
	m_bDelete = bDelete;
}

bool LayerEx::onTouchBegan(Touch *t, Event *e)
{
	return true;
}

void LayerEx::onTouchEnded(Touch *t, Event *e)
{
	if (m_bDelete)
	{
		removeFromParent();
	}
}
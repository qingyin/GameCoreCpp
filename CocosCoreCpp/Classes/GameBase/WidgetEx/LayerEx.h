#pragma once

#include "cocos2d.h"

USING_NS_CC;

class LayerEx : public Layer
{
public:
	LayerEx(void);
	~LayerEx(void);
	virtual bool init();
	void setSwallowTouches(bool bSwallow = true);
	bool onTouchBegan(Touch *t, Event *e); 
	void onTouchEnded(Touch *t, Event *e);

	void setDelete(bool bDelete = true);
private:
	bool m_bDelete;
	EventListenerTouchOneByOne * m_customListener;
};


#include "WXLoginTest.h"

USING_NS_CC;

FV_SINGLETON_STORAGE(WXLoginTest);

WXLoginTest::WXLoginTest(void)
{
	MissionWeiXin::Instance().setMissionSink(this);
}


WXLoginTest::~WXLoginTest(void)
{
}
bool WXLoginTest::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto menuBtn = MenuItemFont::create("wx_login",CC_CALLBACK_1(WXLoginTest::menuCallBack,this));
	menuBtn->setName("wx_login");

	auto menu = Menu::create(menuBtn, NULL);
	//menu->setPosition(Vec2::ZERO);
	menu->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(menu, 1);

	return true;
}

void WXLoginTest::menuCallBack(cocos2d::Ref* pSender)
{
	MenuItemFont* item = static_cast<MenuItemFont*>(pSender);
	const std::string name = item->getName();
	if (name == "wx_login")
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		std::string kNickName = "o3aFvxNSkFwD8cOTLxR2Njgnl";//utility::toString(time(NULL));
		//std::string kNickName = utility::toString(time(NULL));
		m_kWeiXinUserInfo.openid = kNickName;	
		m_kWeiXinUserInfo.nickname = kNickName;
		m_kWeiXinUserInfo.headimgurl = "http:\\assssssssssssssssssssssss";
		onWxLoginSuccess(m_kWeiXinUserInfo);
#else
		MissionWeiXin::Instance().logonWeiXin();
#endif

	}else{

	}
}

void WXLoginTest::onWxLoginSuccess(WxUserInfo kWxUserInfo )
{
	m_kWeiXinUserInfo = kWxUserInfo;

	std::string kAccounts = "WeiXin"+m_kWeiXinUserInfo.openid;
}
void WXLoginTest::onWxLoginFail(std::string kError)
{
	log("onWxLoginFail----kError:%s",kError.c_str());
}
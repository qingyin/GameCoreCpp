#pragma once

#include "GameBase/Game/MissionWeiXin.h"
#include "Core/FV/FvSingleton.h"
#include "cocos2d.h"

class WXLoginTest 
	: public cocos2d::Layer
	,public IWeiXinMissionSink
	,public FvSingleton<WXLoginTest>
{
public:
	WXLoginTest(void);
	~WXLoginTest(void);
	virtual bool init();
	CREATE_FUNC(WXLoginTest);
	void menuCallBack(cocos2d::Ref* pSender);
public:
	virtual void onWxLoginSuccess(WxUserInfo kWxUserInfo );
	virtual void onWxLoginFail(std::string kError);
private:

	WxUserInfo m_kWeiXinUserInfo;
};


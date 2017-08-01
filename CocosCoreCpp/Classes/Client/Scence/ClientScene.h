#pragma once

#include "cocos2d.h"
class ClientScene : public cocos2d::Layer
{
public:
	ClientScene(void);
	~ClientScene(void);
	virtual bool init();
	CREATE_FUNC(ClientScene);
	static cocos2d::Scene* createScene();
};


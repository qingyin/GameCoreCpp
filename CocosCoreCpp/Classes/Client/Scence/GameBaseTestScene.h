#pragma once
#include "cocos2d.h"
class GameBaseTestScene : public cocos2d::Layer
{
public:
	GameBaseTestScene(void);
	~GameBaseTestScene(void);
	static cocos2d::Scene* createScene();
};


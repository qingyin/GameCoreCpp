#pragma once

#include "cocos2d.h"

#include "GameBase/WidgetEx/LayerEx.h"
USING_NS_CC;
class GameBaseScene : public Layer
{
public:
	CREATE_FUNC(GameBaseScene);
	GameBaseScene(void);
	~GameBaseScene(void);
	bool init();
	static Scene* createScene();
};


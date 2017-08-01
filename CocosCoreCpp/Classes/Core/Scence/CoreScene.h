#pragma once

#include "cocos2d.h"

#include "GameBase/WidgetEx/LayerEx.h"

USING_NS_CC;
class CoreScene : public Layer
{
public:
	CREATE_FUNC(CoreScene);
	CoreScene(void);
	~CoreScene(void);
	bool init();
	static Scene* createScene();
};


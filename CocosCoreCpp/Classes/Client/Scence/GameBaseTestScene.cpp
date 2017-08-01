#include "GameBaseTestScene.h"

#include "GameBase/Scence/GameBaseScene.h"

USING_NS_CC;
GameBaseTestScene::GameBaseTestScene(void)
{
}


GameBaseTestScene::~GameBaseTestScene(void)
{
}

Scene* GameBaseTestScene::createScene()
{
	return (GameBaseScene::create())->createScene();
}
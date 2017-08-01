#include "GameBaseScene.h"

#include "GameBase/ViewTest/HttpClientTestView.h"

GameBaseScene::GameBaseScene(void)
{
	//init();
}
GameBaseScene::~GameBaseScene(void)
{
}
bool GameBaseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto view = HttpClientTest::create();
	this->addChild(view);
	return true;
}

Scene* GameBaseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameBaseScene::create();
	scene->addChild(layer);
	return scene;
}
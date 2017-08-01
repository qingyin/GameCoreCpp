#include "CoreScene.h"

#include "Core/Network/DownloaderTest.h"

CoreScene::CoreScene(void)
{
	//init();
}
CoreScene::~CoreScene(void)
{
}
bool CoreScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto view = DownloaderTests::create();
	this->addChild(view);
	return true;
}

Scene* CoreScene::createScene()
{
	auto scene = Scene::create();
	auto layer = CoreScene::create();
	scene->addChild(layer);
	return scene;
}
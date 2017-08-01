#include "ClientScene.h"

#include "Client/ViewTest/WXLoginTest.h"

USING_NS_CC;
ClientScene::ClientScene(void)
{
}


ClientScene::~ClientScene(void)
{
}

bool ClientScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto view = WXLoginTest::create();
	this->addChild(view);

	return true;
}
Scene* ClientScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ClientScene::create();
	scene->addChild(layer);
	return scene;
}
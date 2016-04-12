#include "MainScene.h"
//#include "Result.h"


Scene *MainScene::CreateScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();

	scene->addChild(layer);

	return scene;
}

bool MainScene::init()
{
	if (!CCLayer::init()){return false;}

	MakeBackground();
	Size winSize = Director::getInstance()->getWinSize();

	auto startButton = MenuItemImage::create("CloseNormalGo.png",
											 "CloseSelected.png",
											 CC_CALLBACK_1(MainScene::SceneShift, this));

	startButton->setPosition(Point(winSize.width/2, winSize.height/2));

	auto menu = Menu::create(startButton, NULL);

	this->setPosition(Point::ZERO);

	this->addChild(menu, 1);

	return true;
}

void MainScene::SceneShift(Ref *sender)
{
	CCLOG("PushButtom");

	Scene *nextScene /*= ResultScene::CreateScene()*/;

	TransitionFade *transition = TransitionFade::create(0.5f, nextScene);

	Director::getInstance()->replaceScene(transition);
}

//”wŒi‚Ì¶¬
void MainScene::MakeBackground()
{
	Size winSize = Director::sharedDirector()->getWinSize();

	Sprite* bgPtr = Sprite::create("ImageFile/test.png", CCRectMake(0, 0, 1024, 767));
	bgPtr->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
	this->addChild(bgPtr);
}

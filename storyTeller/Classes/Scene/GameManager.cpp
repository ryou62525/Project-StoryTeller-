//
//  GameManager.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/07.
//
//
#include "Test.hpp"
#include "Test2.hpp"
#include "ProvisionalScene.hpp"
#include "Stage.hpp"
#include "GameManager.hpp"
#include "Title.hpp"
USING_NS_CC;
using namespace cocos2d::ui;

Scene* GameManager::CreateScene()
{
    auto scene = Scene::create();
    Layer* layer = Stage::create();
    scene->addChild(layer);
    
    Layer* testLayer2 = Test2::create();
    scene->addChild(testLayer2);
    
    auto manageLayer = GameManager::create();
    scene->addChild(manageLayer);
    
    return scene;
}

bool GameManager::init()
{
    if(!Layer::create()){return false;}
    
    
    this->scheduleUpdate();
    
    return true;
}

void GameManager::update(float deltaTime)
{
    Test2* test2 = Test2::create();
    
    if(test2->getActive())
    {
        TransitionFade* trasition = TransitionFade::create(1.5, Title::CreateScene());
        Director::getInstance()->replaceScene(trasition);
    }
    CCLOG("%d",test2->getActive());
}
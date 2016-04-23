//
//  Title.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#include <Title.h>

USING_NS_CC;


Scene* Title::CreateScene()
{
    Scene* scene { Scene::create() };
    Layer* layer { Title::create() };
    scene->addChild(layer);
    return scene;
}

bool Title::init()
{
    if(!Layer::init()){ return false; }
    
    Size visibleSize { Director::getInstance()->getVisibleSize() };
    
    //背景
    Sprite* bgSprite { Sprite::create("Title.png") };
    
    bgSprite->setPosition(visibleSize / 2);
    
    this->addChild(bgSprite);
    
    return true;
}
//
//  Title.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/23.
//
//

#include "Title.hpp"

USING_NS_CC;

Scene* Title::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Title::create();
    
    scene->addChild(layer);
    return  scene;
}

bool Title::init()
{
    if(!Layer::init()){ return false; }
    
    Director* director = Director::getInstance();
    
    Size size = director->getWinSize();
    
    Sprite* bgSprite = Sprite::create("ImageFile/TITLE.png");
    
    //bgSprite->setScale(0.7, 0.7);
    bgSprite->setPosition(Vec2(size.width / 2, size.height / 2));
    
    this->addChild(bgSprite);
    
    return true;
    
}
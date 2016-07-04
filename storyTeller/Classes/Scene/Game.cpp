//
//  Game.cpp
//  storyTeller
//
//  Created by vantan on 2016/06/29.
//
//

#include "Game.hpp"

USING_NS_CC;

Scene* Game::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Game::create();
    
    scene->addChild(layer);
    return scene;
}

bool Game::init()
{
    if(!Layer::init()){return false;}
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto obj = Sprite3D::create("FbxFile/jimen_a.c3b");
    obj->setPosition(Vec2(visibleSize.width/2,visibleSize.height/4));
    obj->setRotation3D(Vec3(0,0,0));
    
    addChild(obj);
    
    
    return true;
}
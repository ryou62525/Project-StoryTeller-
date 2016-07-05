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
    
    auto obj = Sprite3D::create("FbxFile/Floor.c3b");
    obj->setTexture("FbxFile/grass.png");
    obj->setPosition3D(Vec3(visibleSize.width/2,visibleSize.height/4,0));
    obj->setScale(1000, 1000);
    obj->setRotation3D(Vec3(90,0,0));
    
    addChild(obj);
    
    return true;
}
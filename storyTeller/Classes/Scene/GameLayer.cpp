//
//  GameLayer.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#include "GameLayer.hpp"


Scene* GameLayer::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameLayer::init()
{
    if(!Layer::create()){return false;}
    
    
    return true;
}
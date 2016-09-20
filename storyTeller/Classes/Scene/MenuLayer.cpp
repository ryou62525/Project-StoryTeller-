//
//  MenuLayer.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#include "MenuLayer.hpp"

Scene* MenuLayer::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = MenuLayer::create();
    scene->addChild(layer);
    return scene;
}

bool MenuLayer::init()
{
    if(!Layer::create()){return false;}
    
    
    return true;
}
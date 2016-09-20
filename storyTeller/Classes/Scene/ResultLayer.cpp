//
//  ResultLayer.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#include "ResultLayer.hpp"

Scene* ResultLayer::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = ResultLayer::create();
    scene->addChild(layer);
    return scene;
}

bool ResultLayer::init()
{
    if(!Layer::create()){return false;}
    
    
    return true;
}
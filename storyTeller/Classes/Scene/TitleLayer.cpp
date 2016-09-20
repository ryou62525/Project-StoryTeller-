//
//  TitleLayer.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#include "TitleLayer.hpp"

Scene* TitleLayer::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = TitleLayer::create();
    scene->addChild(layer);
    return scene;
}

bool TitleLayer::init()
{
    if(!Layer::create()){return false;}
    
    
    return true;
}
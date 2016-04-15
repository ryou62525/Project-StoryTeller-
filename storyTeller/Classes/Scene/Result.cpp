//
//  Result.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#include <Result.h>

USING_NS_CC;

Result::Result()
{
    
}

Result::~Result()
{
    
}

Scene* Result::CreateScene()
{
    auto scene = Scene::create();
    auto layer = Result::create();
    scene->addChild(layer);
    return scene;
}

bool Result::init()
{
    if(!Layer::init()){ return false; }
    
    
    
    return true;
}

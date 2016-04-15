//
//  Title.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#include <Title.h>

USING_NS_CC;

Title::Title()
{
    
}

Title::~Title()
{
    
}

Scene* Title::CreateScene()
{
    auto scene = Scene::create();
    auto layer = Title::create();
    scene->addChild(layer);
    return scene;
}

bool Title::init()
{
    if(!Layer::init()){return false;}
    
    
    return true;
}
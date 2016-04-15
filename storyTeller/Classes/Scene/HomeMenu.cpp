//
//  Menu.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#include "HomeMenu.h"

USING_NS_CC;

HomeMenu::HomeMenu()
{
    
}

HomeMenu::~HomeMenu()
{
    
}

Scene* HomeMenu::CreateScene()
{
    auto scene = Scene::create();
    auto layer = HomeMenu::create();
    scene->addChild(layer);
    return scene;
}

bool HomeMenu::init()
{
    if(!Layer::init()){ return false; }
    
    
    
    return true;
}


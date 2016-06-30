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
    
    return true;
}
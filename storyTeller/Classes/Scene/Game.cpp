//
//  Game.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#include <Game.h>

USING_NS_CC;

Game::Game()
{
    
}

Game::~Game()
{
    
}

Scene* Game::CreateScene()
{
    auto scene = Scene::create();
    auto layer = Game::create();
    scene->addChild(layer);
    return scene;
}

bool Game::init()
{
    if(!Layer::init()){return false;}
    
    
    return true;
}
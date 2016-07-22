//
//  Game.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#include "Game.hpp"

Scene* Game::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Game::create();
    scene->addChild(layer);
    return  scene;
}

bool Game::init()
{
    if(!Layer::init()){return  false;}
    
    this->scheduleUpdate();
    
    return true;
}

void Game::update(float deltaTime)
{
    Label* label = Label::create();
    label->setPosition(500, 500);
    label->setString("test");
    this->addChild(label);
}


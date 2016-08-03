//
//  Result.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#include "Result.hpp"

Scene* Result::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Result::create();
    scene->addChild(layer);
    return  scene;
}

bool Result::init()
{
    if(!Layer::init()){return  false;}
    
    this->scheduleUpdate();
    
    return true;
}

void Result::update(float deltaTime)
{
    
    Label* label = Label::create();
    label->setPosition(500, 500);
    label->setString("test");
    this->addChild(label);

}
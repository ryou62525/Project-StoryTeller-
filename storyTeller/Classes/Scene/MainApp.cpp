//
//  MainApp.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/22.
//
//

#include "MainApp.hpp"
#include "Title.hpp"
#include "Home.hpp"
#include "Game.hpp"
#include "Result.hpp"

Scene* MainApp::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Home::create();
    scene->addChild(layer);
    return scene;
}

bool MainApp::init()
{
    if(!Layer::init()){return false;}
    return true;
}

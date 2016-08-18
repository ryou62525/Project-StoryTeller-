//
//  Test.cpp
//  storyTeller
//
//  Created by vantan on 2016/08/15.
//
//

#include "Test.hpp"
#include "ui/cocosGUI.h"
USING_NS_CC;

#include <vector>
using namespace std;

Scene* Test::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Test::create();
    scene->addChild(layer);
    return scene;
}

bool Test::init()
{
    if(!Layer::init()){return false;}
    Size winSize = Director::getInstance()->getWinSize();

    vector<string> pages;
    pages.push_back("Hello");
    pages.push_back("World");
    
    auto label = Label::createWithSystemFont(pages, "arial.ttf", 24);
    label->setfont
    
    return true;
}

void Test::update(float deltaTime)
{
 
}
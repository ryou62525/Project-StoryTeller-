//
//  Home.cpp
//  storyTeller
//
//  Created by vantan on 2016/05/02.
//  Created by vantan on 2016/07/19.
//
//

#include "Home.hpp"
#include "Game.hpp"
#include <fstream>

Scene* Home::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Home::create();
    
    scene->addChild(layer);
    return  scene;
}

bool Home::init()
{
    if(!Layer::init()){ return false; }
    
    CreateMenuWindow();
    
    return true;
}

void Home::update(float deltaTime)
{
    
}

void Home::CreateMenuWindow()
{
    //背景設定---------------------------------------------------------------------------------------------------
    background[0]->setPosition(960,555);
    addChild(background[0],t_HomeBg);
    reorderChild(background[0], 2);
    
    background[1]->setPosition(winSize.width/2.1, winSize.height/2);
    background[1]->setScale(0.8, 0.8);
    addChild(background[1],1);
    
    background[2]->setPosition(winSize.width/6, winSize.height/1.2);
    background[2]->setScale(0.2, 0.2);
    addChild(background[2],3);
    
    background[3]->setPosition(winSize.width/2, 100);
    addChild(background[3], 4);
    
    //ボタン設定-------------------------------------------------------------------------------------------------
    button[0]->setPosition(Vec2(150, 110));
    button[1]->setPosition(Vec2(400, 110));
    button[2]->setPosition(Vec2(650, 110));
    
    button[0]->setScale(0.15, 0.15);
    button[1]->setScale(0.15, 0.15);
    button[2]->setScale(0.15, 0.15);
    
    addChild(button[0],z_Icon);
    addChild(button[1],z_Icon);
    addChild(button[2],z_Icon);
    
    //ボタンのタッチイベント---------------------------------------------------------------------------------------
    button[0]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 1);
                                         }
                                     });
    
    button[1]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 2);
                                         }
                                     });
    
    button[2]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 1);
                                         }
                                     });
}
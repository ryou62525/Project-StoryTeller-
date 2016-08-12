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
USING_NS_CC;

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
//    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/TitleImagePath.txt");
//    std::ifstream inFile(filePath);
//    assert(inFile);
//    
//    size_t imageValue;
//    std::string _filePath;
//    Vec2 pos, size;
//    
//    inFile >> imageValue;
//    Sprite* background[imageValue];
//    
//    for(int i = 0; i < imageValue; i++)
//    {
//        inFile >> _filePath >> pos.x >> pos.y >> size.x >> size.y;
//        background[i] = Sprite::create(_filePath);
//        background[i]->setPosition(Vec2(pos.x, pos.y));
//        background[i]->setScale(size.x, size.y);
//        this->addChild(background[i]);
//    }

    background[0]->setPosition(960,555);
    background[0]->setScale(1, 1);
    addChild(background[0],z_HomeBg);
    
    background[1]->setPosition(winSize.width/2.1, winSize.height/2);
    background[1]->setScale(0.5, 0.5);
    addChild(background[1],z_Quest);
    
    background[2]->setPosition(winSize.width/6, winSize.height/1.2);
    background[2]->setScale(0.2, 0.2);
    addChild(background[2], z_HomeBg);
    
    background[3]->setPosition(winSize.width/2, 100);
    addChild(background[3], 4);
    
    //ボタン設定-------------------------------------------------------------------------------------------------
    button[0]->setPosition(Vec2(150, 120));
    button[1]->setPosition(Vec2(400, 120));
    button[2]->setPosition(Vec2(650, 120));
    
    button[0]->setScale(0.15, 0.15);
    button[1]->setScale(0.15, 0.15);
    button[2]->setScale(0.15, 0.15);
    
    addChild(button[0],z_Icon);
    addChild(button[1],z_Icon);
    addChild(button[2],z_Icon);
    
    //ステージ選択ボタン------------------------------------------------------------------------------------------
    stageSelectButton[0]->cocos2d::Node::setPosition(900, 500);
    stageSelectButton[0]->setScale(0.3,0.5);
    stageSelectButton[0]->setTitleText("不思議の国のアリス");
    stageSelectButton[0]->setTitleFontSize(256);
    stageSelectButton[0]->setTitleColor(Color3B::WHITE);
    stageSelectButton[0]->setEnabled(false);
    addChild(stageSelectButton[0],z_Quest);
    
    //ボタンのタッチイベント---------------------------------------------------------------------------------------
    button[0]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             SetSelectUnable(stageSelectButton[0]);
                                         }
                                     });
    
    button[1]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 3);
                                             this->reorderChild(stageSelectButton[0], 3);
                                             SetSelectDisable(stageSelectButton[0]);
                                         }
                                     });
    
    button[2]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             SetSelectUnable(stageSelectButton[0]);
                                         }
                                     });
    
    stageSelectButton[0]->addTouchEventListener([this](Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
                                     {
                                         auto gameScene=Game::CreateScene();
                                         Scene* transition;
                                         if(type == ui::Widget::TouchEventType::BEGAN)
                                         {
                                             transition = TransitionFade::create(1.0f, gameScene);
                                         }
                                         Director::getInstance()->replaceScene(transition);
                                     });
    
}

void Home::SetSelectUnable(ui::Button* button)
{
    button->setEnabled(false);
}

void Home::SetSelectDisable(ui::Button* button)
{
    button->setEnabled(true);
}
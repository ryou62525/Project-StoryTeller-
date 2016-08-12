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
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImage.txt");
    std::ifstream bgInFile(filePath);
    assert(bgInFile);
    
    std::string _filePath;
    Vec2 pos, size;
    int dOder;
    

    for(int i = 0; i < BG_IMAGE_VALUE; i++)
    {
        bgInFile >> _filePath >> pos.x >> pos.y >> size.x >> size.y >> dOder;
        background[i] = Sprite::create(_filePath);
        background[i]->setPosition(Vec2(pos.x, pos.y));
        background[i]->setScale(size.x, size.y);
        this->addChild(background[i],dOder);
    }
    //ボタン設定-------------------------------------------------------------------------------------------------
    filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUiImage.txt");
    std::ifstream uiInFile(filePath);
    assert(uiInFile);

    for(int i = 0; i < UI_IMAGE_VALUE; i++)
    {
        uiInFile >> _filePath >> pos.x >> pos.y >> size.x >> size.y >> dOder;
        button[i] = Button::create(_filePath);
        button[i]->setPosition(Vec2(pos.x, pos.y));
        button[i]->setScale(size.x, size.y);
        this->addChild(button[i],dOder);
    }
    //ステージ選択ボタン------------------------------------------------------------------------------------------
    filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeStageSelectImage.txt");
    std::ifstream stageSelectInFile(filePath);
    assert(stageSelectInFile);
    
    std::string uiText;
    float fontSize;
    bool enable;
    
    for(int i = 0; i < UI_IMAGE_VALUE; i++)
    {
        stageSelectInFile >> _filePath >> pos.x >> pos.y
                          >> size.x >> size.y >> uiText
                          >> fontSize >> enable >> dOder;
        
        stageSelectButton[i] = Button::create(_filePath);
        stageSelectButton[i]->Node::setPosition(Vec2(pos.x, pos.y));
        stageSelectButton[i]->setScale(size.x, size.y);
        stageSelectButton[i]->setTitleText(uiText);
        stageSelectButton[i]->setTitleFontSize(fontSize);
        stageSelectButton[i]->setTitleColor(Color3B::WHITE);
        stageSelectButton[i]->setEnabled(enable);
        this->addChild(stageSelectButton[i],dOder);
    }
    //ボタンのタッチイベント---------------------------------------------------------------------------------------
    button[0]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             SetSelectUnable(stageSelectButton[0]);
                                         }
                                     });
    
    button[1]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 3);
                                             this->reorderChild(stageSelectButton[0], 3);
                                             SetSelectDisable(stageSelectButton[0]);
                                         }
                                     });
    
    button[2]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             SetSelectUnable(stageSelectButton[0]);
                                         }
                                     });
    
    stageSelectButton[0]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         auto gameScene=Game::CreateScene();
                                         Scene* transition;
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             transition = TransitionFade::create(1.0f, gameScene);
                                         }
                                         Director::getInstance()->replaceScene(transition);
                                     });
    
}

void Home::SetSelectUnable(Button* button)
{
    button->setEnabled(false);
}

void Home::SetSelectDisable(Button* button)
{
    button->setEnabled(true);
}
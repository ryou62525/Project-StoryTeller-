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
    
    menuSerect = MenuSerect::HOME;
    sprite2 = Sprite::create("ImageFile/Menubg.png");
    sprite2->setPosition(960, 550);
    this->addChild(sprite2);

    SetBgImage();
    SetUiImage();
    
    return true;
}

void Home::update(float deltaTime)
{
    
}

void Home::SetBgImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImagePath.txt");
    std::ifstream inFile(filePath);
    assert(inFile);
    
    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;

    inFile >> imageValue;
    Sprite* bgSprite[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
        
        bgSprite[i] = Sprite::create(_imagePath);
        bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
        bgSprite[i]->setScale(size.x, size.y);
        this->addChild(bgSprite[i]);
    }
}

void Home::SetUiImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUIImage.txt");
    std::ifstream inFile(filePath);
    assert(inFile);
    
    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;
    
    inFile >> imageValue;
    
    ui::Button* button[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;

        button[i] = ui::Button::create(_imagePath);
        button[i]->setPosition(Vec2(pos.x, pos.y));
        button[i]->setScale(size.x, size.y);
        this->addChild(button[i]);
        button[i]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
   
    }
    button[1]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
}

void Home::SetQuestMenu()
{
    auto sprite = Sprite::create("ImageFile/kawabe.png");
    sprite->setPosition(1000, 600);
    sprite->setScale(0.5, 0.5);
    this->addChild(sprite);
}

void Home::touchEvent(Ref *pSender, ui::Widget::TouchEventType type)
{
    
    Scene* nextScene = Home::CreateScene();
    
    Scene* transition;
    
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            
            transition = TransitionFade::create(1.0f, nextScene);
            
            break;
            
        default:
            break;
    }
}
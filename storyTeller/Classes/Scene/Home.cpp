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
    
    auto application = Application::getInstance();
    auto platform = application->getTargetPlatform();

    
    menuSerect = MenuSerect::HOME;
    sprite2 = Sprite::create("ImageFile/Menubg.png");
    
    if(platform== Application::Platform::OS_IPHONE){
    
    sprite2->setPosition(960, 550);
        
    }
    
    if(platform== Application::Platform::OS_IPAD){
        
        sprite2->setPosition(1030, 850);
        
        
    }

    
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
    /////////////////////////////////////////////////////////////////////////
    
    auto application = Application::getInstance();
    auto platform = application->getTargetPlatform();
    
    
    if(platform== Application::Platform::OS_IPHONE){
        
    auto filePath_iphone = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImagePath_iphone.txt");
        
        std::ifstream inFile_iphone(filePath_iphone);
        assert(inFile_iphone);
        
        size_t imageValue;
        std::string _imagePath;
        Vec2 pos, size;
        
        inFile_iphone >> imageValue;
        Sprite* bgSprite[imageValue];
        for(int i = 0; i < imageValue; i++)
        {
            inFile_iphone >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
            
            bgSprite[i] = Sprite::create(_imagePath);
            bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
            bgSprite[i]->setScale(size.x, size.y);
            this->addChild(bgSprite[i]);
        }


        
    }
    
    if(platform==Application::Platform::OS_IPAD){
        
    auto filePath_ipad = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImagePath_Ipad.txt");
        
        std::ifstream inFile_ipad(filePath_ipad);
        assert(inFile_ipad);
        
        size_t imageValue;
        std::string _imagePath;
        Vec2 pos, size;
        
        inFile_ipad >> imageValue;
        Sprite* bgSprite[imageValue];
        for(int i = 0; i < imageValue; i++)
        {
            inFile_ipad >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
            
            bgSprite[i] = Sprite::create(_imagePath);
            bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
            bgSprite[i]->setScale(size.x, size.y);
            this->addChild(bgSprite[i]);
        }
        


    }
    

    
   }

void Home::SetUiImage()
{
    auto application = Application::getInstance();
    auto platform = application->getTargetPlatform();
    
    if(platform== Application::Platform::OS_IPHONE){

    
    auto filePath_iphone = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUIImage_iphone..txt");
        std::ifstream inFile_iphone(filePath_iphone);
    assert(inFile_iphone);
    
    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;
    
    inFile_iphone >> imageValue;
    
    ui::Button* button[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile_iphone >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;

        button[i] = ui::Button::create(_imagePath);
        button[i]->setPosition(Vec2(pos.x, pos.y));
        button[i]->setScale(size.x, size.y);
        this->addChild(button[i]);
        button[i]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
   
    }
  
    button[1]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
        
    }
    
    if(platform== Application::Platform::OS_IPAD){
        
        
        auto filePath_ipad = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUIImage_ipad.txt");
        std::ifstream inFile_ipad(filePath_ipad);
        assert(inFile_ipad);
        
        size_t imageValue;
        std::string _imagePath;
        Vec2 pos, size;
        
        inFile_ipad >> imageValue;
        
        ui::Button* button[imageValue];
        for(int i = 0; i < imageValue; i++)
        {
            inFile_ipad >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
            
            button[i] = ui::Button::create(_imagePath);
            button[i]->setPosition(Vec2(pos.x, pos.y));
            button[i]->setScale(size.x, size.y);
            this->addChild(button[i]);
            button[i]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
            
        }
        
        button[1]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
        
    }

    
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
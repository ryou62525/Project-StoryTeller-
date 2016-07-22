//
//  Home.cpp
//  storyTeller
//
<<<<<<< HEAD
//  Created by vantan on 2016/05/02.
=======
//  Created by vantan on 2016/07/19.
>>>>>>> master
//
//

#include "Home.hpp"
<<<<<<< HEAD

USING_NS_CC;
=======
#include "Game.hpp"
>>>>>>> master

Scene* Home::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Home::create();
<<<<<<< HEAD
    
=======
>>>>>>> master
    scene->addChild(layer);
    return  scene;
}

bool Home::init()
{
<<<<<<< HEAD
    if(!Layer::init()){ return false; }
    
//    Director* director = Director::getInstance();
//    Size size = director->getWinSize();
    SetBgImage();
=======
    menuSerect = MenuSerect::HOME;
    
    if(!Layer::init()){return  false;}
    
    //960 550
    sprite2 = Sprite::create("ImageFile/Menubg.png");
    sprite2->setPosition(960, 550);
    this->addChild(sprite2);
    //SetBgImage();
>>>>>>> master
    SetUiImage();
    
    return true;
}

<<<<<<< HEAD
=======
void Home::update(float deltaTime)
{
    
}

>>>>>>> master
void Home::SetBgImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImagePath.txt");
    std::ifstream inFile(filePath);
    assert(inFile);
<<<<<<< HEAD
    
    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;
    
=======

    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;

>>>>>>> master
    inFile >> imageValue;
    Sprite* bgSprite[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
<<<<<<< HEAD
        
=======

>>>>>>> master
        bgSprite[i] = Sprite::create(_imagePath);
        bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
        bgSprite[i]->setScale(size.x, size.y);
        this->addChild(bgSprite[i]);
    }
<<<<<<< HEAD
=======
    
>>>>>>> master
}

void Home::SetUiImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUIImage.txt");
    std::ifstream inFile(filePath);
    assert(inFile);
<<<<<<< HEAD
    
    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;
    
    inFile >> imageValue;
    
    ui::Button* button[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
        
=======

    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;

    inFile >> imageValue;

    
    ui::Button* button[imageValue];
    
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;

>>>>>>> master
        button[i] = ui::Button::create(_imagePath);
        button[i]->setPosition(Vec2(pos.x, pos.y));
        button[i]->setScale(size.x, size.y);
        this->addChild(button[i]);
<<<<<<< HEAD
        button[i]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
    }

=======
    }
    button[1]->addTouchEventListener(CC_CALLBACK_2(Home::touchEvent, this));
}

void Home::SetQuestMenu()
{
    auto sprite = Sprite::create("ImageFile/kawabe.png");
    sprite->setPosition(1000, 600);
    sprite->setScale(0.5, 0.5);
    this->addChild(sprite);
>>>>>>> master
}

void Home::touchEvent(Ref *pSender, ui::Widget::TouchEventType type)
{
    
<<<<<<< HEAD
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
=======
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            
            SetQuestMenu();
            
            break;

        default:
            break;
    }
}

>>>>>>> master

//
//  Test.cpp
//  storyTeller
//
//  Created by vantan on 2016/08/18.
//
//

#include "Test.hpp"
#include "../Utility/GameUtilis.hpp"
#include "../Utility/GameOption.hpp"
USING_NS_CC;
using namespace cocos2d::ui;

Scene* Test::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Test::create();
    scene->addChild(layer);
    return scene;
}

bool Test::init()
{
    if(!Layer::create()){return false;}
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto layer = Layer::create();
    
    scheduleUpdate();
    
    auto listView = ListView::create();
    listView->setContentSize(Size(240,320));
    listView->setPosition(Vec2(100,500));
    this->addChild(listView);
    
    
    Layer* testLayer = Layer::create();
    SetUI(testLayer, testButton, Vec2(winSize.width/2, winSize.height/2), Vec2(0.1,0.1));
    addChild(testLayer,4);
    
    {
//        sprite->setPosition3D(Vec3(0,0,-30));
//        layer->addChild(sprite);
    }
    
    {
        camera = Camera::createPerspective(60, (GLfloat)winSize.width/winSize.height, 1, 1000);
        camera->setCameraFlag(CameraFlag::USER1);
        camera->lookAt(Vec3(0,0,0));
        camera->setPosition3D(Vec3(0,0,10));
        camera->setRotation3D(Vec3(0,0,0));
        layer->addChild(camera);
        layer->setCameraMask((unsigned short)CameraFlag::USER1);
    }
    addChild(layer);
    
    for(int i = 0; i < 6; i++)
    {
        button[i] = Button::create("ImageFile/button1.png");
        button[i]->setContentSize(Size(300,120));
        button[i]->setPosition(button[i]->getContentSize()/2);
        
        auto layout = Layout::create();
        layout->setContentSize(button[i]->getContentSize());
        layout->addChild(button[i]);
        listView->addChild(layout);
    }
    
    return true;
}

void Test::update(float deltaTime)
{
//    auto user = UserDefault::getInstance();
//    CCLOG("%f", user->getFloatForKey("bgmVolume"));
}

void Test::Transform()
{
    button[0]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        cameraPos.x += 1;
        camera->setRotation3D(cameraPos);
        
    });
    
    button[1]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        cameraPos.x -= 1;
        camera->setRotation3D(cameraPos);
        
    });
    
    button[2]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        cameraPos.y += 1;
        camera->setRotation3D(cameraPos);
        
    });
    
    button[3]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        cameraPos.y -= 1;
        camera->setRotation3D(cameraPos);
        
    });
    
    button[4]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        cameraPos.z += 1;
        camera->setRotation3D(cameraPos);
        
    });
    
    button[5]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        cameraPos.z -= 1;
        camera->setRotation3D(cameraPos);
        
    });
}
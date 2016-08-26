//
//  Test.cpp
//  storyTeller
//
//  Created by vantan on 2016/08/18.
//
//

#include "Test.hpp"
USING_NS_CC;

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
    //auto layer = Layer::create();
    
    scheduleUpdate();

    rect = Sprite::create();
    rect->setPosition(Vec2(winSize.width * 0.3, winSize.height/2));
    rect->setTextureRect(Rect(0,0,200,200));
    rect->setColor(Color3B(255,0,0));
    this->addChild(rect);
    
    Vector<FiniteTimeAction*> actions;
    actions.pushBack(MoveTo::create(2.0f, Vec2(winSize.width/2, winSize.height/2)));
    actions.pushBack(MoveTo::create(2.0f, Vec2(winSize.width * 0.3, winSize.height/2)));
    
    auto sequence = Sequence::create(actions);
    auto repeat = RepeatForever::create(sequence);
    rect->runAction(repeat);
    
    auto button = ui::Button::create("ImageFile/UIOption.png");
    button->setPosition(Vec2(200,100));
    button->setScale(0.1);
    addChild(button);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sound/BGM/menu_bgm.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/BGM/menu_bgm.wav", true);
    
    button->addTouchEventListener([this](Ref *pSender, ui::Widget::TouchEventType type)
    {
        if(type == ui::Widget::TouchEventType::ENDED)
        {
            if(_pause)
            {
                this->resume();
                Director::getInstance()->startAnimation();
                CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
            }
            else
            {
                this->pause();
                Director::getInstance()->stopAnimation();
                CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
            }
            
            _pause = !_pause;
            
        }
    });
    
    
    
//    {
//        sprite->setPosition3D(Vec3(0,0,-580));
//        sprite->setScaleX(1);
//        layer->addChild(sprite);
//    }
//    
//    {
//        camera = Camera::createPerspective(61, (GLfloat)winSize.width/winSize.height, 1, 1000);
//        camera->setCameraFlag(CameraFlag::USER1);
//        camera->lookAt(Vec3(0,0,0));
//        camera->setPosition3D(Vec3(0,10,-23));
//        camera->setRotation3D(Vec3(0,0,0));
//        layer->addChild(camera);
//        layer->setCameraMask((unsigned short)CameraFlag::USER1);
//    }
//    addChild(layer);
    
    return true;
}

void Test::update(float deltaTime)
{
    auto user = UserDefault::getInstance();
    CCLOG("%f", user->getFloatForKey("bgmVolume"));
}
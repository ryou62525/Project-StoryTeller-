//
//  Sample.cpp
//  StoryTeller
//
//  Created by vantan on 2016/08/07.
//
//

#include "Sample.hpp"

USING_NS_CC;

Scene* Sample::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Sample::create();
    scene->addChild(layer);
    return scene;
}

bool Sample::init()
{
    if (!Layer::init()) return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    Sprite* sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    sprite->setScale(1.0f, 1.0f);
    this->addChild(sprite, 1);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch* touch, Event* event)->bool
    {
        CCLOG("began");
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(Sample::menuCloseCallBack, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
                                origin.y + closeItem->getContentSize().height / 2));
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    return true;
}

void Sample::menuCloseCallBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
}

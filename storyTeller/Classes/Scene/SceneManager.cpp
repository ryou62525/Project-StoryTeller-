//
//  SceneManager.cpp
//  storyTeller
//
//  Created by vantan on 2016/06/29.
//
//

#include "Title.hpp"
#include "SceneManager.hpp"
#include "HomeMenu.hpp"

USING_NS_CC;

int SceneManager::transisionNo = 0;

Scene* SceneManager::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = SceneManager::create();
    scene->addChild(layer);
    return scene;
}

bool SceneManager::init()
{
    if(!Layer::init()){return false;}
    
    Size pos = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite* bgSprite = Sprite::create("HelloWorld.png");
    bgSprite->setPosition(pos.width/2, pos.height/2);
    
    this->addChild(bgSprite);
    
    //イベントリスナーの生成
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        auto nextScene = Title::CreateScene();
        Scene* transision;
        
        transision = TransitionFade::create(1.0f, nextScene);
        Director::getInstance()->replaceScene(transision);
        return true;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void SceneManager::hogehoge()
{
    auto nextScene = Title::CreateScene();
    Scene* transision;
    transision = TransitionFade::create(1.0f, nextScene);
    Director::getInstance()->replaceScene(transision);
}
//
//  Character.cpp
//  StoryTeller
//
//  Created by vantan on 2016/08/01.
//
//

#include "Character.hpp"

USING_NS_CC;
using namespace ss;

Scene* Character::createScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Character::create();
    scene->addChild(layer);
    return scene;
    
}

Character::Character() {
    
}

Character::~Character()
{
}

bool Character::init()
{
    if(!Layer::init()) return false;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
   
    ssplayer = Player::create();
    
    manageSprite("storyteller.ssbp");
    
    ssplayer->setData("storyteller");
    ssplayer->play("st_girl/st_wait_girl01");
    ssplayer->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    ssplayer->setScale(0.5f, 0.5f);
    this->addChild(ssplayer);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(Character::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Character::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Character::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Character::onTouchCancelled, this);
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->scheduleUpdate();
    
    return true;
}

int i = 0;
int animation_count = 0;
void Character::update(float delta)
{
//    animation_count++;
//    if (animation_count % 180 == 0) {
//        ++i;
//        switch (i % 3) {
//            case 0:
//                ssplayer->play("st_girl/st_wait_girl01");
//                break;
//            
//            case 1:
//                ssplayer->play("st_girl/st_run_girl01");
//                break;
//            
//            case 2:
//                ssplayer->play("st_girl/st_attack_girl01");
//                break;
//        }
//    }
}


bool Character::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    ssplayer->play("st_girl/st_run_girl01");
    
    CCLOG("began");
    
    return true;
}

void Character::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 deltaPos = touch->getDelta();
    Vec2 pos = ssplayer->getPosition();
    Vec2 newPos = pos + deltaPos;
    newPos.getClampPoint(Vec2(0, 0), Vec2(visibleSize.width / 2, visibleSize.height / 2));
    ssplayer->setPosition(newPos);
    
    CCLOG("moved");
}

void Character::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    ssplayer->play("st_girl/st_wait_girl01");
    
    CCLOG("ended");
}

void Character::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
    CCLOG("cancelled");
}

void Character::manageSprite(const std::string& dataName_ssbp)
{
    auto ss5man = SS5Manager::getInstance();
    ss5man->createEffectBuffer(1024);
    
    auto resman = ResourceManager::getInstance();
    resman->addData(dataName_ssbp);
}
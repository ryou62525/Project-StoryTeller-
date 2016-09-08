//
//  Test2.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/02.
//
//

#include "Test2.hpp"
USING_NS_CC;
using namespace cocos2d::ui;

bool Test2::init()
{
    if(!Layer::create()){return false;}
    
    Size size = Director::getInstance()->getVisibleSize();
    
//    auto rect_1 = Sprite::create();
//    rect_1->setPosition(Vec2(size.width/3, size.height/2));
//    rect_1->setTextureRect(Rect(0,0,200,200));
//    rect_1->setColor(Color3B(255,0,0));
//    addChild(rect_1);
//    
//    auto rect_2 = Sprite::create();
//    rect_2->setPosition(Vec2(size.width/2.9, size.height/2));
//    rect_2->setTextureRect(Rect(0,0,200,200));
//    rect_2->setColor(Color3B(0,0,255));
//    addChild(rect_2);
    
//    Rect aabb_rect_1 = rect_1->getBoundingBox();
//    auto aabb_rect_2 = rect_2->getBoundingBox();
    
//    auto result = Label::create();
//    result->setPosition(Vec2(size.width/2, size.height/7));
//    result->setScale(3);
//    result->setString("接触してません");
//    addChild(result);
//    
//    if(aabb_rect_1.intersectsRect(aabb_rect_2))
//    {
//        result->setString("接触してます");
//    }
    
    auto layer = Layer::create();
    auto button = cocos2d::ui::Button::create("ImageFile/quest/pose/pose.png");
    button->setPosition(Vec2(size.width/1.1,size.height/6));
    button->setScale(0.5);
    
    button->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type){
        
        if(type == Widget::TouchEventType::ENDED)
        {
            active = true;
            CCLOG("%d",active);
        }
    });
    
    layer->addChild(button);
    addChild(layer);
 
    auto resman = ss::ResourceManager::getInstance();
    resman->addData("SpriteStudioFile/storyteller_project/storyteller.ssbp");
    
    auto player = ss::Player::create();
    player->setData("storyteller");
    player->play("st_girl/st_wait_girl01");
    player->setPosition(size/2);
    addChild(player);
    
    //player->runAction(MoveTo::create(2,Vec2(0,0)));
    
    
    return true;
}
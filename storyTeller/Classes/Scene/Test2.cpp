//
//  Test2.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/02.
//
//

#include "Test2.hpp"
USING_NS_CC;

Scene* Test2::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Test2::create();
    scene->addChild(layer);
    return scene;
}

bool Test2::init()
{
    if(!Layer::create()){return false;}
    
    Size size = Director::getInstance()->getVisibleSize();
    
    auto rect_1 = Sprite::create();
    rect_1->setPosition(Vec2(size.width/3, size.height/2));
    rect_1->setTextureRect(Rect(0,0,200,200));
    rect_1->setColor(Color3B(255,0,0));
    addChild(rect_1);
    
    auto rect_2 = Sprite::create();
    rect_2->setPosition(Vec2(size.width/2.9, size.height/2));
    rect_2->setTextureRect(Rect(0,0,200,200));
    rect_2->setColor(Color3B(0,0,255));
    addChild(rect_2);
    
    Rect aabb_rect_1 = rect_1->getBoundingBox();
    auto aabb_rect_2 = rect_2->getBoundingBox();
    
    auto result = Label::create();
    result->setPosition(Vec2(size.width/2, size.height/7));
    result->setScale(3);
    result->setString("接触してません");
    addChild(result);
    
    if(aabb_rect_1.intersectsRect(aabb_rect_2))
    {
        result->setString("接触してます");
    }
    
    return true;
}
//
//  Stage.cpp
//  storyTeller
//
//  Created by vantan on 2016/09/06.
//
//

#include "Stage.hpp"


bool Stage::init()
{
    if(!Layer::create()){return false;}
    Size size = Director::getInstance()->getVisibleSize();
    
    auto stage = Sprite3D::create("C3BFile/test_stage01.c3b");
    stage->setPosition3D(Vec3(size.width/2,size.height/5,0));
    stage->setScale(15);
    addChild(stage);
    
    return true;
}
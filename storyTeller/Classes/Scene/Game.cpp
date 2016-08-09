//
//  Game.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#include "Game.hpp"

Scene* Game::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Game::create();
    scene->addChild(layer);
    return  scene;
}

bool Game::init()
{
    if(!Layer::init()){return false;}

     
    
    pos = 0;
    auto layer = Layer::create();
    {
        stage = Sprite3D::create("FbxFile/st_stage01_floor01.c3b");
        stage->setScale(500);
        stage->setPosition(0,0);
        this->addChild(stage);
    }
    
    {

        
        
        //CCLOG("カメラのポジション　%f,%f,%f", pos.x, pos.y, pos.z);
    }
    
    this->scheduleUpdate();
    this->addChild(layer);
    
    return true;
}

void Game::update(float deltaTime)
{
    pos += 1;
    stage->setPosition3D(Vec3(visibleSize.width/2,0,1));
    stage->setRotation3D(Vec3(0,pos,0));
    
//    auto pos = stage->getPosition3D();
//    CCLOG("ステージのポジション　%f,%f,%f", pos.x, pos.y, pos.z);
}
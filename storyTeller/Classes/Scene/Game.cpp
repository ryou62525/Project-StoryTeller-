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
    if(!Layer::init()){return  false;}
    
    this->scheduleUpdate();
    
    return true;
}

void Game::setup(){
    
    countTimer = 0;
    
    gameTimeLimit =100;
    
    gameTime = gameTimeLimit;
    
    gameState = GAMESTATE::WAIT;

}


void Game::update(float deltaTime)
{
    
    Label* label = Label::create();
    label->setPosition(500, 500);
    label->setString("test");
    this->addChild(label);
    
}


void Game::timeControll(){
    
    this->scheduleUpdate();

    countTimer++;
    
    if(countTimer >= 60){
    
        gameState = GAMESTATE::START;
    
    }
    
    if(countTimer % 60 ==0){
    
        gameTime-=1;
        
    }
    
    if(gameState == GAMESTATE::START){
        
        auto label = Label::createWithTTF("", "fonts/rounded-mplus-1c-heavy.ttf", 80);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(500,900);
        label->setDimensions(1000, 500);
        label->setVisible(true);
        
    }



}


void Game::gameControll(){

   

}




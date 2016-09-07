//
//  GameTimer.cpp
//  Remake_StoryTeller
//
//  Created by vantan on 2016/09/05.
//
//

#include "GameTimer.hpp"


bool GameTimer::init(){
    
    if(!Layer::init()){return  false;}
    
    this->scheduleUpdate();
    setup();
    showTimeText();
    
    return true;
    
}


bool GameTimer::getGameTime(){


    if(gameTime == 0){
    
        return true;
    
    }


}

void GameTimer::setup(){
    
    countTimer = 0;
    
    gameTimeLimit =10;
    
    gameTime = gameTimeLimit;
    
    gameTime =10;
    
    gameState = GAMESTATE::WAIT;
    
    
}


void GameTimer::update(float deltaTime){
    
    timeControll();
    
}


void GameTimer::timeControll(){
    
    
    this->scheduleUpdate();
    
    countTimer++;
    
    if(countTimer >= 60){
        
        gameState = GAMESTATE::START;
        
    }
    
    if(countTimer % 60 ==0 && gameTime > 0){
        
        gameTime-=1;
        
    }
    
    int _gameTime = static_cast<int>(gameTime);
    gameTimeText->setString(StringUtils::toString(gameTime));
    
    
}


void GameTimer::countDown(){
    
    gameTime-=1;
    
}


void GameTimer::showTimeText(){
    
    this->scheduleUpdate();
    
    gameTimeText = Label::createWithTTF(StringUtils::toString(gameTime), "fonts/rounded-mplus-1c-heavy.ttf", 80);
    gameTimeText->setTextColor(Color4B::WHITE);
    gameTimeText->setPosition(1400,800);
    gameTimeText->setDimensions(1000, 500);
    gameTimeText->setVisible(true);
    this->addChild(gameTimeText);
    
}


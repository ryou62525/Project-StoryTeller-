//
//  Player.cpp
//  StoryTeller
//
//  Created by vantan on 2016/09/20.
//
//

#include "Player.hpp"

USING_NS_CC;

Player::Player()
{
    
}

bool Player::init()
{
    if (!ss::Player::init()) return false;
    
    return true;
}

void Player::onEnter()
{
    ss::Player::onEnter();
    
    ss::SS5Manager* ss5man = ss::SS5Manager::getInstance();
    ss5man->createEffectBuffer(1024);
    
    ss::ResourceManager* resman = ss::ResourceManager::getInstance();
    resman->addData("storyteller_project/storyteller.ssbp");
    
    setData("storyteller");
}
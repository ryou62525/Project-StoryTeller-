//
//  Player.hpp
//  StoryTeller
//
//  Created by vantan on 2016/09/20.
//
//

#ifndef Player_hpp
#define Player_hpp

#include "cocos2d.h"
#include "SSPlayer/SS5Player.h"


class Player : public ss::Player
{
    
public:
    Player();
    
    bool init() override;
    void onEnter() override;
    
private:
    
};

#endif /* Player_hpp */

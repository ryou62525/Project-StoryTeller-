//
//  Game.h
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#ifndef Game_h
#define Game_h

#include "cocos2d.h"

class Game : public cocos2d::Layer
{
protected:
    
    Game();
    virtual ~Game();
    
    bool init() override;
    
public:
    
    static cocos2d::Scene* CreateScene();
    CREATE_FUNC(Game)
    
};


#endif /* Game_h */

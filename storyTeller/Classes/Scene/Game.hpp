//
//  Game.hpp
//  storyTeller
//
//  Created by vantan on 2016/06/29.
//
//

#ifndef Game_hpp
#define Game_hpp

#include <cocos2d.h>

class Game : public cocos2d::Layer
{
  
public:
    
    static cocos2d::Scene* CreateScene();
    virtual bool init();
    
    CREATE_FUNC(Game)
};

#endif /* Game_hpp */

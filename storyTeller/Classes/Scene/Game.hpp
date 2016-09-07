//
//  Game.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef Game_hpp
#define Game_hpp

#include <cocos2d.h>
USING_NS_CC;

class Game : public cocos2d::Layer
{
public:

    int countTimer;
    int gameTime;
    int gameTimeLimit;
    
    int gameState;
    enum GAMESTATE{
    
    WAIT,
    START,
    END
    
    };
    
    static Scene* CreateScene();
    bool init();
    void setup();
    void update(float deltaTime);
    void gameControll();
    void timeControll();
    CREATE_FUNC(Game);
};

#endif /* Game_hpp */

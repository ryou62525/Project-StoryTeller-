//
//  GameTimer.hpp
//  Remake_StoryTeller
//
//  Created by vantan on 2016/09/05.
//
//

#ifndef GameTimer_hpp
#define GameTimer_hpp

#include <stdio.h>

USING_NS_CC;

class  GameTimer : public cocos2d::Layer
{
    
    
public:
    
    
    Label *gameTimeText;
    
    int countTimer;
    int gameTime;
    int gameTimeLimit;
    
    int gameState;
    enum GAMESTATE{
        
        WAIT,
        START,
        END
        
    };
    
    bool init();
    bool getGameTime();
    void setup();
    void update(float deltaTime);
    void timeControll();
    void countDown();
    void showTimeText();
    CREATE_FUNC(GameTimer);
    
    
};


#endif /* GameTimer_hpp */

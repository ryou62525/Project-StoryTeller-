//
//  Title.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef Title_hpp
#define Title_hpp

#include <cocos2d.h>
#include "../../cocos2d/cocos/audio/include/AudioEngine.h"
USING_NS_CC;
using namespace experimental;

class Title : public cocos2d::Layer
{
private:

    bool changeScene = false;
    int titleBgm;
    int se;
    float volume = 1;
    
    Sprite* sprite;
    DelayTime* delay;

public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);
    
    void SetImageInfo();
    void SetBlink(float blinkSpeed);
    void SetBgm();
    
    bool IsSoundless();
    
    CREATE_FUNC(Title)
};

#endif /* Title_hpp */
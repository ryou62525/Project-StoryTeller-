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
private:
    
    ActionCamera* camera;
    Sprite3D* stage;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
public:
    
    static Scene* CreateScene();
    bool init();
    void update(float deltaTime);
    
    CREATE_FUNC(Game)
};

#endif /* Game_hpp */

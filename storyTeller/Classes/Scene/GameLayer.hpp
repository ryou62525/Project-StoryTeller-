//
//  GameLayer.hpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include <cocos2d.h>
USING_NS_CC;

class GameLayer : public Layer
{
public:
    
    static Scene* createScene();
    bool init();
    
    CREATE_FUNC(GameLayer);
};

#endif /* GameLayer_hpp */

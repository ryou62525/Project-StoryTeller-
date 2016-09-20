//
//  MenuLayer.hpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#ifndef MenuLayer_hpp
#define MenuLayer_hpp

#include <cocos2d.h>
USING_NS_CC;

class MenuLayer : public Layer
{
public:
    
    static Scene* createScene();
    bool init();
    
    CREATE_FUNC(MenuLayer);
};

#endif /* MenuLayer_hpp */

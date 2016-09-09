//
//  Test2.hpp
//  storyTeller
//
//  Created by vantan on 2016/09/02.
//
//

#ifndef Test2_hpp
#define Test2_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
#include "../SSPlayer/SS5Player.h"
USING_NS_CC;

class Test2 : public Layer
{
    bool active = false;
public:
    
    bool getActive(){return active;}
    bool init();
    CREATE_FUNC(Test2);
    
};

#endif /* Test2_hpp */
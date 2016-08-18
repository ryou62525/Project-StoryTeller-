//
//  Test.hpp
//  storyTeller
//
//  Created by vantan on 2016/08/15.
//
//

#ifndef Test_hpp
#define Test_hpp

#include <cocos2d.h>
USING_NS_CC;

class Test : public cocos2d::Layer
{
    Camera* camera;
    

public:
    static cocos2d::Scene* CreateScene();
    bool init();
    void update(float deltaTime);
    CREATE_FUNC(Test)
};

#endif /* Test_hpp */
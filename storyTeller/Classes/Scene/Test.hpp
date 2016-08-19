//
//  Test.hpp
//  storyTeller
//
//  Created by vantan on 2016/08/18.
//
//

#ifndef Test_hpp
#define Test_hpp

#include <cocos2d.h>
USING_NS_CC;

class Test : public cocos2d::Layer
{
public:

    Camera* camera;
    static Scene* CreateScene();
    bool init();
    
    void update(float deltaTime);
    CREATE_FUNC(Test)
    
};

#endif /* Test_hpp */

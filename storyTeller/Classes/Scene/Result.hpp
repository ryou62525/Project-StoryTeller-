//
//  Result.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef Result_hpp
#define Result_hpp

#include <cocos2d.h>
USING_NS_CC;

class Result : public cocos2d::Layer
{
public:
    
    static Scene* CreateScene();
    bool init();
    void update(float deltaTime);
    CREATE_FUNC(Result)
};

#endif /* Result_hpp */

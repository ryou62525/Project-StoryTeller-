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
USING_NS_CC;

class Title : public cocos2d::Layer
{
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void SetImageInfo();
    void update(float deltaTime);
    CREATE_FUNC(Title)
    
};

#endif /* Title_hpp */
//
//  Home.hpp
//  storyTeller
//
//  Created by vantan on 2016/05/02.
//
//

#ifndef Home_hpp
#define Home_hpp

#include <cocos2d.h>

class Home : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* CreateScene();
    void SetUiImage();
    virtual bool init();
    
    CREATE_FUNC(Home)
};

#endif /* Home_hpp */

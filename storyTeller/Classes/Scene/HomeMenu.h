//
//  Menu.hpp
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#ifndef Menu_hpp
#define Menu_hpp

#include <cocos2d.h>

class HomeMenu : public cocos2d::Layer
{
protected:
    
    HomeMenu();
    virtual ~HomeMenu();
    
    bool init() override;
    
public:
    
    static cocos2d::Scene* CreateScene();
    CREATE_FUNC(HomeMenu);
    
};

#endif /* Menu_hpp */

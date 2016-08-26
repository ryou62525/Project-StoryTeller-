//
//  MainApp.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef MainApp_hpp
#define MainApp_hpp

#include <cocos2d.h>
USING_NS_CC;

class MainApp : public cocos2d::Layer
{
public:
    
    static Scene* CreateScene();
    bool init() override;
    CREATE_FUNC(MainApp)
    
};

#endif /* MainApp_hpp */

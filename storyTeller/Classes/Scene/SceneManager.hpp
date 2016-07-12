//
//  SceneManager.hpp
//  storyTeller
//
//  Created by vantan on 2016/06/29.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <cocos2d.h>

class SceneManager : public cocos2d::Layer
{
    static int transisionNo;
    
    int timer = 0;
public:
    
    static cocos2d::Scene* CreateScene();
    void hogehoge();
    virtual bool init();
    
    CREATE_FUNC(SceneManager)
};

#endif /* SceneManager_hpp */

//
//  Common.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/04.
//
//

#ifndef Common_hpp
#define Common_hpp

#include "cocos2d.h"

class Common : public cocos2d::Layer
{
public:
    
    virtual ~Common();
    virtual cocos2d::Scene* CreateScene();
    virtual bool init();
    virtual void Initialize();
    virtual void Finalize();
    virtual void Update();
    virtual void Draw();
    
};

#endif /* Common_hpp */

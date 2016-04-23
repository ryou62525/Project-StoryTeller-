//
//  Title.h
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#ifndef Title_h
#define Title_h

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
    
    
public:
    
    static cocos2d::Scene* CreateScene();
    
    virtual bool init() override;
    
    CREATE_FUNC(Title)
    
};


#endif /* Title_h */

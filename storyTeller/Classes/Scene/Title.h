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
protected:
    
    Title();
    virtual ~Title();
    
    bool init() override;
    
public:
    
    static cocos2d::Scene* CreateScene();
    CREATE_FUNC(Title)
    
};


#endif /* Title_h */

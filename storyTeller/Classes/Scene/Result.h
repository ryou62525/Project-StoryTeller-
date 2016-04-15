//
//  Result.h
//  storyTeller
//
//  Created by vantan on 2016/04/14.
//
//

#ifndef Result_h
#define Result_h

#include "cocos2d.h"

class Result : public cocos2d::Layer
{
protected:
    
    Result();
    virtual ~Result();
    
    bool init() override;
    
public:
    
    static cocos2d::Scene* CreateScene();
    CREATE_FUNC(Result)
    
};

#endif /* Result_h */

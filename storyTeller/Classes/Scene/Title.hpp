//
//  Title.hpp
//  storyTeller
//
//  Created by vantan on 2016/04/23.
//
//

#ifndef Title_hpp
#define Title_hpp

#include <cocos2d.h>

class Title : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* CreateScene();
    
    virtual bool init() override;
    
    CREATE_FUNC(Title)
    
};

#endif /* Title_hpp */

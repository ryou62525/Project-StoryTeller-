//
//  TitleLayer.hpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#ifndef TitleLayer_hpp
#define TitleLayer_hpp

#include <cocos2d.h>
USING_NS_CC;

class TitleLayer : public Layer
{
public:
    
    static Scene* createScene();
    bool init();
    
    CREATE_FUNC(TitleLayer);
};

#endif /* TitleLayer_hpp */

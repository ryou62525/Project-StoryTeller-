//
//  ResultLayer.hpp
//  storyTeller
//
//  Created by vantan on 2016/09/20.
//
//

#ifndef ResultLayer_hpp
#define ResultLayer_hpp

#include <cocos2d.h>
USING_NS_CC;

class ResultLayer : public Layer
{
public:
    
    static Scene* createScene();
    bool init();
    
    CREATE_FUNC(ResultLayer);
};

#endif /* ResultLayer_hpp */

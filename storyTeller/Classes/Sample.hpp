//
//  Sample.hpp
//  StoryTeller
//
//  Created by vantan on 2016/08/07.
//
//

#ifndef Sample_hpp
#define Sample_hpp

// テスト用

#include "cocos2d.h"

class Sample : public cocos2d::Layer {
    
    
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;
    
    void menuCloseCallBack(cocos2d::Ref* pSender);
    
    CREATE_FUNC(Sample);
};

#endif /* Sample_hpp */

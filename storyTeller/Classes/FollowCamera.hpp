//
//  FollowCamera.hpp
//  StoryTeller
//
//  Created by vantan on 2016/08/24.
//
//

#ifndef FollowCamera_hpp
#define FollowCamera_hpp

#include <cocos2d.h>
USING_NS_CC;

enum FollowType
{
    FollowNone,
    FollowVerticalOnly,
    FollowHorizontalOnly,
    FollowDepthOnly
};

class FollowCamera : public cocos2d::Follow
{
private:
    
    FollowType followType;
    Rect marginRect;
    
    FollowCamera();
    ~FollowCamera();
    
public:
    
    static FollowCamera* create(Node *followedNode);
    static FollowCamera* create(Node *followedNode, FollowType type);
    static FollowCamera* create(Node *followedNode, Rect marginRect);
    
    virtual void step(float deltaTime) override;
};

#endif /* FollowCamera_hpp */

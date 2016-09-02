//
//  FollowCamera.cpp
//  StoryTeller
//
//  Created by vantan on 2016/08/24.
//
//

#include "FollowCamera.hpp"

FollowCamera::FollowCamera()
{
    followType = FollowNone;
    marginRect = Rect::ZERO;
}

FollowCamera::~FollowCamera()
{
    CC_SAFE_RELEASE(_followedNode);
}

FollowCamera* FollowCamera::create(Node *followedNode)
{
    FollowCamera *follow = new FollowCamera();
    if(follow && follow->initWithTarget(followedNode, Rect::ZERO))
    {
        follow->autorelease();
        return follow;
    }
    CC_SAFE_DELETE(follow);
    return nullptr;
}

FollowCamera* FollowCamera::create(Node *followedNode, FollowType type)
{
    FollowCamera *follow = new FollowCamera();
    follow->followType = type;
    if(follow && follow->initWithTarget(followedNode, Rect::ZERO))
    {
        follow->autorelease();
        return follow;
    }
    CC_SAFE_DELETE(follow);
    return nullptr;
}

FollowCamera* FollowCamera::create(Node *followedNode, Rect marginRect)
{
    FollowCamera *follow = new FollowCamera();
    follow->marginRect = marginRect;
    if(follow && follow->initWithTarget(followedNode, Rect::ZERO))
    {
        follow->autorelease();
        return follow;
    }
    CC_SAFE_DELETE(follow);
    return nullptr;
}

void FollowCamera::step(float deltaTime)
{
    CC_UNUSED_PARAM(deltaTime);
    
    if(_boundarySet)
    {
        if(_boundaryFullyCovered)return;
        
        Point tempPos = _halfScreenSize - _followedNode->getPosition();
        float x = clampf(tempPos.x, _leftBoundary, _rightBoundary);
        float y = clampf(tempPos.y, _bottomBoundary, _topBoundary);
        
        if(followType == FollowHorizontalOnly)
        {
            y = _target->getPositionY();
        }
        else if(followType == FollowVerticalOnly)
        {
            x = _target->getPositionX();
        }
        _target->setPosition(Point(x,y));
    }
    else
    {
        Point calcPos = _target->convertToWorldSpace(_followedNode->getPosition());
        
        if(marginRect.containsPoint(calcPos))return;
        
        float x = _halfScreenSize.x - _followedNode->getPositionX();
        float y = _halfScreenSize.y - _followedNode->getPositionY();
        
        if(followType == FollowHorizontalOnly)
        {
            y = _target->getPositionY();
        }
        else if(followType == FollowVerticalOnly)
        {
            x = _target->getPositionX();
        }
        _target->setPosition(Point(x,y));
    }
}
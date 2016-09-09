//
//  Character.hpp
//  StoryTeller
//
//  Created by vantan on 2016/08/01.
//
//

#ifndef Character_hpp
#define Character_hpp

#include "cocos2d.h"
#include "SSPlayer/SS5Player.h"

class Character : public cocos2d::Layer {
  
    ss::Player* ssplayer;
    
    enum AnimationState {
        WAIT,
        RUN,
        ATTACK
    } state;
    
    std::string name;
    
public:
    Character();
    virtual ~Character();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;
    
    virtual void update(float delta) override;
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override;
    
    void userDataCallback(ss::Player* player, const ss::UserData* data);
    void playEndCallback(ss::Player* player);
    
    CREATE_FUNC(Character);

private:
    
    void manageSprite(const std::string& dataName_ssbp);
    
    
};

#endif /* Character_hpp */

//
//  BaseScene.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/04.
//
//

#ifndef BaseScene_hpp
#define BaseScene_hpp

#include <Common.hpp>
#include <SceneChanger.hpp>

class BaseScene : public Common
{
protected:
    
    SceneChanger* sceneChanger;
    
public:
    
    BaseScene(SceneChanger* changer);
    
    virtual cocos2d::Scene* CreateScene() override{}
    virtual void Initialize() override{}
    virtual void Finalize() override{}
    virtual void Update() override{}
    virtual void Draw() override{}
    virtual bool init() override{}
    
};

#endif /* BaseScene_hpp */
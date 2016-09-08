//
//  GameManager.hpp
//  storyTeller
//
//  Created by vantan on 2016/09/07.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;

class GameManager : public Layer
{
private:
    
    Size size = Director::getInstance()->getVisibleSize();
    
public:
    
    static Scene* CreateScene();
    bool init();
    void update(float deltaTime);
    CREATE_FUNC(GameManager);
    
};

#endif /* GameManager_hpp */

//
//  HomeMenu.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/05.
//
//


#ifndef HomeMenu_hpp
#define HomeMenu_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HomeMenu : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* CreateScene();
    void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void SetBgImage();
    void SetUiImage();
    virtual bool init();
    
    CREATE_FUNC(HomeMenu)
};

#endif /* HomeMenu_hpp */
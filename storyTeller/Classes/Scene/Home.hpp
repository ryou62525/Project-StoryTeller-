//
//  Home.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef Home_hpp
#define Home_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;

typedef enum{
    HOME,
    QUEST,
    OPTION,
}MenuSerect;

class Home : public cocos2d::Layer
{
private:
    
    MenuSerect menuSerect;
    Sprite* sprite2;
    
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);
    void hoge(int a[]);
    
    void touchEvent(Ref *pSender, ui::Widget::TouchEventType type);
    void SetBgImage();
    void SetUiImage();
    void hoge(int a, int b);
    
    void SetQuestMenu();
    
    CREATE_FUNC(Home)
    
};

#endif /* Home_hpp */

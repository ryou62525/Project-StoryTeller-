//
//  Home.hpp
//  storyTeller
//
//  Created by vantan on 2016/05/02.
//  Created by vantan on 2016/07/19.
//
//

#ifndef Home_hpp
#define Home_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;

class Home : public cocos2d::Layer
{
private:
  
    enum Tag
    {
        t_Quest = 1,
        t_Option,
        t_HomeBg,
        t_MenuDeco,
        t_Icon,
        t_Character,
    };
    
    enum ZOder
    {
        z_MainBg = 1,
        z_Quest,
        z_Option,
        z_MenuDeco,
        z_Icon,
        z_Character,
    };
    
    //背景の作成
    Sprite* background[4] =
    {
        Sprite::create("ImageFile/Menubg.png"),
        Sprite::create("ImageFile/kawabe.png"),
        Sprite::create("ImageFile/Menu.png"),
        Sprite::create("ImageFile/IconBg.png"),
    };
    
    //ボタンの作成
    ui::Button* button[3] =
    {
        ui::Button::create("ImageFile/UIHome.png"),
        ui::Button::create("ImageFile/UIQuest.png"),
        ui::Button::create("ImageFile/UIOption.png"),
    };
    
    Size winSize = Director::getInstance()->getWinSize();
    
    void CreateMenuWindow();
    void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);

    CREATE_FUNC(Home)
};

#endif /* Home_hpp */
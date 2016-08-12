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
//#include "../../cocos2d/external/tinyxml2/tinyxml2.h"       //xmlファイルを読み込む機能の追加
//#include "../../cocos2d/external/json/rapidjson.h"          //jsonファイルを読み込む機能の追加
#include "../../cocos2d/cocos/audio/include/AudioEngine.h"  //サウンドファイルを読み込む機能の追

USING_NS_CC;

class Home : public cocos2d::Layer
{
private:
  
    enum Tag
    {
        t_Quest = 1,
        t_Option,
        t_HomeBg,
        t_Icon,
        t_Character,
    };
    
    enum ZOder
    {
        z_Quest = 1,
        z_Option,
        z_HomeBg,
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
    cocos2d::ui::Button* button[3] =
    {
        cocos2d::ui::Button::create("ImageFile/UIHome.png"),
        cocos2d::ui::Button::create("ImageFile/UIQuest.png"),
        cocos2d::ui::Button::create("ImageFile/UIOption.png"),
    };
    
    cocos2d::ui::Button* stageSelectButton[1] =
    {
        cocos2d::ui::Button::create("ImageFile/IconBg.png"),
    };
    
    Size winSize = Director::getInstance()->getWinSize();
    
    void CreateMenuWindow();
    void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    void SetSelectUnable(cocos2d::ui::Button* button);
    void SetSelectDisable(cocos2d::ui::Button* button);
    
    int menuBgm = experimental::AudioEngine::play2d("Sound/BGM/menu_bgm.wav");
    
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);

    CREATE_FUNC(Home)
};

#endif /* Home_hpp */
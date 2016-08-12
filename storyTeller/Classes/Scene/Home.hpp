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
#include "../../cocos2d/cocos/audio/include/AudioEngine.h"  //サウンドファイルを読み込む機能の追

USING_NS_CC;
using namespace cocos2d::ui;

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
    
    enum
    {
        BG_IMAGE_VALUE = 4,
        UI_IMAGE_VALUE = 3,
        STAGE_UI_IMAGE_VALUE = 1,
    };

    Sprite* background[BG_IMAGE_VALUE];
    Button* button[UI_IMAGE_VALUE];
    Button* stageSelectButton[STAGE_UI_IMAGE_VALUE];
    Size winSize = Director::getInstance()->getWinSize();
    
    void CreateMenuWindow();
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void SetSelectUnable(Button* button);
    void SetSelectDisable(Button* button);
    int menuBgm = experimental::AudioEngine::play2d("Sound/BGM/menu_bgm.wav");
    
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);

    CREATE_FUNC(Home)
};

#endif /* Home_hpp */
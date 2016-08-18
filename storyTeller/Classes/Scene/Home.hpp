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
using namespace experimental;

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
        STAGE_UI_IMAGE_VALUE = 4,
        MENU_UI_VALUE = 9,
    };
    
    enum class UI_IMAGE
    {
        HOME = 0,
        QUEST,
        DICTIONARY,
        OPTION,
        
        MAX
    };
    
    enum class OPTION_LABEL
    {
        BGM = 0,
        SE,
        M_SPEED,
        
        MAX = 9
    };
    
    enum class STAGE_SELECT
    {
        ALICE = 0,
        
        MAX = 4
    };
    
    ListView* menuList = ListView::create();
    PageView* pageView = PageView::create();
    Sprite* background[BG_IMAGE_VALUE];
    Button* button[(int)UI_IMAGE::MAX];
    Button* stageSelectButton[(int)STAGE_SELECT::MAX];
    Size winSize = Director::getInstance()->getWinSize();
    
    void CreateMenuWindow();
    void CreateOptionWindow();
    void CreateQuestWindow();
    
    
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void ChangePageMoveIn(PageView* _pageView);
    void ChangePageMoveOut(PageView* _pageView);
    void SetSelectUnable(Button* button);
    void SetSelectDisable(Button* button);
    void SetBgm();
    
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);

    CREATE_FUNC(Home)
};

#endif /* Home_hpp */
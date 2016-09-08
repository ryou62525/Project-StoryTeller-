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
#include <string.h>

#include "../../cocos2d/cocos/audio/include/AudioEngine.h"  //サウンドファイルを読み込む機能の追
#include "ResDataBase.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace experimental;

class Home : public cocos2d::Layer
{
private:
    
    float percent = 50;
    int menuBgm;
    
    Size winSize;
    ListView* optionMenuList;
    UserDefault* user;
    
    PageView* pageView[(int)PAGE::MAX];
    Sprite* background[BG_IMAGE_VALUE];
    Button* button[(int)UI_IMAGE::MAX];
    
    Button* storySelectButton[(int)STORY_SELECT::MAX];
    Button* stage1SelectButton[3];
    
    void CreateMenuWindow();
    void CreateOptionWindow();
    void CreatePageViewList(const std::string _filePath, PageView* _pageView, Button* _button[], const int ButtonNum, Vec2 initPos = Vec2(0, 380));
    
    void StorySelectedProcessingImplementation();
    void StageSelectedProcessingImplementation();
    
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    void ChangePageMoveIn(PageView* _pageView);
    void ChangePageMoveOut(PageView* _pageView);
    void SetSelectUnable(Button* button);
    void SetSelectDisable(Button* button);
    void SetBgm(const std::string _filePath, bool _enable);
    
public:
    
    static Scene* CreateScene();
    virtual bool init();
    void update(float deltaTime);

    CREATE_FUNC(Home)
};

#endif /* Home_hpp */
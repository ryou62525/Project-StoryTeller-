//
//  Home.cpp
//  storyTeller
//
//  Created by vantan on 2016/05/02.
//  Created by vantan on 2016/07/19.
//
//
#include "Home.hpp"
#include "Game.hpp"
#include "../Utility/GameUtilis.hpp"
#include <fstream>

#define ElemValue(arr) (sizeof(arr)/sizeof(arr)[0])
USING_NS_CC;

using namespace cocos2d::ui;

Scene* Home::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Home::create();
    scene->addChild(layer);
    return  scene;
}

bool Home::init()
{
    if(!Layer::init()){ return false; }

    user = UserDefault::getInstance();
    winSize = Director::getInstance()->getWinSize();
    optionMenuList = ListView::create();
    
    for (int i = 0; i<(int)PAGE::MAX; i++) {
        pageView[i] =  PageView::create();
    }
    
    CreatePageViewList("DataFile/StorySelectImage.txt", pageView[(int)PAGE::STORY_SELECT], storySelectButton, ElemValue(storySelectButton));
    CreatePageViewList("DataFile/StageSelectImage.txt", pageView[(int)PAGE::STAGE_SELECT], stage1SelectButton, ElemValue(stage1SelectButton), Vec2(winSize.width,380));
    
    SetBgm("Sound/BGM/menu_bgm.wav", true);
    
    CreateMenuWindow();
    
    CreateOptionWindow();
    
    StorySelectedProcessingImplementation();
    StageSelectedProcessingImplementation();
    
    return true;
}

void Home::update(float deltaTime)
{
   
}

//メニューのウィンドウの設定及びボタンの設置、タッチイベントの生成など
void Home::CreateMenuWindow()
{
    //背景設定---------------------------------------------------------------------------------------------------
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImage.txt");
    std::ifstream bgInFile(filePath);
    assert(bgInFile);
    
    std::string _filePath;
    Vec2 pos, size;
    int dOder;

    for(int i = 0; i < BG_IMAGE_VALUE; i++)
    {
        bgInFile >> _filePath >> pos.x >> pos.y >> size.x >> size.y >> dOder;
        background[i] = Sprite::create(_filePath);
        background[i]->setPosition(Vec2(pos.x, pos.y));
        background[i]->setScale(size.x, size.y);
        this->addChild(background[i],dOder);
    }
    
    //ボタン設定-------------------------------------------------------------------------------------------------
    filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeUiImage.txt");
    std::ifstream uiInFile(filePath);
    assert(uiInFile);

    for(int i = 0; i < (int)UI_IMAGE::MAX; i++)
    {
        uiInFile >> _filePath >> pos.x >> pos.y
                              >> size.x >> size.y
                              >> dOder;
        
        button[i] = Button::create(_filePath,"",_filePath);
        button[i]->setPosition(Vec2(pos.x, pos.y));
        button[i]->setScale(size.x, size.y);
        this->addChild(button[i],dOder);
    }
    
    //ボタンのタッチイベント---------------------------------------------------------------------------------------
    button[(int)UI_IMAGE::HOME]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             this->reorderChild(optionMenuList,1);
                                             
                                             for (int i = 0; i < ElemValue(pageView); i++)
                                             {
                                                 this->reorderChild(pageView[i],1);
                                                 pageView[i]->setEnabled(false);
                                             }
                                             
                                             SetSelectDisable(storySelectButton[0]);
                                             
                                         }
                                     });
    
    button[(int)UI_IMAGE::QUEST]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 3);
                                             this->reorderChild(optionMenuList,1);
                                             
                                             for (int i = 0; i < ElemValue(pageView); i++)
                                             {
                                                 this->reorderChild(pageView[i],4);
                                                 pageView[i]->setEnabled(true);
                                             }
                                             
                                             SetSelectUnable(storySelectButton[0]);
                                             
                                         }
                                     });
    
    button[(int)UI_IMAGE::DICTIONARY]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             this->reorderChild(optionMenuList,1);
                                             
                                             for (int i = 0; i < ElemValue(pageView); i++)
                                             {
                                                 this->reorderChild(pageView[i],1);
                                                 pageView[i]->setEnabled(false);
                                             }
                                             
                                             SetSelectDisable(storySelectButton[0]);
                                             
                                         }
                                     });
   
    button[(int)UI_IMAGE::OPTION]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::ENDED)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             this->reorderChild(optionMenuList,4);
                                             
                                             for (int i = 0; i < ElemValue(pageView); i++)
                                             {
                                                 this->reorderChild(pageView[i],1);
                                                 pageView[i]->setEnabled(false);
                                             }
                                             
                                             SetSelectDisable(storySelectButton[0]);
                                             optionMenuList->setEnabled(true);
                                             
                                             
                                             for (int i = 0; i < (int)UI_IMAGE::MAX; i++)
                                             {
                                                 if(i != (int)UI_IMAGE::OPTION)
                                                 button[i]->setEnabled(false);
                                             }
                                             
                                             this->runAction(Sequence::create(DelayTime::create(0.05),CallFunc::create([this](){
                                                 button[3]->setEnabled(false);
                                             }),NULL));
                                         }
                                     });
}

//オプションウィンドウの生成、及びタッチイベントの生成など
void Home::CreateOptionWindow()
{
    optionMenuList->setContentSize(Size(winSize.width,winSize.height));
    optionMenuList->Node::setPosition((winSize - optionMenuList->getContentSize())/2);
    addChild(optionMenuList,1);
    
    Slider* slider[3];
    
    for (int i = 0; i < 3; i++)
    {
        slider[i] = Slider::create();
        slider[i]->loadBarTexture("ImageFile/sliderTrack.png");
        slider[i]->loadSlidBallTextures("ImageFile/sliderThumb.png",
                                        "ImageFile/sliderThumb.png","");
        slider[i]->loadProgressBarTexture("ImageFile/sliderProgress.png");
        slider[i]->Node::setScale(1);
    }
    
    slider[0]->setPosition(Vec2(1225, -350));
    slider[1]->setPosition(Vec2(1225, -500));
    slider[2]->setPosition(Vec2(1225, -650));
    
    slider[0]->addEventListener([this](Ref* pSender, Slider::EventType type)
    {
        if(type == Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            //値が変化した時の処理
            auto slider = dynamic_cast<Slider*>(pSender);
            percent = slider->getPercent();
            AudioEngine::setVolume(menuBgm, percent/100);
            
            CCLOG("Percent %f", percent/100);
        }
    });
    
    auto closeButton = Button::create("ImageFile/button1.png","ImageFile/button1selected.png");
    closeButton->setPosition(Vec2(winSize.width/2, -780));
    closeButton->setScale(1.8,1.8);
    closeButton->setTitleText("閉じる");
    closeButton->setTitleFontSize(16);
    closeButton->setTitleColor(Color3B::WHITE);
    closeButton->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                       {
                                           if(type == Widget::TouchEventType::ENDED)
                                           {
                                               this->runAction(Sequence::create(DelayTime::create(0.1),CallFunc::create([this](){
                                                   
                                                   for(int i = 0; i < (int)UI_IMAGE::MAX; i++)
                                                       button[i]->setEnabled(true);
                                                   
                                                   user->setFloatForKey("bgmVolume", percent/100);
                                                   
                                                   this->reorderChild(optionMenuList,1);
                                                   optionMenuList->setEnabled(false);
                                                   
                                               }),NULL));
                                           }
                                       });
    
    auto layout = Layout::create();
    layout->setPosition(optionMenuList->getContentSize()/2);
    auto imageView = ImageView::create("ImageFile/option/option_window.png");         //メニュー用の画像きたら貼り替え、スケールも変更
    imageView->setPosition(Vec2(winSize.width/2,-winSize.height/2));
    imageView->setScale(1.5, 1.5);
    layout->addChild(imageView);
    Vec2 pos = imageView->getPosition();
    
    for (int i = 0; i<3; i++) {
        layout->addChild(slider[i]);
    }
    
//    Label* label[9];
//    
//    for (int i = 0;i < (int)OPTION_LABEL::MAX; i++) {
//        label[i] = Label::create();
//    }
//    
//    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeOptionUI.txt");
//    std::ifstream menuInFile(filePath);
//    assert(menuInFile);
//    
//    std::string text;
//    Vec2 _pos;
//    for(int i = 0; i < MENU_UI_VALUE; i++)
//    {
//        menuInFile >> _pos.x >> _pos.y >> text;
//        
//        label[i]->setPosition(Vec2(_pos.x, -_pos.y));
//        label[i]->setString(text);
//        label[i]->setScale(3.5);
//        layout->addChild(label[i]);
//    }

    layout->addChild(closeButton);
    optionMenuList->addChild(layout);
    optionMenuList->setEnabled(false);
}

//ストーリー選択メニュー及びタッチイベントの生成
void Home::StorySelectedProcessingImplementation()
{
    storySelectButton[0]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                                {
                                                    if(type == Widget::TouchEventType::ENDED)
                                                    {
                                                        ChangePageMoveOut(pageView[(int)PAGE::STORY_SELECT]);
                                                        
                                                        this->runAction(Sequence::create(DelayTime::create(1),CallFunc::create([this](){
                                                        
                                                            ChangePageMoveIn(pageView[(int)PAGE::STAGE_SELECT]);
                                                            
                                                        }),NULL));
                                                    }
                                                });
}

//ゲームシーンへ移動
void Home::StageSelectedProcessingImplementation()
{
    stage1SelectButton[0]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                                 {
                                                     TransitionFade* trasition = TransitionFade::create(1.5, Game::CreateScene());
                                                     Director::getInstance()->replaceScene(trasition);
                                                 });
}

void Home::CreatePageViewList(const std::string _filePath, PageView* _pageView, Button* _button[], const int ButtonNum, Vec2 initPos)
{
    _pageView->setContentSize(Size(winSize.width,320));
    _pageView->setPosition(initPos);
    this->addChild(_pageView,1);
    
    auto filePath = FileUtils::getInstance()->fullPathForFilename(_filePath);
    std::ifstream stageSelectInFile(filePath);
    assert(stageSelectInFile);
    
    Vec2 pos, size;
    std::string _imagePath;
    std::string uiText;
    float fontSize;

    for(int i = 0; i < ButtonNum; i++)
    {
        stageSelectInFile >> _imagePath >> pos.x >> pos.y
                                        >> size.x >> size.y
                                        >> uiText >> fontSize;
        
        auto layout = Layout::create();
        layout->setContentSize(_pageView->getContentSize());
        
        _button[i] = Button::create(_imagePath);
        _button[i]->setPosition(layout->getContentSize()/2);
        _button[i]->setScale(size.x, size.y);
        _button[i]->setTitleText(uiText);
        _button[i]->setTitleFontSize(fontSize);
        _button[i]->setTitleColor(Color3B::WHITE);
        _button[i]->setEnabled(true);
        layout->addChild(_button[i]);
        _pageView->addChild(layout,i);
    }
    _pageView->setEnabled(false);
}

void Home::ChangePageMoveIn(PageView* _pageView)
{
    auto action = MoveTo::create(1, Vec2(0, 380));
    auto easeAction = EaseOut::create(action, 5);
    _pageView->runAction(easeAction);
}

void Home::ChangePageMoveOut(PageView* _pageView)
{
    auto action = MoveTo::create(1, Vec2(winSize.width, 380));
    auto easeAction = EaseOut::create(action, 5);
    _pageView->runAction(easeAction);
}

void Home::SetSelectUnable(Button* button)
{
    button->setEnabled(true);
}

void Home::SetSelectDisable(Button* button)
{
    button->setEnabled(false);
}

//--------BGMの設定--------//
//ファイルのパス   std::string
//ループ設定       bool
void Home::SetBgm(const std::string _filePath, bool _enable)
{
    menuBgm = experimental::AudioEngine::play2d(_filePath);
    AudioEngine::setLoop(menuBgm, _enable);
}
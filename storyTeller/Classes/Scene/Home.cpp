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
#include <fstream>

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

    CreateMenuWindow();
    CreateOptionWindow();
    CreateQuestWindow();
    SetBgm();
    
    return true;
}

void Home::update(float deltaTime)
{
    
}

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
                                             this->reorderChild(menuList,1);
                                             this->reorderChild(pageView,1);
                                             SetSelectDisable(stageSelectButton[0]);
                                             menuList->setEnabled(false);
                                             pageView->setEnabled(false);
                                         }
                                     });
    
    button[(int)UI_IMAGE::QUEST]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[1], 3);
                                             this->reorderChild(menuList,1);
                                             this->reorderChild(pageView,4);
                                             SetSelectUnable(stageSelectButton[0]);
                                             pageView->setEnabled(true);
                                             menuList->setEnabled(false);
                                         }
                                     });
    
    button[(int)UI_IMAGE::DICTIONARY]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::BEGAN)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             this->reorderChild(menuList,1);
                                             this->reorderChild(pageView,1);
                                             SetSelectDisable(stageSelectButton[0]);
                                             menuList->setEnabled(false);
                                             pageView->setEnabled(false);
                                         }
                                     });
   
    button[(int)UI_IMAGE::OPTION]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                     {
                                         if(type == Widget::TouchEventType::ENDED)
                                         {
                                             this->reorderChild(background[0], 3);
                                             this->reorderChild(background[2], 3);
                                             this->reorderChild(menuList,4);
                                             this->reorderChild(pageView,1);
                                             SetSelectDisable(stageSelectButton[0]);
                                             menuList->setEnabled(true);
                                             pageView->setEnabled(false);
                                             
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
    menuList->setContentSize(Size(winSize.width,winSize.height));
    menuList->Node::setPosition((winSize - menuList->getContentSize())/2);
    addChild(menuList,1);
    
    Slider* slider[3] = {   Slider::create(),
                            Slider::create(),
                            Slider::create()};
    
    for (int i =0; i<3; i++) {
        
        slider[i]->loadBarTexture("ImageFile/sliderTrack.png");
        slider[i]->loadSlidBallTextures("ImageFile/sliderThumb.png",
                                        "ImageFile/sliderThumb.png","");
        slider[i]->loadProgressBarTexture("ImageFile/sliderProgress.png");
        slider[i]->Node::setScale(2, 2);
    }
    
    slider[0]->setPosition(Vec2(1225, -350));
    slider[1]->setPosition(Vec2(1225, -500));
    slider[2]->setPosition(Vec2(1225, -650));
    
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
                                                   this->reorderChild(menuList,1);
                                                   menuList->setEnabled(false);
                                                   
                                               }),NULL));
                                           }
                                       });
    
    auto layout = Layout::create();
    layout->setPosition(menuList->getContentSize()/2);
    auto imageView = ImageView::create("ImageFile/kuro.png");         //メニュー用の画像きたら貼り替え、スケールも変更
    imageView->setPosition(Vec2(winSize.width/2,-winSize.height/2));
    imageView->setScale(0.6, 0.55);
    layout->addChild(imageView);
    Vec2 pos = imageView->getPosition();
    
    for (int i = 0; i<3; i++) {
        layout->addChild(slider[i]);
    }
    
    Label* label[9];
    
    for (int i = 0;i < (int)OPTION_LABEL::MAX; i++) {
        label[i] = Label::create();
    }
    
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeOptionUI.txt");
    std::ifstream menuInFile(filePath);
    assert(menuInFile);
    
    std::string text;
    Vec2 _pos;
    for(int i = 0; i < MENU_UI_VALUE; i++)
    {
        menuInFile >> _pos.x >> _pos.y >> text;
        
        label[i]->setPosition(Vec2(_pos.x, -_pos.y));
        label[i]->setString(text);
        label[i]->setScale(3.5);
        layout->addChild(label[i]);
    }

    layout->addChild(closeButton);
    menuList->addChild(layout);
    menuList->setEnabled(false);
}

//クエストメニューウィンドウ及びタッチイベントの生成
void Home::CreateQuestWindow()
{
    pageView->setContentSize(Size(winSize.width,320));
    pageView->setPosition((winSize-pageView->getContentSize())/2);
    this->addChild(pageView,1);
    
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeStageSelectImage.txt");
    std::ifstream stageSelectInFile(filePath);
    assert(stageSelectInFile);
    
    Vec2 pos;
    Vec2 size;
    
    std::string _filePath;
    std::string uiText;
    int dOder;
    float fontSize;
    
    for(int i = 0; i < STAGE_UI_IMAGE_VALUE; i++)
    {
        stageSelectInFile >> _filePath >> pos.x >> pos.y
                                       >> size.x >> size.y
                                       >> uiText >> fontSize >> dOder;
        
        auto layout = Layout::create();
        layout->setContentSize(pageView->getContentSize());
        
        stageSelectButton[i] = Button::create(_filePath);
        stageSelectButton[i]->setPosition(layout->getContentSize()/2);
        stageSelectButton[i]->setScale(size.x, size.y);
        stageSelectButton[i]->setTitleText(uiText);
        stageSelectButton[i]->setTitleFontSize(fontSize);
        stageSelectButton[i]->setTitleColor(Color3B::WHITE);
        stageSelectButton[i]->setEnabled(true);
        layout->addChild(stageSelectButton[i],dOder);
        pageView->addChild(layout,i);
    }
    
    pageView->setEnabled(false);
    
    stageSelectButton[0]->addTouchEventListener([this](Ref *pSender, Widget::TouchEventType type)
                                                {
                                                    if(type == Widget::TouchEventType::ENDED)
                                                    {
                                                        ChangePageMoveOut(pageView);
                                                        
                                                        this->runAction(Sequence::create(DelayTime::create(3),CallFunc::create([this](){
                                                            
                                                        }),NULL));
                                                    }
                                                });
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

void Home::SetBgm()
{
    int menuBgm = experimental::AudioEngine::play2d("Sound/BGM/menu_bgm.wav");
    AudioEngine::setLoop(menuBgm, true);
}
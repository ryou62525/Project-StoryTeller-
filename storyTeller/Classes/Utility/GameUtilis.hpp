//
//  GameUtilis.hpp
//  storyTeller
//
//  Created by vantan on 2016/08/29.
//
//

#ifndef GameUtilis_hpp
#define GameUtilis_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
#include <fstream>
#include "ResDataBase.h"
#include "../../cocos2d/cocos/audio/include/AudioEngine.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace experimental;


//UIの生成
//_layer  貼り付ける対象のレイヤー
//_path   読み込む画像のパス
//_button ボタン設定をする対象のボタンオブジェクト
//_pos    設定する位置（初期位置は0,0）
//_size   設定するスケール（初期スケール1,1）
static void SetUI(Layer* _layer, Button* _button, Vec2 _pos = Vec2::ZERO, Vec2 _size = Vec2::ONE)
{
    _button->setPosition(_pos);
    _button->setScale(_size.x, _size.y);
    _layer->addChild(_button);
}

static void CreateOption(Layer* _layer, ListView* _menuList, Slider* slider[])
{
    Size winSize = Director::getInstance()->getVisibleSize();
    
    _menuList->setContentSize(Size(winSize.width,winSize.height));
    _menuList->Node::setPosition((winSize - _menuList->getContentSize())/2);
    _layer->addChild(_menuList,1);
    
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
    
    
    auto closeButton = Button::create("ImageFile/button1.png","ImageFile/button1selected.png");
    closeButton->setPosition(Vec2(winSize.width/2, -780));
    closeButton->setScale(1.8,1.8);
    closeButton->setTitleText("閉じる");
    closeButton->setTitleFontSize(16);
    closeButton->setTitleColor(Color3B::WHITE);
    
    auto layout = Layout::create();
    layout->setPosition(_menuList->getContentSize()/2);
    auto imageView = ImageView::create("ImageFile/option_window.png");
    imageView->setPosition(Vec2(winSize.width/2,-winSize.height/2));
    imageView->setScale(0.6, 0.55);
    layout->addChild(imageView);
    
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
    _menuList->addChild(layout);
    _menuList->setEnabled(false);
    
    
}


#endif /* GameUtilis_hpp */
//
//  ProvisionalScene.cpp
//  storyTeller
//
//  Created by vantan on 2016/08/31.
//
//

#include "ProvisionalScene.hpp"
#include "../Utility/GameUtilis.hpp"
#include "../Utility/GameOption.hpp"

Scene* ProvisionalScene::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = ProvisionalScene::create();
    scene->addChild(layer);
    return scene;
}

bool ProvisionalScene::init()
{
    if(!Layer::init()){return false;}
    
    auto sprite = Sprite::create("ImageFile/Menubg.png");
    sprite->setPosition(winSize/2);
    this->addChild(sprite,3);
    
    //メニューリスト生成----------------------------------------------------->
    menuList->setContentSize(Size(winSize.width,winSize.height));
    menuList->Node::setPosition((winSize - menuList->getContentSize())/2);
    addChild(menuList,1);
    
    //スライダーバー生成----------------------------------------------------->
    for (int i = 0; i < 3; i++)
    {
        slider[i] = Slider::create();
        slider[i]->loadBarTexture("ImageFile/sliderTrack.png");
        slider[i]->loadSlidBallTextures("ImageFile/sliderThumb.png",
                                        "ImageFile/sliderThumb.png","");
        slider[i]->loadProgressBarTexture("ImageFile/sliderProgress.png");
        slider[i]->Node::setScale(2);
    }
    slider[0]->setPosition(Vec2(1225, -350));
    slider[1]->setPosition(Vec2(1225, -500));
    slider[2]->setPosition(Vec2(1225, -650));
    
    //Closeボタン生成--------------------------------------------------->
    auto closeButton = Button::create("ImageFile/button1.png",
                                      "ImageFile/button1selected.png");
    closeButton->setPosition(Vec2(winSize.width/2, -780));
    closeButton->setScale(1.8,1.8);
    closeButton->setTitleText("閉じる");
    closeButton->setTitleFontSize(16);
    closeButton->setTitleColor(Color3B::WHITE);
    
    //レイアウト生成------------------------------------>
    auto layout = Layout::create();
    layout->setPosition(menuList->getContentSize()/2);
    
    //レイアウトの背景画像生成------------------------------------------->
    auto imageView = ImageView::create("ImageFile/option/option_window.png");
    imageView->setPosition(Vec2(winSize.width/2,-winSize.height/2));
    imageView->setScale(1.5, 1.5);
    layout->addChild(imageView);
    
    for (int i = 0; i<3; i++) {
        layout->addChild(slider[i]);
    }
    
    layout->addChild(closeButton);
    menuList->addChild(layout);
    menuList->setEnabled(false);
    
    optionButton->setPosition(Vec2(200,100));
    optionButton->setScale(0.1);
    addChild(optionButton,4);
    
    optionButton->addTouchEventListener([&,this](Ref *pSender, Widget::TouchEventType type){
    
        this->reorderChild(menuList, 3);
        menuList->setEnabled(true);

    });
    
    return true;
}

void ProvisionalScene::update(float deltaTime)
{
    
}
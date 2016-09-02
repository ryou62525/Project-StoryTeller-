//
//  GameOption.hpp
//  storyTeller
//
//  Created by vantan on 2016/08/31.
//
//

#ifndef GameOption_hpp
#define GameOption_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;
using namespace cocos2d::ui;

class GameOption : public Layer
{
private:
    
    Layer* layer;
    Slider* slider[3];
    Size winSize = Size(1920, 1080);
    
public:
    
    ListView* menuList = ListView::create();
    GameOption(Layer* _layer);
    void CreateOption();
    void SetEnable(bool _enable){menuList->setEnabled(_enable);}
    void SetDisable(){menuList->setEnabled(false);};
    
};

#endif /* GameOption_hpp */

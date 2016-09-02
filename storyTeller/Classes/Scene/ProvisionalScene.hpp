//
//  ProvisionalScene.hpp
//  storyTeller
//
//  Created by vantan on 2016/08/31.
//
//

#ifndef ProvisionalScene_hpp
#define ProvisionalScene_hpp

#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;
using namespace cocos2d::ui;

class ProvisionalScene : public Layer
{
private:
    
    Size winSize = Director::getInstance()->getVisibleSize();
    Button* optionButton = Button::create("ImageFile/UIHome.png");
    ListView* menuList = ListView::create();
    Slider* slider[3];
    
public:
    
    static Scene* CreateScene();
    bool init();
    void update(float deltaTime);
    CREATE_FUNC(ProvisionalScene);
    
};

#endif /* ProvisionalScene_hpp */

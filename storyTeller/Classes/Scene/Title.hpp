//
//  Title.hpp
//  storyTeller
//
//  Created by vantan on 2016/04/23.
//
//

#ifndef Title_hpp
#define Title_hpp

#include <cocos2d.h>

class Title : public cocos2d::Layer
{
    std::string imagePath = "DataFile/TitleImagePath.txt";
    int imageValue;
    cocos2d::Sprite* bgSprite;
    
public:
    
    int sceneNumber = 0;
    static cocos2d::Scene* CreateScene();
    bool init();
    void SetImageInfo();
    CREATE_FUNC(Title)
    
};

#endif /* Title_hpp */.

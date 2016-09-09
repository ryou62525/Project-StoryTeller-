//
//  Result.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef Result_hpp
#define Result_hpp

#include <cocos2d.h>
#include <fstream>
#include <codecvt>
#include <string>

USING_NS_CC;

class Result : public cocos2d::Layer
{
public:
    
    Label *label1;
    
    float labelSize;
    
    Vec2 labelPos;
    
    std::string str;
    
    size_t str_size;
    
    int string_num;
    
    enum ResultState{
    
    GOOD,
    BAD
        
    };
    
    static int result_State;
    
    static cocos2d::Scene* CreateScene();
    bool init();
    void SetImageInfo();
    void ResultControll();
    void update(float deltaTime);
    void setup();
    size_t strlen(const std::string& s);
    char32_t getchar(const std::string& s, const size_t pos);
    std::string substr(const std::string& s,const size_t pos =0, const size_t len = std::string::npos);
    CREATE_FUNC(Result)
};

#endif /* Result_hpp */

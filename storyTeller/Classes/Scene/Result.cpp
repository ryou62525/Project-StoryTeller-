//
// Result.cpp
// storyTeller
//
// Created by vantan on 2016/07/19.
//
//

#include "Result.hpp"
#include <fstream>
#include <codecvt>
#include <string>

cocos2d::Scene* Result::CreateScene()
{
    result_State = GOOD;
    
    cocos2d::Scene* scene = cocos2d::Scene::create();
    Layer* layer = Result::create();
    scene->addChild(layer);
    return  scene;
}

bool Result::init()
{
    if(!Layer::init()){return  false;}
    
    this->scheduleUpdate();
    
    labelPos =Vec2(700,500);
    
    labelSize =50.0f;
    
    string_num = 0;
   
    str ="地球と宇宙に住む全ての皆さんこんにちわ。私は地球連邦政府首相リカルドマーセナスです";
    label1 = Label::createWithTTF("", "fonts/rounded-mplus-1c-heavy.ttf", 50);
    label1->setTextColor(Color4B::WHITE);
    label1->setPosition(labelPos);
    label1->setDimensions(1000, 500);
    label1->setVisible(true);

    
    this->addChild(label1);
    
    return true;
}


void Result::setup(){
    
    
    
}



void Result::update(float deltaTime)
{
    
    if(string_num<str.size()*3){
    
        string_num++;
        
        if(string_num % 3 == 0 ){
            
        }
    
    }
    
    label1->setPosition(labelPos);
    
    label1->setString(str.substr(0,string_num));

}

void Result::ResultControll(){
    
    

    if(result_State==GOOD){
    //グッドエンド
        
       
    
    
    }
    
    if(result_State == BAD){
    //バッドエンド
    
    
    }



}

void Result::SetImageInfo()
{
    
   auto application = cocos2d::Application::getInstance();
   auto platform = application->getTargetPlatform();
   
   
   if(platform== cocos2d::Application::Platform::OS_IPHONE){
       
       auto filePath_iphone = cocos2d::FileUtils::getInstance()->fullPathForFilename("DataFile/ResultImagePath_iphone.txt");
       std::ifstream inFile_iphone(filePath_iphone);
       assert(inFile_iphone);
       
       size_t imageValue_iphone;
       std::string _filePath_iphone;
       cocos2d::Vec2 pos, size;
       
       inFile_iphone >> imageValue_iphone;
       cocos2d::Sprite* bgSprite[imageValue_iphone];
       
       for(int i = 0; i < imageValue_iphone; i++)
       {
           //画像のパス、横の座標、縦の座標、
           //横のサイズの比率、縦のサイズの比率の順にデータを読み込む
           inFile_iphone >> _filePath_iphone >> pos.x >> pos.y >> size.x >> size.y;
           
           //変数に読み込んだデータをもとに情報をセットしていく
           bgSprite[i] = cocos2d::Sprite::create(_filePath_iphone);
           bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
           bgSprite[i]->setScale(size.x, size.y);
           
           this->addChild(bgSprite[i]);
       }
       
       CCLOG("%f", bgSprite[0]->getPosition().x);
       
   }
   
   if(platform == cocos2d::Application::Platform::OS_IPAD){
       
      auto filePath_ipad =FileUtils::getInstance()->fullPathForFilename("DataFile/ResultImagePath_ipad.txt");
       
       std::ifstream inFile_ipad(filePath_ipad);
       assert(inFile_ipad);
       
       size_t imageValue_ipad;
       std::string _filePath_ipad;
       cocos2d::Vec2 pos, size;
       
       inFile_ipad >> imageValue_ipad;
       cocos2d::Sprite* bgSprite[imageValue_ipad];
       
       for(int i = 0; i < imageValue_ipad; i++)
       {
           //画像のパス、横の座標、縦の座標、
           //横のサイズの比率、縦のサイズの比率の順にデータを読み込む
           inFile_ipad >> _filePath_ipad >> pos.x >> pos.y >> size.x >> size.y;
           
           //変数に読み込んだデータをもとに情報をセットしていく
           bgSprite[i] = cocos2d::Sprite::create(_filePath_ipad);
           bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
           bgSprite[i]->setScale(size.x, size.y);
           
           this->addChild(bgSprite[i]);
       }
       
       CCLOG("%f", bgSprite[0]->getPosition().x);
       
   }
   
    
}


size_t Result::strlen(const std::string& s){

    std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv;
    return conv.from_bytes(s).size();

}

std::string Result::substr(const std::string& s,const size_t pos, const size_t len){

    std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t> conv;
    
    auto u32string = conv.from_bytes(s);
    auto sub = u32string.substr(pos,len);
    
    return conv.to_bytes(sub);

}
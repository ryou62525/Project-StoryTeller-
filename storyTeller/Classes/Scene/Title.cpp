//
//  Title.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/22.
//
//

#include "Title.hpp"
#include "Home.hpp"
#include "Result.hpp"
#include <fstream>

Scene* Title::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Title::create();
    scene->addChild(layer);
    return  scene;
}

bool Title::init()
{
    if(!Layer::init()){return  false;}
    
    SetImageInfo();
 
    //イベントリスナーの生成
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        auto nextScene = Home::CreateScene();
        Scene* transision;
        
        transision = TransitionFade::create(1.0f, nextScene);
        Director::getInstance()->replaceScene(transision);
        return true;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Title::update(float deltaTime)
{
    
}

//画像の情報をテキストファイルから呼び出す
void Title::SetImageInfo()
{
    
    auto application = Application::getInstance();
    auto platform = application->getTargetPlatform();
    
    
    if(platform== Application::Platform::OS_IPHONE){
        
        auto filePath_iphone = FileUtils::getInstance()->fullPathForFilename("DataFile/TitleImage_iphone.txt");
        std::ifstream inFile_iphone(filePath_iphone);
        assert(inFile_iphone);
        
        size_t imageValue_iphone;
        std::string _filePath_iphone;
        Vec2 pos, size;
        
        inFile_iphone >> imageValue_iphone;
        Sprite* bgSprite[imageValue_iphone];
        
        for(int i = 0; i < imageValue_iphone; i++)
        {
            //画像のパス、横の座標、縦の座標、
            //横のサイズの比率、縦のサイズの比率の順にデータを読み込む
            inFile_iphone >> _filePath_iphone >> pos.x >> pos.y >> size.x >> size.y;
            
            //変数に読み込んだデータをもとに情報をセットしていく
            bgSprite[i] = Sprite::create(_filePath_iphone);
            bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
            bgSprite[i]->setScale(size.x, size.y);
            
            this->addChild(bgSprite[i]);
        }
        
        CCLOG("%f", bgSprite[0]->getPosition().x);
        
        
    }
    
    if(platform==Application::Platform::OS_IPAD){
        
        auto filePath_ipad = FileUtils::getInstance()->fullPathForFilename("DataFile/TitleImage_ipad.txt");
        std::ifstream inFile_ipad(filePath_ipad);
        assert(inFile_ipad);
        
        size_t imageValue_ipad;
        std::string _filePath_ipad;
        Vec2 pos, size;
        
        inFile_ipad >> imageValue_ipad;
        Sprite* bgSprite[imageValue_ipad];
        
        for(int i = 0; i < imageValue_ipad; i++)
        {
            //画像のパス、横の座標、縦の座標、
            //横のサイズの比率、縦のサイズの比率の順にデータを読み込む
            inFile_ipad >> _filePath_ipad >> pos.x >> pos.y >> size.x >> size.y;
            
            //変数に読み込んだデータをもとに情報をセットしていく
            bgSprite[i] = Sprite::create(_filePath_ipad);
            bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
            bgSprite[i]->setScale(size.x, size.y);
            
            this->addChild(bgSprite[i]);
        }
        
        CCLOG("%f", bgSprite[0]->getPosition().x);
        
    
    
    
}
 
    
}
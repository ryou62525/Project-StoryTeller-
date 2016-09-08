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
    
    {
        SetImageInfo();
        sprite = Sprite::create("ImageFile/TapEventImage.png");
        sprite->setPosition(Vec2(960,200));
        sprite->setScale(0.4,0.4);
        this->addChild(sprite);
        this->scheduleUpdate();
        
        SetBgm();
        SetBlink(2);
    }
    
    //Scene* nextScene = Home::CreateScene();
        
    //画面タッチ時イベント処理
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* touch, Event* event)
    {
        this->getEventDispatcher()->removeAllEventListeners();
        SetBlink(0.1);
        changeScene = true;
        se = AudioEngine::play2d("Sound/SE/TouchToStart.wav");
        delay = DelayTime::create(3.5);
        
        auto startGame = CallFunc::create([]
        {
            TransitionFade* trasition = TransitionFade::create(1.5, Home::CreateScene());
            Director::getInstance()->replaceScene(trasition);
        });
       
        this->runAction(Sequence::create(delay, startGame, NULL));
        return true;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
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
        
<<<<<<< HEAD
        
=======
        //変数に読み込んだデータをもとに情報をセットしていく
        bgSprite[i] = Sprite::create(_filePath);
        bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
        bgSprite[i]->setScale(size.x, size.y);
        this->addChild(bgSprite[i]);
>>>>>>> ryou62525/master
    }
}

void Title::SetBlink(float blinkSpeed)
{
    auto blink = Sequence::create(FadeTo::create(blinkSpeed, 60),FadeTo::create(blinkSpeed, 255), NULL);
    sprite->runAction(RepeatForever::create(blink));
}

//BGMの設定
void Title::SetBgm()
{
    titleBgm = AudioEngine::play2d("Sound/BGM/title_bgm.wav");
    AudioEngine::setLoop(titleBgm, true);
    
}

void Title::update(float deltaTime)
{
    if(changeScene)
    {
        volume -= 0.01;
        AudioEngine::setVolume(titleBgm, volume);
    }
    
<<<<<<< HEAD
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
 
    
=======
    if(IsSoundless())
    {
        AudioEngine::stop(titleBgm);
    }
}

bool Title::IsSoundless()
{
    if(volume <=0 )return true;
    else return false;
>>>>>>> ryou62525/master
}
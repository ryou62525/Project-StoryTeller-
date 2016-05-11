//
//  Title.cpp
//  storyTeller
//
//  Created by vantan on 2016/04/23.
//
//

#include "Title.hpp"

USING_NS_CC;

Scene* Title::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Title::create();
    
    scene->addChild(layer);
    return  scene;
}

bool Title::init()
{
    if(!Layer::init()){ return false; }
    
    SetImageInfo();
    
    return true;
}

//画像の情報をテキストファイルから呼び出す
void Title::SetImageInfo()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/TitleImagePath.txt");
    std::ifstream inFile(filePath);
    assert(inFile);
    
    size_t imageValue;
    std::string _filePath;
    Vec2 pos, size;
    
    inFile >> imageValue;
    Sprite* bgSprite[imageValue];
    
    for(int i = 0; i < imageValue; i++)
    {
        //画像のパス、横の座標、縦の座標、
        //横のサイズの比率、縦のサイズの比率の順にデータを読み込む
        inFile >> _filePath >> pos.x >> pos.y >> size.x >> size.y;
        
        //変数に読み込んだデータをもとに情報をセットしていく
        bgSprite[i] = Sprite::create(_filePath);
        bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
        bgSprite[i]->setScale(size.x, size.y);
        
        this->addChild(bgSprite[i]);
    }
}
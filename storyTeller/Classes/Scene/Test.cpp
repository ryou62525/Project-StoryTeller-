//
//  Test.cpp
//  storyTeller
//
//  Created by vantan on 2016/08/18.
//
//
#define UTF8_CHAR_LEN(byte)((0xE500000>>((byte>>3)&0x1e))&3)+1

int GetUnicodeLength(const char* utf8)
{
    int byteCount = 0;
    
    while (*utf8) {
        int charRen = UTF8_CHAR_LEN(*utf8);
        byteCount++;
        utf8+=charRen;
    }
    return byteCount;
}


#include "Test.hpp"
USING_NS_CC;

Scene* Test::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Test::create();
    scene->addChild(layer);
    return scene;
}

bool Test::init()
{
    if(!Layer::create()){return false;}
    Size winSize = Director::getInstance()->getVisibleSize();
    auto layer = Layer::create();
    
    {
        auto sprite = Sprite3D::create("FbxFile/st_floor.c3b");
        sprite->setPosition(0,0);
        sprite->setScale(1);
        layer->addChild(sprite);
    }
    
    {
        auto s = layer->getContentSize();
        camera = Camera::createPerspective(60, (GLfloat)s.width/s.height, 1, 1000);
        camera->setCameraFlag(CameraFlag::USER1);
        camera->lookAt(Vec3(0,0,0));
        camera->setPosition3D(Vec3(0,0,0));
        layer->addChild(camera);
        layer->setCameraMask((unsigned short)CameraFlag::USER1);
    }
    
    addChild(layer);
    
//    TTFConfig ttfConfig("Fonts/arial.ttf",24, GlyphCollection::DYNAMIC);
//    auto label = Label::createWithTTF(ttfConfig, "Hello World!!");
//    label->setVerticalAlignment(TextVAlignment::TOP);
//    label->setHorizontalAlignment(TextHAlignment::LEFT);
//    label->setColor(Color3B::WHITE);
//    
//    label->setPosition(winSize/2);
//    label->setStringWithRunText("Hello World!!", 0.05f);
//    addChild(label)
    return true;
}

void Test::update(float deltaTime)
{
    
}
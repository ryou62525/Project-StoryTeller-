#include "AppDelegate.h"
#include "Scene/GameLayer.hpp"
USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320),
                     smallResolutionSize = cocos2d::Size(480, 320),
                     mediumResolutionSize = cocos2d::Size(1024, 768),
                     largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
    {
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    glview->setDesignResolutionSize(1920, 1080, ResolutionPolicy::SHOW_ALL);
    
    FileUtils::getInstance()->addSearchPath("SpriteStudioFile");

    Scene* scene = MainApp::CreateScene();
    director->runWithScene(scene);
    
    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}
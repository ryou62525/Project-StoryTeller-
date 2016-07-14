#include "AppDelegate.h"
#include "Scene/Title.hpp"
#include "Scene/SceneManager.hpp"
#include "Scene/Game.hpp"
#include "Scene/HomeMenu.hpp"


USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320),
                     smallResolutionSize = cocos2d::Size(480, 320),
                     mediumResolutionSize = cocos2d::Size(1024, 768),
                     largeResolutionSize = cocos2d::Size(2048, 1536);

enum Scenes
{
    Title,
    Menu,
    Game,
    Result,
};

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

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    glview->setDesignResolutionSize(1920, 1080, ResolutionPolicy::SHOW_ALL);
    
    // create a scene. it's an autorelease object
    Scene* scene = Game::CreateScene();
   
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

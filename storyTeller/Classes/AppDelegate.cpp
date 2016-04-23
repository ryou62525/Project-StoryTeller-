#include "AppDelegate.h"
#include "Title.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
    
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
	return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();

	auto glview = director->getOpenGLView();
	if (!glview) {

        glview = GLViewImpl::create("testTemplate");
		director->setOpenGLView(glview);
	}
    
    director->getOpenGLView()->setDesignResolutionSize(840, 640,
                                                       ResolutionPolicy::SHOW_ALL);

	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);
    
    //Resource配下のフォルダをSearchPathに追加して読み込み時フォルダ名を省略する
    FileUtils::getInstance()->addSearchPath("CharacterObject");
	FileUtils::getInstance()->addSearchPath("Map");
    FileUtils::getInstance()->addSearchPath("Scene");
    FileUtils::getInstance()->addSearchPath("SS5Player");
    FileUtils::getInstance()->addSearchPath("SSCommon");

	// create a scene. it's an autorelease object
    Scene* scene = { Title::CreateScene() };

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::HelloWorld() : isRun(false)
{
    
}

HelloWorld::~HelloWorld()
{
    CC_SAFE_RELEASE(ssplayer);
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    

	auto ss5man = ss::SS5Manager::getInstance();
	ss5man->createEffectBuffer(1024);

	auto resman = ss::ResourceManager::getInstance();
	resman->addData("SpriteStudioFile/storyteller_project/storyteller.ssbp");
    //resman->addData("SpriteStudioFile/character_template_comipo/character_template1.ssbp");
	
    std::string path = "storyteller";
	ssplayer = ss::Player::create();
    //ssplayer->retain();
	ssplayer->setData(path);
    ssplayer->play("st_girl/st_wait_girl01");
    
    runplayer = ss::Player::create();
    runplayer->setData(path);

    //ssplayer->setData("character_template1");
    //ssplayer->play("character_template_3head/stance");
    
	ssplayer->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	ssplayer->setScale(0.5f, 0.5f);
	//ssplayer->setUserDataCallback(CC_CALLBACK_2(HelloWorld::userDataCallback, this));
	//ssplayer->setPlayEndCallback(CC_CALLBACK_1(HelloWorld::playEndCallback, this));
	this->addChild(ssplayer, 5);
    
    runplayer->setPosition(ssplayer->getPosition());
    runplayer->setScale(ssplayer->getScale());
    this->addChild(runplayer, 5);
    
    
	animation_count = 0;
    isRun = false;
    
    auto questButton = ui::Button::create("ImageFile/UIQuest.png");
    questButton->setPosition(Vec2(368.0f, 130.0f));
    questButton->setScale(0.1f, 0.1f);
    this->addChild(questButton);
    //questButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchQuestEvent, this));
    questButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchQuestEvent, this));
                                       
    auto itemButton = ui::Button::create("ImageFile/UIItem.png");
    itemButton->setPosition(Vec2(1200.0f, 130.0f));
    itemButton->setScale(0.1f, 0.1f);
    this->addChild(itemButton);
    itemButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchItemEvent, this));
    
    auto userButton = ui::Button::create("ImageFile/UIUser.png");
    userButton->setPosition(Vec2(1600.0f, 130.0f));
    userButton->setScale(0.1f, 0.1f);
    this->addChild(userButton);
    userButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchUserEvent, this));

    
	//this->scheduleUpdate();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

int num = -1;

void HelloWorld::update(float delta)
{
//		animation_count++;
//		if ((animation_count % 180) == 0)
//        {
//            ++num;
//            switch (num % 4) {
//                case 0:
//                    
//                    ssplayer->play("st_girl/st_attack_girl01");
//                    //this->ssplayer->retain();
//                    CCLOG("Re:%d", ssplayer->getReferenceCount());
//        
//                    //ssplayer->motionBlendPlay("character_template_3head/stance");
//                    
//                    break;
//                case 1:
//                    
//                    ssplayer->play("st_girl/st_jump_girl01");
//                    //this->ssplayer->retain();
//                    CCLOG("Re:%d", ssplayer->getReferenceCount());
//                    
//                    //ssplayer->motionBlendPlay("character_template_3head/run");
//                    
//                    break;
//                case 2:
//                    
//                    ssplayer->play("st_girl/st_run_girl01");
//                    CCLOG("Re:%d", ssplayer->getReferenceCount());
//                    //this->ssplayer->retain();
//                    
//                    break;
//                case 3:
//                    
//                    ssplayer->play("st_girl/st_attack_girl01");
//                    CCLOG("Re:%d", ssplayer->getReferenceCount());
//                    
//                    break;
//                
//            }
//            
//            //if(num++){ssplayer->retain();}
//            CCLOG("%d", num);
//            CCLOG("%s", ssplayer->getPlayAnimeName().c_str());
//            
////			if (change == false)
////            {
////				change = true;
////                ssplayer->motionBlendPlay("st_girl/st_run_girl01");
////
////            }
////            else
////            {
////				change = false;
////               ssplayer->motionBlendPlay("st_girl/st_attack_girl01");
////                
////            }
//		}
    
}

void HelloWorld::userDataCallback(ss::Player* player, const ss::UserData* data)
{
	//
}

void HelloWorld::playEndCallback(ss::Player* player)
{
    this->ssplayer = player;
    ssplayer->retain();
}

void HelloWorld::touchQuestEvent(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    switch(type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            
            ssplayer->play("st_girl/st_attack_girl01", 1);
            
            
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            this->getEventDispatcher()->setEnabled(false);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            break;
        
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            
            ssplayer->play("st_girl/st_wait_girl01", 0);
            
            
            break;

    }
}

void HelloWorld::touchItemEvent(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    switch(type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            
            ssplayer->play("st_girl/st_jump_girl01", 1);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            this->getEventDispatcher()->setEnabled(false);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            
            ssplayer->play("st_girl/st_wait_girl01", 0);
            
            
            break;
    }
}

void HelloWorld::touchUserEvent(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    switch(type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            ssplayer->play("st_girl/st_stand_girl01", 0);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            this->getEventDispatcher()->setEnabled(false);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            
            ssplayer->play("st_girl/st_wait_girl01", 0);
            
            
            break;

    }
}
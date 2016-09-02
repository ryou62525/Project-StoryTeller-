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

HelloWorld::HelloWorld()
{
    
}

HelloWorld::~HelloWorld()
{
    CC_SAFE_RELEASE(ssplayer);
    CC_SAFE_RELEASE(enemy);
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
    
    enemy = ss::Player::create();
    enemy->setData(path);
    enemy->play("st_monster01/st_attack_specter01");
    
    //ssplayer->setData("character_template1");
    //ssplayer->play("character_template_3head/stance");
    
    pos = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	ssplayer->setPosition(pos.x, pos.y);
    //ssplayer->setFlippedX(true);
	ssplayer->setScale(0.5f, 0.5f);
	//ssplayer->setUserDataCallback(CC_CALLBACK_2(HelloWorld::userDataCallback, this));
	//ssplayer->setPlayEndCallback(CC_CALLBACK_1(HelloWorld::playEndCallback, this));
	this->addChild(ssplayer, 5);
    
    enemy->setPosition(pos.x - 210, visibleSize.height / 2);
    enemy->setFlippedX(true);
    enemy->setScale(0.5f, 0.5f);
    this->addChild(enemy, 5);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchMoved = [](cocos2d::Touch* touch, cocos2d::Event* event)->bool {
        
        CCLOG("touch");
        
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
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
    if(isRun) {
        pos.x -= speed;
    }
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
            
            
            //ssplayer->play("st_girl/st_attack_girl01", 1);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            ssplayer->play("st_girl/st_run_girl01", 0);

            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            ssplayer->play("st_girl/st_wait_girl01", 0);

            break;
        
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            
            ssplayer->play("st_girl/st_attack_girl01", 1);
            //ssplayer->play("st_girl/st_wait_girl01", 0);
            
            
            break;

    }
}

void HelloWorld::touchItemEvent(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    switch(type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            
            //ssplayer->play("st_girl/st_damage_girl01", 1);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            ssplayer->play("st_girl/st_wait_girl01", 0);

            break;
            
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            ssplayer->play("st_girl/st_jump_girl01", 1);
            
            
            break;
    }
}

void HelloWorld::touchUserEvent(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    switch(type)
    {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            
            //ssplayer->play("st_girl/st_wait_girl01", 0);
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            
            
            break;
            
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            
            ssplayer->play("st_girl/st_wait_girl01", 0);

            break;
            
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            
            
            ssplayer->play("st_girl/st_run_girl01", 0);
            isRun = true;
            
            break;

    }
}
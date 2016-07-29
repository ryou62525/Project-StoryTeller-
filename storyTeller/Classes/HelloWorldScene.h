#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SSPlayer/SS5Player.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    HelloWorld();
    ~HelloWorld();

    virtual bool init() override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	virtual void update(float delta) override;

	void userDataCallback(ss::Player* player, const ss::UserData* data);

	void playEndCallback(ss::Player* player);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void touchQuestEvent(Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void touchItemEvent(Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void touchUserEvent(Ref* ref, cocos2d::ui::Widget::TouchEventType type);

private:

    ss::Player* runplayer;
	ss::Player* ssplayer;
	int animation_count;
    bool isRun;
};

#endif // __HELLOWORLD_SCENE_H__

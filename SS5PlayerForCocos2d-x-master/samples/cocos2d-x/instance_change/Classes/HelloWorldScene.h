#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SSPlayer/SS5Player.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
//    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
//    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
//    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
//    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


	//アップデート
	virtual void update(float delta);

	//ユーザーデータコールバック
	void userDataCallback(ss::Player* player, const ss::UserData* data);

	//アニメーション終了コールバック
	void playEndCallback(ss::Player* player);

private:
<<<<<<< Updated upstream:SS5PlayerForCocos2d-x-master/samples/cocos2d-x/instance_change/Classes/HelloWorldScene.h
	//SS5プレイヤー
	ss::Player *ssplayer;

	//情報表示用ラベル
	cocos2d::Label *label;
=======
    
    ss::Player* enemy;
	ss::Player* ssplayer;
    cocos2d::Vec2 pos;
    float speed;
	int animation_count;
    bool isRun;
>>>>>>> Stashed changes:storyTeller/Classes/HelloWorldScene.h
};

#endif // __HELLOWORLD_SCENE_H__

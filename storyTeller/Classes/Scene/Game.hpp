//
//  Game.hpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#ifndef Game_hpp
#define Game_hpp

#include "cocos2d.h"
#include "../SSPlayer/SS5Player.h"


class Game : public cocos2d::Layer
{
    
    CC_SYNTHESIZE_RETAIN(ss::Player*, _player, Player);
    CC_SYNTHESIZE_RETAIN(ss::Player*, _enemy, Enemy);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite3D*, _stage, Stage);
    CC_SYNTHESIZE_RETAIN(cocos2d::Camera*, _camera, Camera);
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _sister, Sister);
    CC_SYNTHESIZE(bool, _isSkip, IsSkip);
    CC_SYNTHESIZE(bool, _isTouch, IsTouch);
    CC_SYNTHESIZE(bool, _isBegan, IsBegan);
    CC_SYNTHESIZE(float, _Zorder, Zorder);
    
    enum class GameState
    {
        TUTORIAL,
        PLAY,
        CLEAR,
        RESULT,
        GAMEOVEER
        
    } gameState;
    
public:
    
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 visibleOrigin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    static cocos2d::Scene* CreateScene();
    
protected:
    
    virtual bool init() override;
    virtual void update(float deltaTime) override;
    
    CREATE_FUNC(Game);
    
    // アニメーションファイル読み込み
    void manageSprite(const std::string& dataName_ssbp);
    
    // アニメーション再生
    void playAnimation(const std::string& stateName, int loop = 0);
    
    // アニメーション再生（Blend有り）
    void playAnimationWithBlend(const std::string& stateName, int loop = 0);
    
    
private:
    Game();
    virtual ~Game();

    // タッチイベント
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override;// タッチイベント
    
    // 姉出現イベント
    void showSister(cocos2d::Vec2 showStartPos);
    
    // チュートリアル
    void tutorialEvent();
    
    // 姉削除
    void removeSister();
    
    // 敵追加
    void addEnemy();
    
    // ゲームスタート
    void onGameStart();
    
    // ゲームクリア
    void onClear();
    
    // ゲームリザルト
    void onGameResult();
    
    // ゲームオーバー
    void onGameOver();
};

#endif /* Game_hpp */

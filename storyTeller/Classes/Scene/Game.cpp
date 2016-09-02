//
//  Game.cpp
//  storyTeller
//
//  Created by vantan on 2016/07/19.
//
//

#include "Game.hpp"
#include "../FollowCamera.hpp"

USING_NS_CC;
using namespace ss;

Scene* Game::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Game::create();
    scene->addChild(layer);
    return  scene;
}

Game::Game()
: _player(nullptr)
, _enemy(nullptr)
, _sister(nullptr)
, _camera(nullptr)
, _stage(nullptr)
, _isSkip(false)
, _isTouch(false)
, _isBegan(false)
, gameState(GameState::TUTORIAL)
{
}

Game::~Game()
{
    CC_SAFE_RELEASE_NULL(_player);
    CC_SAFE_RELEASE_NULL(_camera);
    CC_SAFE_RELEASE_NULL(_stage);
    CC_SAFE_RELEASE_NULL(_player);
    CC_SAFE_RELEASE_NULL(_enemy);
}

bool Game::init()
{
    if(!Layer::init()){return false;}

    auto layer = Layer::create();
    
    _player = Player::create();
   
    //3Dのステージの設定(FBXからの読み込み)
    _stage = Sprite3D::create("FbxFile/test_stage01.c3b");
    _stage->setPosition3D(Vec3(0, 0, -50));
    _stage->setScale(10);
    
    layer->addChild(_stage);
    
    //プレイヤーの設定(SpriteStudio)
    this->manageSprite("storyteller_project/storyteller.ssbp");
    _player->setData("storyteller");
    _player->setPosition3D(Vec3(visibleSize.width / 2 - 80, 200, 0.0f));
    _player->setScale(0.3f);
    this->playAnimation("wait");
    this->getPlayer()->setFlippedX(true);
    layer->addChild(_player, 50);
    
    // 敵を追加
    addEnemy();
    
    // アリスの姉出現
    showSister(Vec2(visibleOrigin.x - 100, visibleSize.height / 2 + 100));
    
    //カメラの設定
    _camera = Camera::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 1000);
    _camera->setCameraFlag(CameraFlag::USER1);
    _camera->setPosition3D(Vec3(0, 0, 10));
    _camera->lookAt(_stage->getPosition3D());
    layer->addChild(_camera);
    layer->setCameraMask((unsigned short)CameraFlag::USER1);
    addChild(layer);
    
    // タッチ操作
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Game::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Game::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Game::onTouchCancelled, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->scheduleUpdate();
    
    return true;
}

void Game::update(float deltaTime)
{
    // カメラの座標をプレイヤーのx軸に合わせる（プレイヤーを常に追尾）// カメラの座標をプレイヤーのx軸に合わせる（プレイヤーを常に追尾）
    this->getCamera()->setPosition(Vec2(this->getPlayer()->getPositionX(), 0));
    
    this->getPlayer()->setPositionZ(_Zorder);
    
    //CCLOG("%.2f", Zorder);

}

bool Game::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (gameState == GameState::PLAY) {
        if (this->getIsBegan()) {
            this->playAnimationWithBlend("run");
            this->setIsBegan(true);
        }
        else {
            playAnimationWithBlend("attack");
        }
    }
    
    log("Began");
    
    if (this->getIsTouch() == false) {
        removeSister();
    }
    
    return true;
}

void Game::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (gameState == GameState::PLAY) {
        
        this->setIsBegan(true);
    
        // 前回とのタッチした差分を取得
        Vec2 deltaPos = touch->getDelta();
        float posX = this->getPlayer()->getPositionX() + deltaPos.x / 5;
        float posZ = this->getPlayer()->getPositionZ() + deltaPos.y;
        Vec3 newPos = Vec3(posX, 0.0, posZ);
    
        // 移動制限範囲を指定
        newPos.clamp(Vec3(10 + this->getPlayer()->getContentSize().width, this->getPlayer()->getPositionY(), this->getPlayer()->getPositionZ()),
                     Vec3(visibleSize.width - this->getStage()->getContentSize().width + 50, this->getPlayer()->getPositionY(), this->getPlayer()->getPositionZ()));
        
        this->getPlayer()->setPosition3D(newPos);
    
        // 反転
        if (deltaPos.x > 0) {
            this->getPlayer()->setFlippedX(true);
        }
        else if (deltaPos.x < 0) {
            this->getPlayer()->setFlippedX(false);
        }
    
    
        // Z軸の座標を更新
        if (deltaPos.y > 0) {
            this->_Zorder -= 0.5f;
            if (_Zorder < -300.0f) {
                _Zorder = -300.0f;
            }
        }
        if (deltaPos.y < 0) {
            this->_Zorder += 0.5f;
            if (_Zorder > 200.0f) {
                _Zorder = 200.0f;
            }
        }
    
    }
    
    log("Moved");
}

void Game::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    this->playAnimationWithBlend("wait");
    
    log("Ended");
}

void Game::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
    onTouchEnded(touch, event);
}


//-----------------------------------------------------------------------------------------------
//
// protectedメソッド
//
//-----------------------------------------------------------------------------------------------
void Game::manageSprite(const std::string& dataName_ssbp)
{
    auto ss5man = SS5Manager::getInstance();
    ss5man->createEffectBuffer(1024);
    
    auto resman = ResourceManager::getInstance();
    resman->addData(dataName_ssbp);
}

void Game::playAnimation(const std::string &stateName, int loop)
{
    std::string name = stateName;
    this->getPlayer()->play("st_girl/st_" + name + "_girl01", loop);
}

void Game::playAnimationWithBlend(const std::string &stateName, int loop)
{
    std::string name = stateName;
    this->getPlayer()->motionBlendPlay("st_girl/st_" + name + "_girl01", loop);
}

//----------------------------------------------------------------------------------------------
//
// private メソッド
//
//----------------------------------------------------------------------------------------------

// 姉出現イベント
void Game::showSister(cocos2d::Vec2 showStartPos)
{
    auto winSize = Director::getInstance()->getWinSize();
    
    _sister = Sprite::create("alice's sister.png");
    _sister->setPosition(showStartPos);
    _sister->setScale(0.1f);
    
    auto move = MoveTo::create(1.0f, Vec2(winSize.width / 2 + 100, showStartPos.y));
    
    auto flip = CallFunc::create([this]() {
        this->getSister()->setFlippedX(true);
    });
    
    auto move2 = MoveBy::create(0.5f, Vec2(-120, 0));
    
    auto flip2 = CallFunc::create([this]() {
        this->getSister()->setFlippedX(false);
    });
    
    auto move3 = MoveBy::create(0.5f, Vec2(135, 0));
    
    auto flip3 = CallFunc::create([this]() {
        this->getSister()->setFlippedX(true);
    });
    
    auto move4 = MoveBy::create(0.5f, Vec2(-200, 0));
    
    auto flip4 = CallFunc::create([this]() {
        this->getSister()->setFlippedX(false);
    });
    
    auto sequence = Sequence::create(move, flip, move2, flip2, move3, flip3, move4, flip4, NULL);
    
    this->getSister()->runAction(sequence);
    
    this->addChild(this->getSister(), 30);
}

// チュートリアル
void Game::tutorialEvent()
{
    
}

// 姉削除
void Game::removeSister()
{
    auto winSize = Director::getInstance()->getWinSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto flip = CallFunc::create([this]() {
        this->getSister()->setFlippedX(true);
    });
    
    auto back = MoveTo::create(1.0f, Vec2(origin.x - 100, winSize.height / 2 + 100));
    
    auto remove = CallFunc::create([this]() {
        this->getSister()->removeFromParent();
        
        this->onGameStart();
    });
    
    auto sequence = Sequence::create(flip, back, remove, nullptr);
    
    this->getSister()->runAction(sequence);
    
    if (!this->getIsTouch()) {
        this->setIsTouch(true);
    }
    
}

// 敵追加
void Game::addEnemy()
{
    auto winSize = Director::getInstance()->getWinSize();
    
    this->_enemy = Player::create();
    manageSprite("storyteller.ssbp");
    _enemy->setData("storyteller");
    _enemy->setPosition3D(Vec3(winSize.width - 20, 200, 0));
    _enemy->setScale(0.30f);
    _enemy->play("st_monster01/st_run_specter01");
    _enemy->setStep(0.5f);
    this->addChild(_enemy, 50);
    
}

// ゲームスタート
void Game::onGameStart()
{
    gameState = GameState::PLAY;
}

// ゲームクリア
void Game::onClear()
{
}

// ゲームリザルト
void Game::onGameResult()
{
}

// ゲームオーバー
void Game::onGameOver()
{
}
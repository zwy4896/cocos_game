#include "HelloWorldScene.h"
#include "LevelScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getWinSize();
    
    auto background = Sprite::create("bg_1.png");
    background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//    背景平铺
    float winW = winSize.width;
    float winH = winSize.height;
    float spx = background->getTextureRect().getMaxX();
    float spy = background->getTextureRect().getMaxY();

    background->setScaleX(winW / spx);
    background->setScaleY(winH / spy);
    this->addChild(background);
    this->scheduleOnce(CC_SCHEDULE_SELECTOR(HelloWorld::start), 1.5f);
    return true;
}

void HelloWorld::start(float dt) {
    auto reScene = TransitionCrossFade::create(0.3f, LevelScene::createScene());
    Director::getInstance()->replaceScene(reScene);
}

void HelloWorld::startCallBack(cocos2d::Ref *ref) { 
    auto reScene = TransitionCrossFade::create(0.3f, LevelScene::createScene());
    Director::getInstance()->replaceScene(reScene);
}


//
//  LevelScene.cpp
//  cocos2d
//
//  Created by Bluzy on 2021/6/28.
//

#include "LevelScene.h"
#include "GameManager.h"

USING_NS_CC;

cocos2d::Scene *LevelScene::createScene() { 
    auto scene = Scene::create();
    auto layer = LevelScene::create();
    scene->addChild(layer);
    
    GameManager::destroyInstance();
    
    return scene;
}

bool LevelScene::init() { 
    if(!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size winSize = Director::getInstance()->getWinSize();
    
    auto background = Sprite::create("back.jpg");
    background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//    背景平铺
    float winW = winSize.width;
    float winH = winSize.height;
    float spx = background->getTextureRect().getMaxX();
    float spy = background->getTextureRect().getMaxY();

    background->setScaleX(winW / spx);
    background->setScaleY(winH / spy);
    this->addChild(background);

    return true;
}


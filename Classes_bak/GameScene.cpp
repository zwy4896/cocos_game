//
//  GameScene.cpp
//  cocos2d
//
//  Created by Bluzy on 2021/6/28.
//

#include "GameScene.h"
#include "GameManager.h"
#include "HelloWorldScene.h"
#include "Hero.h"

USING_NS_CC;

int GameScene::level = 0;

cocos2d::Scene *GameScene::createScene(int level) {
    GameScene::level = level;
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init() { 
    if(!LayerColor::initWithColor(Color4B(0,250,250,255)))
    {
        return false;
    }
    pause = false;
    staticLayer = this;
    GameManager::getInstance()->staticLayer = staticLayer;
//    主层
    gameLayer = Layer::create();
    GameManager::getInstance()->gameLayer = gameLayer;
    staticLayer->addChild(gameLayer);
    
//    视差层
    ParallaxNode *paraNode = ParallaxNode::create();
    bkLayer = Layer::create();
    GameManager::getInstance()->bkLayer = bkLayer;
    gameLayer->addChild(paraNode, -2);
    paraNode->addChild(bkLayer, 1, Vec2(0.5, 0.8), Vec2(0, 0));
    
//    事物层
    thingLayer = Layer::create();
    GameManager::getInstance()->thingLayer = thingLayer;
    gameLayer->addChild(thingLayer);
    
//    怪物层
    monsterLayer = Layer::create();
    GameManager::getInstance()->monsterLayer = monsterLayer;
    gameLayer->addChild(monsterLayer);
    
//    英雄层
    heroLayer = Layer::create();
    GameManager::getInstance()->heroLayer = heroLayer;
    gameLayer->addChild(heroLayer);

//    特效层
    weaponLayer = Layer::create();
    GameManager::getInstance()->weaponLayer = weaponLayer;
    gameLayer->addChild(weaponLayer);

//    设置层
    settingLayer = Layer::create();
    GameManager::getInstance()->settingLayer = settingLayer;
    staticLayer->addChild(settingLayer);
    settingLayer->setVisible(false);
    
    hero = GameManager::getInstance()->hero;
    
    
    return true;
}


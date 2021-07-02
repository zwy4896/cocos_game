//
//  GameScene.h
//  cocos2d
//
//  Created by Bluzy on 2021/6/28.
//

#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"
class Hero;

class GameScene: public cocos2d::LayerColor
{
private:
    bool pause;
    cocos2d::Layer* staticLayer;    // 静态层
    cocos2d::Layer* gameLayer;      // 地图层
    cocos2d::Layer* bkLayer;        // 背景层-视差层
    cocos2d::Layer* settingLayer;   // 设置层
    cocos2d::Layer* weaponLayer;    // 特效层
    cocos2d::Layer* heroLayer;      // 英雄层
    cocos2d::Layer* monsterLayer;   // 怪物层
    cocos2d::Layer* thingLayer;     // 事物层
    
    Hero *hero;
public:
    static int level;
    static cocos2d::Scene* createScene(int level);
    virtual bool init();
    CREATE_FUNC(GameScene);
};

#endif /* GameScene_h */

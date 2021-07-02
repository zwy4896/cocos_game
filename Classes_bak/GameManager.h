//
//  GameManager.hpp
//  cocos2d
//
//  Created by Bluzy on 2021/6/28.
//

#ifndef GameManager_h
#define GameManager_h

#include "cocos2d.h"
class Hero;

class GameManager: public cocos2d::Ref{
private:
    static GameManager *gameManager;
    GameManager();
    
public:
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
    static GameManager *getInstance();
    static void destroyInstance();
    ~GameManager();
    void initRes();
};

#endif /* GameManager_h */

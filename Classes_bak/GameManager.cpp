//
//  GameManager.cpp
//  cocos2d
//
//  Created by Bluzy on 2021/6/28.
//

#include "GameManager.h"
#include "Hero.h"

USING_NS_CC;

GameManager *GameManager::gameManager = nullptr;

GameManager *GameManager::getInstance() { 
    if(!gameManager)
    {
        gameManager = new GameManager();
        gameManager->retain();
    }
    
    return gameManager;
}

void GameManager::destroyInstance() { 
    CC_SAFE_DELETE(gameManager);
}

GameManager::GameManager() {
    initRes();
}

void GameManager::initRes() {
    hero = nullptr;
    int a = 0;
}

GameManager::~GameManager() {
    CC_SAFE_DELETE(gameManager);
}





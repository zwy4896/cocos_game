//
//  LevelScene.cpp
//  cocos2d
//
//  Created by Bluzy on 2021/6/28.
//

#include "Hero.h"

USING_NS_CC;

void Hero::initParam() { 
    startTag = true;
    jumpCount = 0;
    
}

void Hero::moveRight() { 
    this->setDir(DIR::DIR_RIGHT);
}


void Hero::moveLeft() { 
    this->setDir(DIR::DIR_LEFT);
}

void Hero::update(float dt) { 
    
}



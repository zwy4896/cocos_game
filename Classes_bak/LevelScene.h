//
//  LevelScene.h
//  cocos_game
//
//  Created by Bluzy on 2021/6/28.
//

#ifndef LevelScene_h
#define LevelScene_h

#include "cocos2d.h"

class LevelScene: public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(LevelScene);
};

#endif /* LevelScene_h */

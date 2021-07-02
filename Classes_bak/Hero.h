//
//  Hero.h
//  cocos_game
//
//  Created by Bluzy on 2021/6/28.
//

#ifndef _HERO_H
#define _HERO_H

#include "cocos2d.h"
enum DIR{
    DIR_LEFT,
    DIR_RIGHT
};

class Hero{
protected:
    bool startTag;
    int jumpCount;
    
public:
    CC_SYNTHESIZE(DIR, dir, Dir);
    virtual void initParam();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void update(float dt);
    
};

#endif /* HERO_H */

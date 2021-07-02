//
//  GameObject.h
//  cocos_game
//
//  Created by Bluzy on 2021/6/28.
//

#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "cocos2d.h"

class GameObject: public cocos2d::Sprite {
public:
    virtual bool init(float x, float y, float width, float height);
    virtual bool init(float x, float y, b2Vec2* points, int count);
};
#endif /* _GAME_OBJECT_H */

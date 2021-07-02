#ifndef _SLIME_H_
#define _SLIME_H_

#include "Aware.h"
/*史莱姆*/
class Slime : public Aware
{
protected:
	CC_SYNTHESIZE(float, speed, Speed);
public:
	virtual bool init(float x, float y, float width, float height) override;
	CREATE_FUNC_4(Slime, float, float, float, float);

	virtual void update(float ft) override;

	virtual void dead() override;

	virtual void ended() override;
/*
	virtual void BeginContact(GameObject* other, b2Contact* contact);
*/
	virtual void PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold) override;
	/*向左移动*/
	virtual void moveLeft();
	/*向右移动*/
	virtual void moveRight();
};

#endif

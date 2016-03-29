#pragma once

#include "gameNode.h"
#include "bullets.h"

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;

public:
	spaceShip();
	~spaceShip();

	HRESULT init();
	void release();
	void update();
	void render();

	float getX() { return _ship->getCenterX(); }
	float getY() { return _ship->getCenterY(); }
};


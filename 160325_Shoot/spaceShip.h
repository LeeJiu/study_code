#pragma once

#include "gameNode.h"
#include "bullets.h"



class enemy;		//상호참조를 피하자

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	enemy** _enemy;

	RECT _rcShip;
	float _x, _y;
	bool _isDead;

public:
	spaceShip();
	~spaceShip();

	HRESULT init();
	void release();
	void update(enemy** enemy);
	void render();

	//미사일 정보를 던져주자
	missile* getMissile() { return _missile; }

	//플레이어의 위치를 던져주자
	float getX() { return _x; }
	float getY() { return _y; }

	RECT getShipRect() { return _rcShip; }
	bool isDead() { return _isDead; }
	void die() { _isDead = true; }

	//적을 쏴서 맞췄는지
	void hit();
};


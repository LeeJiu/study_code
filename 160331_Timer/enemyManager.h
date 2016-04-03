#pragma once

#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

class spaceShip;

class enemyManager : public gameNode
{
private:
	int _x, _y, _rnd;
	bullet* _bullet;
	bullet2* _bullet2;

	spaceShip* _ship;

	float _time;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//적 총알 발싸
	void bulletFire();

	//총알과 spaceShip이 충돌했다면
	void collision();

	//전방선언 용 메모리 링크
	void setShipMemoryLink(spaceShip* ship) { _ship = ship; }
};


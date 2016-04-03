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

	//�� �Ѿ� �߽�
	void bulletFire();

	//�Ѿ˰� spaceShip�� �浹�ߴٸ�
	void collision();

	//���漱�� �� �޸� ��ũ
	void setShipMemoryLink(spaceShip* ship) { _ship = ship; }
};


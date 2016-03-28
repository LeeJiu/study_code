#pragma once
#include "gameNode.h"
#include "bullets.h"



class spaceShip;

class enemy : public gameNode
{
private:
	image* _enemy;
	bullet* _bullet;
	spaceShip* _ship;
	
	RECT _rcEnemy;
	float _x, _y;
	bool _isDead;

	int _count;

public:
	enemy();
	~enemy();

	HRESULT init(int i);
	void release();
	void update(spaceShip* ship);
	void render();

	//총 정보를 던져주자
	bullet* getBullet() { return _bullet; }

	RECT getEnemyRect() { return _rcEnemy; }
	bool isDead() { return _isDead; }
	void die() { _isDead = true; }

	//ship을 맞췄는지
	void hit();
};
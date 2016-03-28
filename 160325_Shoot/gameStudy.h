#pragma once

#include "gameNode.h"
#include "spaceShip.h"
#include "enemy.h"



class gameStudy : public gameNode
{
private:
	spaceShip* _spaceShip;
	enemy* _enemy[ENEMYMAX];
	float _x, _y;
	int _offsetX, _offsetY;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render();

};


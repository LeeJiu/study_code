#pragma once

#include "gameNode.h"
#include "spaceShip.h"
#include "enemyManager.h"

class gameStudy : public gameNode
{
private:
	spaceShip* _spaceShip;
	enemyManager* _enemyManager;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render();

};


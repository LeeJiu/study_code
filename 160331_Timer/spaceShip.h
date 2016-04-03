#pragma once

#include "gameNode.h"
#include "bullets.h"

//���漱��
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;

	enemyManager* _em;

public:
	spaceShip();
	~spaceShip();

	HRESULT init();
	void release();
	void update();
	void render();

	image* getShipImage() { return _ship; }

	//���漱�� �� �޸� ��ũ
	void setEnemyManagerMemoryLink(enemyManager* enemyMgr) { _em = enemyMgr; }
};


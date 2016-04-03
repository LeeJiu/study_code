#pragma once

#include "gameNode.h"
#include "bullets.h"

//전방선언
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

	//전방선언 용 메모리 링크
	void setEnemyManagerMemoryLink(enemyManager* enemyMgr) { _em = enemyMgr; }
};


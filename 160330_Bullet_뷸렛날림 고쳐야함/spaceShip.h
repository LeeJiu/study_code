#pragma once

#include "gameNode.h"
#include "bullets.h"

//전방선언
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;

	enemyManager* _em;

public:
	spaceShip();
	~spaceShip();

	HRESULT init();
	void release();
	void update();
	void render();

	void removeMissile(int arrNum);

	//충돌 함수
	void collision(void);

	missile* getMissile() { return _missile; }
	image* getShipImage() { return _ship; }

	//전방선언 용 메모리 링크
	void setEnemyManagerMemoryLink(enemyManager* enemyMgr) { _em = enemyMgr; }
};


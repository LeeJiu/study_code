#pragma once

#pragma warning(disable : 4996)

#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//전방선언
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	int _currentHP;
	int _maxHP;

	enemyManager* _em;

	progressBar* _hpBar;

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

	//피 깎자
	void hitDamage(float damage);

	missile* getMissile() { return _missile; }
	image* getShipImage() { return _ship; }

	//전방선언 용 메모리 링크
	void setEnemyManagerMemoryLink(enemyManager* enemyMgr) { _em = enemyMgr; }
};


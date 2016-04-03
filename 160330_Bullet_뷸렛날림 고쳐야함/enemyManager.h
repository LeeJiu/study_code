#pragma once

#include "gameNode.h"
#include "minion.h"
#include "boss.h"
#include "bullets.h"
#include <vector>


class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vEnemy::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	bullet* _bullet;		//공용으로 쏘는 총알
	bullet2* _bullet2;		//보스가 쏘는 총알
	bullet3* _bullet3;		//보스가 또 쏠껄?

	spaceShip* _ship;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//미니언 셋팅 해줄 함수
	void setMinion();

	//보스 셋팅 해줄 함수
	void setBoss();

	//적 총알 발싸
	void minionBulletFire();

	void removeMinion(int arrNum);

	//나의 총알과 spaceShip이 충돌했다면
	void collision();

	inline vector<enemy*> getVMinion() { return _vMinion; }
	inline vector<enemy*>::iterator getVIMinion() { return _viMinion; }

	//전방선언 용 메모리 링크
	void setShipMemoryLink(spaceShip* ship) { _ship = ship; }
};


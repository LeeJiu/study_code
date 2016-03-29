#pragma once

#include "gameNode.h"
#include "minion.h"
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

	//�������� ����� �Ѿ� ����������
	bullet* _bullet;

	spaceShip* _spaceShip;

public:
	enemyManager();
	~enemyManager();

	HRESULT init(spaceShip* spaceShip);
	void release();
	void update();
	void render();

	//�̴Ͼ� ���� ���� �Լ�
	void setMinion();

	//�� �Ѿ� �߽�
	void minionBulletFire();

	inline vector<enemy*> getVMinion() { return _vMinion; }
	inline vector<enemy*>::iterator getVIMinion() { return _viMinion; }
};


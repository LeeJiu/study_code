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

	bullet* _bullet;		//�������� ��� �Ѿ�
	bullet2* _bullet2;		//������ ��� �Ѿ�
	bullet3* _bullet3;		//������ �� ��?

	spaceShip* _ship;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�̴Ͼ� ���� ���� �Լ�
	void setMinion();

	//���� ���� ���� �Լ�
	void setBoss();

	//�� �Ѿ� �߽�
	void minionBulletFire();

	void removeMinion(int arrNum);

	//���� �Ѿ˰� spaceShip�� �浹�ߴٸ�
	void collision();

	inline vector<enemy*> getVMinion() { return _vMinion; }
	inline vector<enemy*>::iterator getVIMinion() { return _viMinion; }

	//���漱�� �� �޸� ��ũ
	void setShipMemoryLink(spaceShip* ship) { _ship = ship; }
};

#pragma once

#include "gameNode.h"
#include "bullets.h"

//���漱��
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

	//�浹 �Լ�
	void collision(void);

	missile* getMissile() { return _missile; }
	image* getShipImage() { return _ship; }

	//���漱�� �� �޸� ��ũ
	void setEnemyManagerMemoryLink(enemyManager* enemyMgr) { _em = enemyMgr; }
};


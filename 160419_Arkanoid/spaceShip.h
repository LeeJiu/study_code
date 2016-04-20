#pragma once

#pragma warning(disable : 4996)

#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//���漱��
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

	//�浹 �Լ�
	void collision(void);

	//�� ����
	void hitDamage(float damage);

	missile* getMissile() { return _missile; }
	image* getShipImage() { return _ship; }

	//���漱�� �� �޸� ��ũ
	void setEnemyManagerMemoryLink(enemyManager* enemyMgr) { _em = enemyMgr; }
};


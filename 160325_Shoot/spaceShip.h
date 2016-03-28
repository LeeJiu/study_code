#pragma once

#include "gameNode.h"
#include "bullets.h"



class enemy;		//��ȣ������ ������

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	enemy** _enemy;

	RECT _rcShip;
	float _x, _y;
	bool _isDead;

public:
	spaceShip();
	~spaceShip();

	HRESULT init();
	void release();
	void update(enemy** enemy);
	void render();

	//�̻��� ������ ��������
	missile* getMissile() { return _missile; }

	//�÷��̾��� ��ġ�� ��������
	float getX() { return _x; }
	float getY() { return _y; }

	RECT getShipRect() { return _rcShip; }
	bool isDead() { return _isDead; }
	void die() { _isDead = true; }

	//���� ���� �������
	void hit();
};


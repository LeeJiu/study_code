#pragma once
#include "gameNode.h"
#include "progressBar.h"

class player;

enum ENEMYSTATE
{
	R_IDLE_E,
	L_IDLE_E,
	R_WALK_E,
	L_WALK_E,
	R_ATTACK_E,
	L_ATTACK_E
};

struct tagEnemy
{
	image* image;
	RECT enemy;
	ENEMYSTATE state;
	float x, y;
	int maxHp;
	int curHp;
};


class enemy : public gameNode
{
private:
	tagEnemy _enemy;
	int _index, _count;

	progressBar* _hpBar;

	player* _player;

public:
	enemy();
	~enemy();

	HRESULT init();
	void release();
	void update();
	void render();

	void setFrame();

	//전방선언 용 메모리 링크
	void setPlayerMemoryLink(player* player) { _player = player; }

	void hit();
	void collision();

	RECT getRect() { return _enemy.enemy; }
};


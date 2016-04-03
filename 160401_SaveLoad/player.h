#pragma once
#include "gameNode.h"
#include "progressBar.h"

class enemy;

enum PLAYERSTATE
{
	R_IDLE,
	L_IDLE,
	R_WALK,
	L_WALK,
	R_ATTACK,
	L_ATTACK
};

struct tagPlayer
{
	image* image;
	RECT player;
	PLAYERSTATE state;
	float x, y;
	int maxHp;
	int curHp;
};


class player : public gameNode
{
private:
	tagPlayer _player;
	int _index, _count;

	progressBar* _hpBar;

	enemy* _enemy;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	void setFrame();

	//전방선언 용 메모리 링크
	void setEnemyMemoryLink(enemy* enemy) { _enemy = enemy; }

	void hit();
	void collision();

	RECT getRect() { return _player.player; }
};


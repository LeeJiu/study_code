#pragma once
#include "gameNode.h"

class ball;

struct tagEnemy
{
	image* image;
	float x, y;
	float radius;
	float angle;
};

class enemy : public gameNode
{
private:
	tagEnemy _enemy;
	ball* _ball;

	RECT _goal;
	RECT _tmp;

	int _score;

public:
	enemy();
	~enemy();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
	void goal();

	void setBallMemoryLink(ball* ball) { _ball = ball; }
};


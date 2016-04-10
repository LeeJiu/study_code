#pragma once
#include "gameNode.h"

class ball;

struct tagPlayer
{
	image* image;
	float x, y;
	float radius;
	float angle;
};

class player : public gameNode
{
private:
	tagPlayer _player;
	ball* _ball;

	RECT _goal;
	RECT _tmp;

	int _score;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();
	void goal();

	void setBallMemoryLink(ball* ball) { _ball = ball; }
};


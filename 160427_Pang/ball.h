#pragma once
#include "gameNode.h"

class player;

struct tagBall
{
	image* image;
	RECT rc;
	float x, y;
	float speed;
	float radius;
	int deadCnt;
	bool isRight;
	bool isDead;
};

class ball : public gameNode
{
private:
	vector<tagBall> _vBall;
	vector<tagBall>::iterator _viBall;

	float _gravity;

	player* _player;

public:
	ball();
	~ball();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
	void collision();
	void splitBall();
	void increaseBall(float x, float y, int deadCnt);

	void setPlayerMemoryLink(player* player) { _player = player; }
};


#pragma once
#include "gameNode.h"

class playerBar;
class block;

struct tagBall
{
	image* ball;
	RECT coll;
	float x, y;
	float radius;
	float angle;
	float speed;
};

class ball : public gameNode
{
private:
	tagBall _ball;
	playerBar* _bar;
	block* _block;

public:
	ball();
	~ball();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
	void barCollision();
	void blockCollision();

	void setBarMemoryLink(playerBar* bar) { _bar = bar; }
	void setBlockMemoryLink(block* block) { _block = block; }
};


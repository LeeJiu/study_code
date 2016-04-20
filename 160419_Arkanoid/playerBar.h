#pragma once
#include "gameNode.h"

struct tagBar
{
	image* bar;
	RECT rc;
	float x, y;
};

class playerBar : public gameNode
{
private:
	tagBar _bar;

public:
	playerBar();
	~playerBar();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();

	RECT getRect() { return _bar.rc; }
};


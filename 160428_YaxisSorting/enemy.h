#pragma once
#include "gameObject.h"

class enemy : public gameObject
{
private:
	tagObject _enemy;

	int _curFrameX, _curFrameY, _count;

public:
	enemy();
	~enemy();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void keyControl() {};
	void move();
	void setImage();
	void setFrame();

	RECT getRect() { return _enemy.rc; }
};


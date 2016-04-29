#pragma once
#include "gameObject.h"


class player : public gameObject
{
private:
	tagObject _player;

	int _curFrameX, _curFrameY, _count;

public:
	player();
	~player();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void keyControl();
	void move();
	void setImage();
	void setFrame();

	RECT getRect() { return _player.rc; }
};


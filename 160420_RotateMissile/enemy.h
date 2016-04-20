#pragma once

#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;

	int _count;
	int _fireCount;
	int _rndFireCount;

public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imagName, POINT position);
	void release();
	void update();
	void render();

	void move();
	void draw();

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }

};


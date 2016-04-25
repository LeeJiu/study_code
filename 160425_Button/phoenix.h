#pragma once
#include "ship.h"


class phoenix : public ship
{
public:
	phoenix();
	~phoenix();

	HRESULT init(const char* imageName, int x, int y);
	void release();
	void update();
	void render();

	void move();
};


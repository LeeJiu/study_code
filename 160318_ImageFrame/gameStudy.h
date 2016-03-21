#pragma once

#include "gameNode.h"


class gameStudy : public gameNode
{
private:
	image* _bg;
	image* _sakura;

	int timeCount;
	int imageFrame, direct;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void walk(int frame);
};


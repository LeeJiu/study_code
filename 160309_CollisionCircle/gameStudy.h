#pragma once

#include "gameNode.h"

class gameStudy : public gameNode
{
private:
	RECT rt, cc;
	int radius;
	bool isCollide;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


#pragma once

#include "gameNode.h"

class gameStudy : public gameNode
{
private:
	RECT _rc;
	int _x, _y;
	bool _changeDir, _changeColor;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


#pragma once

#include "gameNode.h"

#define INTERVAL 400

class gameStudy : public gameNode
{
private:
	RECT _rc, _tmp;
	RECT _land[2], _hurdle[3];
	POINT _ptLand[2], _ptHurdle[3];
	int _width[2], _height, _jumpCnt;
	float _gravity, _jumpPower;
	bool _isJump;

	char check[128];

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


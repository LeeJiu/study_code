#pragma once

#include "gameNode.h"
#define INTERVAL 400

struct tagHurdle
{
	RECT _upRc;
	RECT _downRc;
};


class gameStudy : public gameNode
{
private:
	HBRUSH MyBrush, OldBrush;		//면을 채울거야

	tagHurdle _hurdle[2];
	RECT _rc, _tmp;
	RECT _land;
	POINT _pt[2];
	int _score;
	float _gravity, _jumpPower;
	char _scoreShow[128];
	bool _isJump, _jumpHurdle;


public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


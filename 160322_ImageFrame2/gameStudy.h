#pragma once

#include "gameNode.h"
#define FRAME 10

class gameStudy : public gameNode
{
private:
	image* _bgImage;
	image* _sakuraIdle, * _sakuraWalk, * _sakuraJump, * _shadow;

	float _x, _y, _oldX, _oldY;
	float _jumpPw, _gravity;

	bool _isRight, _isIdle, _isJump;
	int _count;
	int _index;
	int _resizeX, _resizeY, _reAlpha;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void move();
};


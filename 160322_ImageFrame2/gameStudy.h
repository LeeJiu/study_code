#pragma once

#include "gameNode.h"
#define FRAME 10

class gameStudy : public gameNode
{
private:
	image* _bgImage;
	image* _sakuraIdle, * _sakuraWalk, * _sakuraJump;

	float _x, _y;
	float _jumpPw;

	bool _isRight, _isIdle, _isJump;
	int _count;
	int _index;


public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

};


#pragma once

#include "gameNode.h"

#define JUMPFRAME 10
#define WALKFRAME 7

class gameStudy : public gameNode
{
private:
	image* _sakura;
	image* _shadow;
	image* _box;

	RECT _rcPlayer, _rcBox[3], _tmp;
	POINT _ptBox[3];
	
	float _x, _y, _offsetX, _offsetY;
	float _jumpPw, _gravity;
	int _count, _index, _floor;
	bool _isWalk, _isJump;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void collision();
};


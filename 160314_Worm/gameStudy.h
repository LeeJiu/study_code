#pragma once

#include "gameNode.h"
#define PI 3.141592f
#define WORMMAX 10

struct Worms
{
	float x, y;
	bool isTail, isMove;
};

class gameStudy : public gameNode
{
private:
	Worms mWorm[WORMMAX];
	float mItemX, mItemY;
	float mAngle, mSpeed, mRadius;
	int mWormCnt;
	bool mGameStart;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void move();
	float getAngle(float x1, float y1, float x2, float y2);
	bool collision();
};


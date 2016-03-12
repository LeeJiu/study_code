#pragma once

#include "gameNode.h"
#define PI 3.14f
#define BULLETMAX 20

class gameStudy : public gameNode
{
private:
	SYSTEMTIME st;
	POINT ptHour, ptMinute, ptSecond;
	float hour, min, sec;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};


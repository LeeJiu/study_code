#pragma once

#include "gameNode.h"
#define PI 3.141592f
#define BULLETMAX 5

struct tagBullet
{
	RECT bullet;
	float x, y;
	float angle, bulletSpd, bulletPwX, bulletPwY;
	bool isFire;
};

class gameStudy : public gameNode
{
private:
	RECT circle;
	tagBullet bullet[BULLETMAX];
	float x, y, angle, gravity;
	float gunX, gunY;
	char str[128];

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void bulletFire();
	void bulletMove();
};


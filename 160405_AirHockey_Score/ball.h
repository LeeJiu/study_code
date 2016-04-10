#pragma once
#include "gameNode.h"

struct tagBall
{
	image* image;
	float x, y;
	float radius;
	float angle;
	float speed;
};

class ball : public gameNode
{
private:
	tagBall _ball;

public:
	ball();
	~ball();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision();

	float getX() { return _ball.x; }
	float getY() { return _ball.y; }
	float getRadius() { return _ball.radius; }

	void setAngle(float angle) { _ball.angle = angle; };
	void setSpeed(float speed) { _ball.speed = speed; };
};


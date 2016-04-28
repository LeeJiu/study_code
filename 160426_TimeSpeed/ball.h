#pragma once
#include "gameNode.h"


class ball : public gameNode
{
private:
	image* _ball;
	RECT _rc;
	float _x, _y, _saveX, _saveY;
	float _radius;
	float _angle;
	float _speed;
	float _distance, _saveDist;
	float _time, _elapsedTime;

public:
	ball();
	~ball();

	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();
	void move();
};


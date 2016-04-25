#pragma once

#include "gameNode.h"

class ship : public gameNode
{
protected:
	image* _image;
	RECT _rc;
	float _x, _y;
	float _angle;
	float _speed;
	float _radius;
	float _maxSpd;

public:
	ship();
	~ship();

	virtual HRESULT init(const char* imageName, float angle, float maxSpd);
	virtual void release() override;
	virtual void update() override;
	virtual void render() override;

	virtual void draw();
	virtual void keyControl();
	virtual void move();
};


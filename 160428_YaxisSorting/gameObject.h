#pragma once
#include "gameNode.h"

enum STATE 
{
	STAND,
	WALK
};

struct tagObject
{
	image* image;
	RECT rc;
	STATE state;
	float x, y;
	bool isRight;
};

class gameObject : public gameNode
{
public:
	gameObject();
	~gameObject();

	virtual HRESULT init(int x, int y) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void keyControl() = 0;
	virtual void move() = 0;

	virtual RECT getRect() = 0;
};


#pragma once
#include "gameNode.h"

struct tagSelect
{
	image* image;
	RECT rc;
	float x, y;
	float angle;
};

class selectScene : public gameNode
{
private:
	tagSelect _battle, _carrier, _phoenix;

	SHIP _select;

public:
	selectScene();
	~selectScene();

	HRESULT init();
	void release();
	void update();
	void render();

	SHIP selectShip() { return _select; }
	void setSelectNone() { _select = NONE; }
};


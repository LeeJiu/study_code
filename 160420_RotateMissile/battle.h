#pragma once

#include "gameNode.h"
#include "bullets.h"

class carrier;

struct tagUnit
{
	image* unit;
	float x, y;
	RECT rc;
	float angle;
	float speed;
};

class battle : public gameNode
{
private:
	tagUnit _battle;
	bullet* _bullet;

	carrier* _carrier;

public:
	battle();
	~battle();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void collision();

	void setCarrierMemoryLink(carrier* carrier) { _carrier = carrier; }
};


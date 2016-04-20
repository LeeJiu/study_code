#pragma once
#include "gameNode.h"

class battle;

struct tagCarrier
{
	image* carrier;
	RECT rc;
	float x, y;
	float angle;
	float speed;
};

class carrier : public gameNode
{
private:
	tagCarrier _carrier;

	battle* _battle;

public:
	carrier();
	~carrier();

	HRESULT init();
	void release();
	void update();
	void render();

	RECT getRect() { return _carrier.rc; }

	void setBattleMemoryLink(battle* battle) { _battle = battle; }
};


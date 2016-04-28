#pragma once
#include "gameNode.h"

struct tagHarpoon
{
	image* image;
	RECT rc;
	POINT pt;
	int speed;
	bool fire;
};

class player : public gameNode
{
private:
	RECT _player;
	POINT _pt;
	bool _isDead;
	
	tagHarpoon _harpoon;
	int _stretchHeight;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();
	void shoot();

	void dead() { _isDead = true; }
	void fireoff();

	bool getFire() { return _harpoon.fire; }
	RECT getPlayerRect() { return _player; }
	RECT getHarpoonRect() { return _harpoon.rc; }
};


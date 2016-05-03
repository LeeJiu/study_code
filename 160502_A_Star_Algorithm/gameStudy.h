#pragma once

#include "gameNode.h"
#include "tile.h"

class gameStudy : public gameNode
{
private:
	tile* _tile;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


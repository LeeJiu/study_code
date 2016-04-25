#pragma once

#include "gameNode.h"
#include "ship.h"


class starwarsScene : public gameNode
{
private:
	ship* _ship;

public:
	starwarsScene();
	~starwarsScene();

	HRESULT init();
	HRESULT init(SHIP ship);
	void release();
	void update();
	void render();
};


#pragma once

#include "gameNode.h"
#include "ship.h"

class battle;
class carrier;

class starwarsScene : public gameNode
{
private:
	battle* _battle;
	carrier* _carrier;

public:
	starwarsScene();
	~starwarsScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


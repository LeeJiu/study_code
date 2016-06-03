#pragma once

#include "gameNode.h"
#include "knight.h"

class ghostGoblinScene : public gameNode
{
	knight* _knight;

public:
	ghostGoblinScene();
	~ghostGoblinScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


#pragma once

#include "gameNode.h"
#include "balloon.h"
#include "player.h"

class gameStudy : public gameNode
{
private:
	balloon* _balloon;
	player* _player;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


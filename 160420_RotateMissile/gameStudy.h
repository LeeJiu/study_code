#pragma once

#include "gameNode.h"
#include "battle.h"
#include "carrier.h"

class gameStudy : public gameNode
{
private:
	battle* _battle;
	carrier* _carrier;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


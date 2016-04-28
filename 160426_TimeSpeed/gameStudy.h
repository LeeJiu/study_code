#pragma once

#include "gameNode.h"
#include "ball.h"

class gameStudy : public gameNode
{
private:
	ball* _ball;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


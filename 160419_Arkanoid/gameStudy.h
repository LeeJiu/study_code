#pragma once

#include "gameNode.h"
#include "playerBar.h"
#include "block.h"
#include "ball.h"

class gameStudy : public gameNode
{
private:
	playerBar* _bar;
	block* _block;
	ball* _ball;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


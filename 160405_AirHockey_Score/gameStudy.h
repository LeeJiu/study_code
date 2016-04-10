#pragma once

#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "ball.h"

class gameStudy : public gameNode
{
private:
	player* _player;
	enemy* _enemy;
	ball* _ball;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render();

};


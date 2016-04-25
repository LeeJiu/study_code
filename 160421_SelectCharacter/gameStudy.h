#pragma once
//http://wiki.teamliquid.net/starcraft2/Interceptor
#include "gameNode.h"
#include "starwarsScene.h"
#include "selectScene.h"

class gameStudy : public gameNode
{
private:
	starwarsScene* _ss;
	selectScene* _selScene;
	bool _gameStart;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


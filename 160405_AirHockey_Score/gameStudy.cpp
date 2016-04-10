#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("background", "image/stadium.bmp", WINSIZEX, WINSIZEY, false, false);
	
	_player = new player;
	_player->init();

	_enemy = new enemy;
	_enemy->init();

	_ball = new ball;
	_ball->init();

	_player->setBallMemoryLink(_ball);
	_enemy->setBallMemoryLink(_ball);

	return S_OK;
}

void gameStudy::release()
{
	_player->release();
	SAFE_DELETE(_player);

	_enemy->release();
	SAFE_DELETE(_enemy);
	
	_ball->release();
	SAFE_DELETE(_ball);

	gameNode::release();
}

void gameStudy::update()
{
	_player->update();

	_enemy->update();

	_ball->update();

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	_player->render();

	_enemy->render();

	_ball->render();


	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



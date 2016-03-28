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

	_offsetX = _offsetY = 0;

	IMAGEMANAGER->addImage("background", "bg_drought.bmp", WINSIZEX, WINSIZEY, false, false);

	_spaceShip = new spaceShip;
	_spaceShip->init();

	for (int i = 0; i < ENEMYMAX; ++i)
	{
		_enemy[i] = new enemy;
		_enemy[i]->init(i);
	}

	return S_OK;
}

void gameStudy::release()
{
	_spaceShip->release();
	SAFE_DELETE(_spaceShip);
	
	for (int i = 0; i < ENEMYMAX; ++i)
	{
		_enemy[i]->release();
		SAFE_DELETE(_enemy[i]);
	}

	gameNode::release();
}

void gameStudy::update()
{
	_offsetY -= 3;

	_spaceShip->update(_enemy);
	for (int i = 0; i < ENEMYMAX; ++i)
	{
		_enemy[i]->update(_spaceShip);
	}

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background")->loopRender(getMemDC(), 
		&RectMake(0, 0, WINSIZEX, WINSIZEY), _offsetX, _offsetY);
	//======================
	//이 사이에서 그려주면 됨.

	_spaceShip->render();
	for (int i = 0; i < ENEMYMAX; ++i)
	{
		_enemy[i]->render();
	}

	//======================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



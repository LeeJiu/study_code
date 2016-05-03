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

	_tile = new tile;
	_tile->init();

	return S_OK;
}

void gameStudy::release()
{
	_tile->release();
	SAFE_DELETE(_tile);

	gameNode::release();
}

void gameStudy::update()
{
	_tile->update();

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//IMAGEMANAGER->findImage("background")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	_tile->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
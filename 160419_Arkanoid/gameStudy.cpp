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

	IMAGEMANAGER->addImage("background", "image/background.bmp", WINSIZEX, WINSIZEY, false, false);

	_bar = new playerBar;
	_bar->init();

	_block = new block;
	_block->init();

	_ball = new ball;
	_ball->init();

	_ball->setBarMemoryLink(_bar);
	_ball->setBlockMemoryLink(_block);

	return S_OK;
}

void gameStudy::release()
{
	SAFE_DELETE(_bar);
	SAFE_DELETE(_block);
	SAFE_DELETE(_ball);

	gameNode::release();
}

void gameStudy::update()
{
	_bar->update();
	_block->update();
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

	_bar->render();
	_block->render();
	_ball->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



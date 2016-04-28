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
	IMAGEMANAGER->addImage("bullet", "image/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "image/ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));

	_player = new player;
	_player->init();

	_ball = new ball;
	_ball->init();

	_ball->setPlayerMemoryLink(_player);

	return S_OK;
}

void gameStudy::release()
{
	_player->release();
	SAFE_DELETE(_player);
	_ball->release();
	SAFE_DELETE(_ball);

	gameNode::release();
}

void gameStudy::update()
{
	_player->update();
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
	_ball->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



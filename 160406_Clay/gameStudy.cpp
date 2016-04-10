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
	IMAGEMANAGER->addImage("target", "image/target.bmp", 50, 50, true, 0x00ff00);
	IMAGEMANAGER->addFrameImage("balloon", "image/balloon.bmp", 400, 198, 8, 3, true, 0x00ff00);
	IMAGEMANAGER->addFrameImage("bomb", "image/bomb.bmp", 100, 198, 2, 3, true, 0x00ff00);

	_balloon = new balloon;
	_balloon->init("balloon", 2);

	_player = new player;
	_player->init("target");
	_player->setBalloonMemoryLink(_balloon);

	return S_OK;
}

void gameStudy::release()
{
	_balloon->release();
	SAFE_DELETE(_balloon);

	_player->release();
	SAFE_DELETE(_player);

	gameNode::release();
}

void gameStudy::update()
{
	_balloon->update();
	_player->update();

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	_balloon->render();
	_player->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
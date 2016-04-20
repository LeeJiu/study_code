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
	IMAGEMANAGER->addImage("background2", "image/background_space.bmp", WINSIZEX, WINSIZEY, false, false);
	IMAGEMANAGER->addImage("bullet", "image/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "image/ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("battle", "image/battle.bmp", 0, 0, 1536, 79, 16, 1, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("carrier", "image/carrier.bmp", 0, 0, 3712, 116, 32, 1, true, 0xff00ff);

	_battle = new battle;
	_battle->init();

	_carrier = new carrier;
	_carrier->init();
	
	_battle->setCarrierMemoryLink(_carrier);
	_carrier->setBattleMemoryLink(_battle);

	return S_OK;
}

void gameStudy::release()
{
	SAFE_DELETE(_battle);
	SAFE_DELETE(_carrier);

	gameNode::release();
}

void gameStudy::update()
{
	_battle->update();
	_carrier->update();

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background2")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	_battle->render();
	_carrier->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



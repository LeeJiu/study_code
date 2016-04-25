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
	IMAGEMANAGER->addFrameImage("carrier", "image/carrier.bmp", 0, 0, 116 * 32, 116, 32, 1, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("phoenix", "image/phoenix.bmp", 0, 0, 5200, 189, 26, 1, true, 0xff00ff);

	//_ss = new starwarsScene;
	//_ss->init();

	_selScene = new selectScene;
	_selScene->init();

	return S_OK;
}

void gameStudy::release()
{
	//_ss->release();
	//SAFE_DELETE(_ss);
	
	SAFE_DELETE(_selScene);

	gameNode::release();
}

void gameStudy::update()
{
	//_ss->update();
	if (_selScene->selectShip() != NONE)
	{
		_gameStart = true;
		_ss = new starwarsScene;
		_ss->init(_selScene->selectShip());
		_selScene->setSelectNone();
	}

	if (_gameStart)
	{
		_ss->update();
	}
	else
	{
		_selScene->update();
	}

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background2")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	if (_gameStart)
	{
		_ss->render();
	}
	else
	{
		_selScene->render();
	}

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



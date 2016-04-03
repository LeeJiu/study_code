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

	IMAGEMANAGER->addImage("background", "background.bmp", WINSIZEX, WINSIZEY, false, false);
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("missile", "missile.bmp", 26, 124, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ufo", "ufo.bmp", 0, 0, 530, 32, 10, 1, true, RGB(255, 0, 255));


	_spaceShip = new spaceShip;
	_spaceShip->init();

	_enemyManager = new enemyManager;
	_enemyManager->init();

	_spaceShip->setEnemyManagerMemoryLink(_enemyManager);
	_enemyManager->setShipMemoryLink(_spaceShip);

	return S_OK;
}

void gameStudy::release()
{
	_spaceShip->release();
	SAFE_DELETE(_spaceShip);

	_enemyManager->release();
	SAFE_DELETE(_enemyManager);

	gameNode::release();
}

void gameStudy::update()
{
	_spaceShip->update();
	_enemyManager->update();

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	_enemyManager->render();
	_spaceShip->render();
	


	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



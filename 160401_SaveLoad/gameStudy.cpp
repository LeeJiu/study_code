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

	IMAGEMANAGER->addImage("background", "sakura_bg3.bmp", WINSIZEX, WINSIZEY, false, false);

	_player = new player;
	_player->init();

	_enemy = new enemy;
	_enemy->init();

	_player->setEnemyMemoryLink(_enemy);
	_enemy->setPlayerMemoryLink(_player);
	
	return S_OK;
}

void gameStudy::release()
{
	_player->release();
	SAFE_DELETE(_player);

	_enemy->release();
	SAFE_DELETE(_enemy);

	gameNode::release();
}

void gameStudy::update()
{
	_player->update();
	_enemy->update();

	gameNode::update();
}

void gameStudy::render()
{
	//����ۿ��� �ѷ��ش�
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background")->render(getMemDC());
	//======================
	//�� ���̿��� �׷��ָ� ��.

	_player->render();
	_enemy->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



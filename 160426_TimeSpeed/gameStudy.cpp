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

	IMAGEMANAGER->addImage("background2", "image/background_space.bmp", WINSIZEX, WINSIZEY, true, 0xff00ff);

	_ball = new ball;
	_ball->init();

	return S_OK;
}

void gameStudy::release()
{
	_ball->release();
	SAFE_DELETE(_ball);

	gameNode::release();
}

void gameStudy::update()
{
	_ball->update();

	gameNode::update();
}

void gameStudy::render()
{
	//����ۿ��� �ѷ��ش�
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background2")->render(getMemDC());
	//======================
	//�� ���̿��� �׷��ָ� ��.

	_ball->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



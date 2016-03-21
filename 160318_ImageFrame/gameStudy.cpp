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
	gameNode::init();

	_sakura = new image;
	_bg = new image;
	_sakura->init("sakura_walk.bmp", 336, 190, true, RGB(0, 255, 0));
	_bg->init("sakura_bg.bmp", WINSIZEX, WINSIZEY, false, false);
	imageFrame = direct = timeCount = 0;

	return S_OK;
}

void gameStudy::release()
{
	SAFE_RELEASE(_sakura);
	SAFE_RELEASE(_bg);
	SAFE_DELETE(_sakura);
	SAFE_DELETE(_bg);

	gameNode::release();
}

void gameStudy::update()
{
	timeCount++;

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) direct = 1;
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) direct = 0;

	walk(8);

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//이 사이에서 그려주면 됨.

	_bg->render(backDC, 0, 0);
	_sakura->alphaRender(backDC, CENTERX, CENTERY, 56 * imageFrame, 95 * direct, 56, 95, 255);

	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::walk(int frame)
{
	if (0 <= timeCount && timeCount <= 1 * frame)
	{
		imageFrame = 0;
	}
	else if (1 * frame + 1 <= timeCount && timeCount <= 2 * frame)
	{
		imageFrame = 1;
	}
	else if (2 * frame + 1 <= timeCount && timeCount <= 3 * frame)
	{
		imageFrame = 2;
	}
	else if (3 * frame + 1 <= timeCount && timeCount <= 4 * frame)
	{
		imageFrame = 3;
	}
	else if (4 * frame + 1 <= timeCount && timeCount <= 5 * frame)
	{
		imageFrame = 4;
	}
	else if (5 * frame + 1 <= timeCount && timeCount <= 6 * frame)
	{
		imageFrame = 5;
	}
	else if (6 * frame + 1 <= timeCount && timeCount <= 7 * frame)
	{
		timeCount = 0;
		imageFrame = 0;
	}
}


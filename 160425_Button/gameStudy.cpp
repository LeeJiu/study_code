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

	IMAGEMANAGER->addImage("background2", "image/background_space.bmp", WINSIZEX, WINSIZEY, false, false);

	IMAGEMANAGER->addFrameImage("battle", "image/battle.bmp", 0, 0, 1536, 79, 16, 1, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("carrier", "image/carrier.bmp", 0, 0, 116 * 32, 116, 32, 1, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("phoenix", "image/phoenix.bmp", 0, 0, 5200, 189, 26, 1, true, 0xff00ff);

	SCENEMANAGER->addScene("select", new selectScene);
	SCENEMANAGER->addScene("starwars", new starwarsScene);

	SCENEMANAGER->changeScene("select");

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	SCENEMANAGER->update();

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background2")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	SCENEMANAGER->render();

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



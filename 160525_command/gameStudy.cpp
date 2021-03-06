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

	IMAGEMANAGER->addFrameImage("kusanagi_idle", "image/kusanagi_idle.bmp", 780, 210, 10, 2, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("kusanagi_walk", "image/kusanagi_walk.bmp", 432, 232, 6, 2, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("kusanagi_run", "image/kusanagi_run.bmp", 721, 232, 7, 2, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("kusanagi_command1", "image/kusanagi_command1.bmp", 1870, 236, 17, 2, true, 0xff00ff);

	SCENEMANAGER->addScene("starwars", new starwarsScene);
	SCENEMANAGER->addScene("select", new selectScene);
	SCENEMANAGER->addScene("aStar", new aStar);
	SCENEMANAGER->addScene( "command", new commandScene );
	
	SCENEMANAGER->changeScene("command");

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
	//TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



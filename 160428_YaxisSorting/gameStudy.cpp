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
	
	_obj = new player;
	_obj->init(CENTERX, CENTERY + 50);

	_vObject.push_back(_obj);

	for (int i = 0; i < 20; ++i)
	{
		_obj = new enemy;
		_obj->init(RND->getFromIntTo(50, WINSIZEX - 50), RND->getFromIntTo(CENTERY + 50, WINSIZEY - 50));
		_vObject.push_back(_obj);
	}

	return S_OK;
}

void gameStudy::release()
{
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->release();
		SAFE_DELETE(*_viObject);
	}
	_vObject.clear();

	gameNode::release();
}

void gameStudy::update()
{
	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->update();
	}

	gameNode::update();
}

void gameStudy::render()
{
	//백버퍼에서 뿌려준다
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->findImage("background")->render(getMemDC());
	//======================
	//이 사이에서 그려주면 됨.

	std::sort(_vObject.begin(), _vObject.end(), gameStudy::Compare);

	for (_viObject = _vObject.begin(); _viObject != _vObject.end(); ++_viObject)
	{
		(*_viObject)->render();
	}

	//======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}



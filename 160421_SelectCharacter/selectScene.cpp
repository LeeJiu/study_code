#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{
}

HRESULT selectScene::init()
{
	_battle.x = WINSIZEX / 4;
	_carrier.x = WINSIZEX / 4 * 2;
	_phoenix.x = WINSIZEX / 4 * 3;
	_battle.y = _carrier.y = _phoenix.y = CENTERY;

	_battle.angle = _carrier.angle = _phoenix.angle = 0.f;
	
	_battle.image = IMAGEMANAGER->findImage("battle");
	_carrier.image = IMAGEMANAGER->findImage("carrier");
	_phoenix.image = IMAGEMANAGER->findImage("phoenix");

	_battle.rc = RectMakeCenter(_battle.x, _battle.y, _battle.image->getFrameWidth(), _battle.image->getFrameHeight());
	_carrier.rc = RectMakeCenter(_carrier.x, _carrier.y, _carrier.image->getFrameWidth(), _carrier.image->getFrameHeight());
	_phoenix.rc = RectMakeCenter(_phoenix.x, _phoenix.y, _phoenix.image->getFrameWidth(), _phoenix.image->getFrameHeight());

	_battle.image->setFrameX(_battle.angle / PI8);
	_carrier.image->setFrameX(_carrier.angle / PI16);
	_phoenix.image->setFrameX(_phoenix.angle / (PI / 13));

	_select = NONE;

	return S_OK;
}

void selectScene::release()
{
}

void selectScene::update()
{
	if (PtInRect(&_battle.rc, _ptMouse))
	{
		_battle.angle += 0.06f;
		if (_battle.angle > PI2) _battle.angle -= PI2;
		_battle.image->setFrameX(_battle.angle / PI8);
		
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			_select = BATTLE;
	}
	if (PtInRect(&_carrier.rc, _ptMouse))
	{
		_carrier.angle += 0.06f;
		if (_carrier.angle > PI2) _carrier.angle -= PI2;
		_carrier.image->setFrameX(_carrier.angle / PI16);
		
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			_select = CARRIER;
	}
	if (PtInRect(&_phoenix.rc, _ptMouse))
	{
		_phoenix.angle += 0.06f;
		if (_phoenix.angle > PI2) _phoenix.angle -= PI2;
		_phoenix.image->setFrameX(_phoenix.angle / (PI / 13));
		
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			_select = PHOENIX;
	}
}

void selectScene::render()
{
	_battle.image->frameRender(getMemDC(), _battle.rc.left, _battle.rc.top);
	_carrier.image->frameRender(getMemDC(), _carrier.rc.left, _carrier.rc.top);
	_phoenix.image->frameRender(getMemDC(), _phoenix.rc.left, _phoenix.rc.top);
}

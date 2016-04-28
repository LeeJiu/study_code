#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_pt.x = CENTERX;
	_pt.y = WINSIZEY - 72;

	_player = RectMakeCenter(_pt.x, _pt.y, 70, 100);

	_harpoon.image = new image;
	_harpoon.image->init("image/harpoon.bmp", 16, 600, true, 0xff00ff);
	_harpoon.fire = false;

	return S_OK;
}

void player::release()
{
	_harpoon.image->release();
	SAFE_DELETE(_harpoon.image);
}

void player::update()
{
	keyControl();
	shoot();
}

void player::render()
{
	_harpoon.image->render(getMemDC(), _harpoon.rc.left, _harpoon.rc.top, 0, 0, _harpoon.image->getWidth(), _stretchHeight);
	if(!_isDead)
		Rectangle(getMemDC(), _player.left, _player.top, _player.right, _player.bottom);
}

void player::keyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_player.left > 18)
			_pt.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_player.right < WINSIZEX - 18)
			_pt.x += 3;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_harpoon.fire) return;
	
		_harpoon.fire = true;
		_harpoon.pt.x = _pt.x - _harpoon.image->getWidth() / 2;
		_harpoon.pt.y = WINSIZEY - 22;
	}

	_player = RectMakeCenter(_pt.x, _pt.y, 70, 100);
}

void player::shoot()
{
	if (!_harpoon.fire) return;

	_stretchHeight += 3;
	_harpoon.pt.y -= 3;

	if (_harpoon.pt.y <= 22)
	{
		_harpoon.fire = false;
		_stretchHeight = 0;
	}

	_harpoon.rc = RectMake(_harpoon.pt.x, _harpoon.pt.y, _harpoon.image->getWidth(), _stretchHeight);
}

void player::fireoff()
{
	_harpoon.fire = false;
	_stretchHeight = 0;
}

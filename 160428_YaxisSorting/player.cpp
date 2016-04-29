#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init(int x, int y)
{
	IMAGEMANAGER->addFrameImage("shinchan_stand", "image/shinchan_stand.bmp", 40, 80, 1, 2, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("shinchan_walk", "image/shinchan_walk.bmp", 200, 80, 5, 2, true, 0xff00ff);

	_player.image = IMAGEMANAGER->findImage("shinchan_stand");
	_player.state = STAND;
	_player.x = x;
	_player.y = y;
	_player.rc = RectMakeCenter(_player.x, _player.y, 
		_player.image->getFrameWidth(), _player.image->getFrameHeight());

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	keyControl();
	move();
	setImage();
}

void player::render()
{
	_player.image->frameRender(getMemDC(), _player.rc.left, _player.rc.top, _curFrameX, _curFrameY);
}

void player::keyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_player.x - _player.image->getFrameWidth() / 2 > 0)
		{
			if (_player.isRight)
				_player.isRight = false;
			_player.state = WALK;
			_player.x -= 3;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_player.x + _player.image->getFrameWidth() / 2 < WINSIZEX)
		{
			if (!_player.isRight)
				_player.isRight = true;
			_player.state = WALK;
			_player.x += 3;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_player.y - _player.image->getFrameHeight() / 2 > CENTERY)
		{
			_player.state = WALK;
			_player.y -= 3;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_player.y + _player.image->getFrameHeight() / 2 < WINSIZEY)
		{
			_player.state = WALK;
			_player.y += 3;
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT)
		|| KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_DOWN)) 
		_player.state = STAND;
}

void player::move()
{
	_player.rc = RectMakeCenter(_player.x, _player.y,
		_player.image->getFrameWidth(), _player.image->getFrameHeight());
}

void player::setImage()
{
	switch (_player.state)
	{
	case STAND:
		_player.image = IMAGEMANAGER->findImage("shinchan_stand");
		setFrame();
		break;

	case WALK:
		_player.image = IMAGEMANAGER->findImage("shinchan_walk");
		setFrame();
		break;
	}
}

void player::setFrame()
{
	if (_player.isRight)
	{
		_curFrameY = 0;
		_player.image->setFrameY(_curFrameY);
		_count++;
		if (_count % 10 == 0)
		{
			_curFrameX++;
			if (_curFrameX > _player.image->getMaxFrameX())
				_curFrameX = 0;

			_player.image->setFrameX(_curFrameX);
		}
	}
	else
	{
		_curFrameY = 1;
		_player.image->setFrameY(_curFrameY);
		_count++;
		if (_count % 10 == 0)
		{
			_curFrameX--;
			if (_curFrameX < 0)
				_curFrameX = _player.image->getMaxFrameX();

			_player.image->setFrameX(_curFrameX);
		}
	}
}

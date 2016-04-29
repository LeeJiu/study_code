#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init(int x, int y)
{
	_enemy.image = new image;
	_enemy.image->init("image/monster_stand.bmp", 53, 136, 1, 2, true, 0xff00ff);
	_enemy.state = STAND;
	_enemy.x = x;
	_enemy.y = y;
	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y,
		_enemy.image->getFrameWidth(), _enemy.image->getFrameHeight());

	return S_OK;
}

void enemy::release()
{
	_enemy.image->release();
	SAFE_DELETE(_enemy.image);
}

void enemy::update()
{
	move();
	setImage();
}

void enemy::render()
{
	_enemy.image->frameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _curFrameX, _curFrameY);
}

void enemy::move()
{
	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y,
		_enemy.image->getFrameWidth(), _enemy.image->getFrameHeight());
}

void enemy::setImage()
{
	switch (_enemy.state)
	{
	case STAND:
		_enemy.image->init("image/monster_stand.bmp", 53, 136, 1, 2, true, 0xff00ff);
		setFrame();
		break;

	case WALK:
		_enemy.image->init("image/monster_walk.bmp", 318, 136, 6, 2, true, 0xff00ff);
		setFrame();
		break;
	}
}

void enemy::setFrame()
{
	if (_enemy.isRight)
	{
		_curFrameY = 0;
		_enemy.image->setFrameY(_curFrameY);
		_count++;
		if (_count % 10 == 0)
		{
			_curFrameX++;
			if (_curFrameX > _enemy.image->getMaxFrameX())
				_curFrameX = 0;

			_enemy.image->setFrameX(_curFrameX);
		}
	}
	else
	{
		_curFrameY = 1;
		_enemy.image->setFrameY(_curFrameY);
		_count++;
		if (_count % 10 == 0)
		{
			_curFrameX--;
			if (_curFrameX < 0)
				_curFrameX = _enemy.image->getMaxFrameX();

			_enemy.image->setFrameX(_curFrameX);
		}
	}
}

#include "stdafx.h"
#include "balloon.h"


balloon::balloon()
{
}


balloon::~balloon()
{
}

HRESULT balloon::init(const char* imageName, int balloonMax)
{
	_balloonMax = balloonMax;

	_isRight = true;

	_gravity = 0.01f;

	_count = _currentFrameX = _currentFrameY = 0;

	//총알을 초기화해서 넣자
	for (int i = 0; i < _balloonMax; ++i)
	{
		tagBalloon balloon;
		ZeroMemory(&balloon, sizeof(tagBalloon));

		balloon.image = IMAGEMANAGER->findImage(imageName);
		balloon.fire = false;
		balloon.speed = 0;
		balloon.gravityPw = 1.f;
		balloon.angle = 0;
		balloon.x = 0;
		balloon.y = 0;
		balloon.rc = RectMakeCenter(balloon.x, balloon.y,
			balloon.image->getFrameWidth(),
			balloon.image->getFrameHeight() / 2);

		_vBalloon.push_back(balloon);
	}

	return S_OK;
}

void balloon::release()
{
	for (_viBalloon = _vBalloon.begin(); _viBalloon != _vBalloon.end(); )
	{
		_viBalloon = _vBalloon.erase(_viBalloon);
	}
}

void balloon::update()
{
	_time += TIMEMANAGER->getElapsedTime();

	//3초마다 쏘자
	if (_time > 3)
	{
		fire();
		_time = 0;
	}

	move();
	setFrame();
}

void balloon::render()
{
	for (_viBalloon = _vBalloon.begin(); _viBalloon != _vBalloon.end(); ++_viBalloon)
	{
		if (!_viBalloon->fire) continue;

		_viBalloon->image->frameRender(getMemDC(), _viBalloon->rc.left, _viBalloon->rc.top, _viBalloon->image->getFrameX(), _viBalloon->image->getFrameY());
	}
}

void balloon::fire()
{
	float angle, x, y;

	if (_isRight)
	{
		x = WINSIZEX;
		y = RND->getFromIntTo(CENTERY - 50, CENTERY + 50);
		angle = RND->getFromFloatTo(PI / 4 * 3, PI);
		_isRight = false;
	}
	else
	{
		x = 0;
		y = RND->getFromIntTo(CENTERY - 50, CENTERY + 50);
		angle = RND->getFromFloatTo(0, PI / 4);
		_isRight = true;
	}

	for (_viBalloon = _vBalloon.begin(); _viBalloon != _vBalloon.end(); ++_viBalloon)
	{
		if (_viBalloon->fire) continue;

		_viBalloon->fire = true;
		_viBalloon->type = (BALLOONTYPE)RND->getInt(3);
		_viBalloon->x = x;
		_viBalloon->y = y;
		_viBalloon->speed = 5.f;
		_viBalloon->angle = angle;
		_viBalloon->gravityPw = 1.f;
		_viBalloon->rc = RectMakeCenter(_viBalloon->x, _viBalloon->y,
			_viBalloon->image->getFrameWidth(),
			_viBalloon->image->getFrameHeight() / 2);

		break;
	}
}

void balloon::move()
{
	//벡터에 담아둔 녀석들 움직이자
	for (_viBalloon = _vBalloon.begin(); _viBalloon != _vBalloon.end(); ++_viBalloon)
	{
		if (!_viBalloon->fire) continue;
		
		_viBalloon->gravityPw -= _gravity;

		_viBalloon->x += cosf(_viBalloon->angle) * _viBalloon->speed;
		_viBalloon->y += -sinf(_viBalloon->angle) * _viBalloon->speed * _viBalloon->gravityPw;

		_viBalloon->rc = RectMakeCenter(_viBalloon->x, _viBalloon->y,
			_viBalloon->image->getFrameWidth()/2,
			_viBalloon->image->getFrameHeight()/2);

		//화면 밖으로 나가면 총알 끄자
		if (_viBalloon->rc.right < 0 || _viBalloon->rc.left > WINSIZEX)
		{
			_viBalloon->fire = false;
		}
	}
}

void balloon::setFrame()
{
	_count++;

	if (_count % 5 == 0)
	{
		for (_viBalloon = _vBalloon.begin(); _viBalloon != _vBalloon.end(); ++_viBalloon)
		{
			if (!_viBalloon->fire) continue;
			
			switch (_viBalloon->type)
			{
			case ORIGINAL:
				_currentFrameY = 0;
				break;
			case DOUBLE:
				_currentFrameY = 1;
				break;
			case BOMB:
				_currentFrameY = 2;
				break;
			}
			_viBalloon->image->setFrameY(_currentFrameY);

			_currentFrameX++;
			if (_currentFrameX > _viBalloon->image->getMaxFrameX()) _currentFrameX = 0;
			_viBalloon->image->setFrameX(_currentFrameX);
			
			if (_viBalloon->bomb && _currentFrameX == _viBalloon->image->getMaxFrameX())
			{
				_viBalloon->bomb = false;
				_viBalloon->fire = false;
				_viBalloon->image = IMAGEMANAGER->findImage("balloon");
			}
		}
	}
}

void balloon::setBombImage(const char * imageName, int arrNum)
{
	_viBalloon = (_vBalloon.begin() + arrNum);
	_viBalloon->image = IMAGEMANAGER->findImage(imageName);
}
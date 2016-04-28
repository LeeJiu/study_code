#include "stdafx.h"
#include "ball.h"
#include "player.h"


ball::ball()
{
}


ball::~ball()
{
}

HRESULT ball::init()
{
	tagBall ball;
	ZeroMemory(&ball, sizeof(tagBall));
	ball.image = new image;
	ball.image->init("image/ball1.bmp", 96, 96, true, 0xff00ff);
	ball.x = 100;
	ball.y = CENTERY;
	ball.radius = ball.image->getWidth() / 2;
	ball.isRight = true;
	ball.speed = 0.f;
	ball.rc = RectMakeCenter(ball.x, ball.y, ball.image->getWidth(), ball.image->getHeight());
	ball.deadCnt = 3;

	_vBall.push_back(ball);

	_gravity = 0.2f;

	return S_OK;
}

void ball::release()
{
	for (_viBall = _vBall.begin(); _viBall != _vBall.end(); )
	{
		SAFE_DELETE(_viBall->image);
		_viBall = _vBall.erase(_viBall);
	}
}

void ball::update()
{
	move();
	collision();
	splitBall();
}

void ball::render()
{
	for (_viBall = _vBall.begin(); _viBall != _vBall.end(); ++_viBall)
	{
		if (_viBall->isDead) continue;
		
		_viBall->image->render(getMemDC(), _viBall->rc.left, _viBall->rc.top);
	}
}

void ball::move()
{
	for (_viBall = _vBall.begin(); _viBall != _vBall.end(); ++_viBall)
	{
		_viBall->y -= _viBall->speed;
		_viBall->speed -= _gravity;
		
		if (_viBall->isRight)
		{
			_viBall->x += 2.f;
		}
		else if (!_viBall->isRight)
		{
			_viBall->x -= 2.f;
		}

		if (_viBall->rc.left < 18)
		{
			_viBall->isRight = true;
		}
		else if (_viBall->rc.right > WINSIZEX - 18)
		{
			_viBall->isRight = false;
		}
		else if (_viBall->rc.bottom > WINSIZEY - 35)
		{
			switch (_viBall->deadCnt)
			{
			case 0:
				_viBall->speed = 3.f;
				break;
			case 1:
				_viBall->speed = 5.f;
				break;
			case 2:
				_viBall->speed = 8.f;
				break;
			case 3:
				_viBall->speed = 11.f;
				break;
			}
		}

		_viBall->rc = RectMakeCenter(_viBall->x, _viBall->y, _viBall->image->getWidth(), _viBall->image->getHeight());
	}
}

void ball::collision()
{
	for (_viBall = _vBall.begin(); _viBall != _vBall.end(); ++_viBall)
	{
		if (_viBall->isDead) continue;

		if (IntersectRect(&RectMake(0, 0, 0, 0), &_viBall->rc, &_player->getPlayerRect()))
		{
			if (_viBall->x < _player->getPlayerRect().left
				&& _viBall->y < _player->getPlayerRect().top)
			{
				float dist = MY_UTIL::getDistance(_viBall->x, _viBall->y, 
					_player->getPlayerRect().left, _player->getPlayerRect().top);

				if (dist < _viBall->radius)
				{
					_player->dead();
				}
			}
			else if (_viBall->x > _player->getPlayerRect().right
				&& _viBall->y < _player->getPlayerRect().top)
			{
				float dist = MY_UTIL::getDistance(_viBall->x, _viBall->y,
					_player->getPlayerRect().right, _player->getPlayerRect().top);

				if (dist < _viBall->radius)
				{
					_player->dead();
				}
			}
			else
			{
				_player->dead();
			}
		}
	}
}

void ball::splitBall()
{
	if (!_player->getFire()) return;

	for (_viBall = _vBall.begin(); _viBall != _vBall.end(); ++_viBall)
	{
		if (_viBall->isDead) continue;

		if (IntersectRect(&RectMake(0, 0, 0, 0), &_viBall->rc, &_player->getHarpoonRect()))
		{
			if (_viBall->x < _player->getHarpoonRect().left
				&& _viBall->y < _player->getHarpoonRect().top)
			{
				float dist = MY_UTIL::getDistance(_viBall->x, _viBall->y,
					_player->getHarpoonRect().left, _player->getHarpoonRect().top);

				if (dist < _viBall->radius)
				{
					_player->fireoff();
					_viBall->isDead = true;
					increaseBall(_viBall->x, _viBall->y, _viBall->deadCnt);
					break;
				}
			}
			else if (_viBall->x > _player->getHarpoonRect().right
				&& _viBall->y < _player->getHarpoonRect().top)
			{
				float dist = MY_UTIL::getDistance(_viBall->x, _viBall->y,
					_player->getHarpoonRect().right, _player->getHarpoonRect().top);

				if (dist < _viBall->radius)
				{
					_player->fireoff();
					_viBall->isDead = true;
					increaseBall(_viBall->x, _viBall->y, _viBall->deadCnt);
					break;
				}
			}
			else
			{
				_player->fireoff();
				_viBall->isDead = true;
				increaseBall(_viBall->x, _viBall->y, _viBall->deadCnt);
				break;
			}
		}
	}
}

void ball::increaseBall(float x, float y, int deadCnt)
{
	switch (deadCnt)
	{
	case 0:
		return;
	case 1:
	{
		tagBall ball[2];
		for (int i = 0; i < 2; ++i)
		{
			ZeroMemory(&ball[i], sizeof(tagBall));
			ball[i].image = new image;
			ball[i].image->init("image/ball4.bmp", 14, 14, true, 0xff00ff);
			ball[i].x = x;
			ball[i].y = y;
			ball[i].radius = ball[i].image->getWidth() / 2;
			ball[i].rc = RectMakeCenter(ball[i].x, ball[i].y, ball[i].image->getWidth(), ball[i].image->getHeight());
			ball[i].deadCnt = 0;

			if (i == 0)
				ball[i].isRight = true;
			else
				ball[i].isRight = false;

			_vBall.push_back(ball[i]);
		}
	}
	break; 
	case 2:
	{
		tagBall ball[2];
		for (int i = 0; i < 2; ++i)
		{
			ZeroMemory(&ball[i], sizeof(tagBall));
			ball[i].image = new image;
			ball[i].image->init("image/ball3.bmp", 32, 32, true, 0xff00ff);
			ball[i].x = x;
			ball[i].y = y;
			ball[i].radius = ball[i].image->getWidth() / 2;
			ball[i].rc = RectMakeCenter(ball[i].x, ball[i].y, ball[i].image->getWidth(), ball[i].image->getHeight());
			ball[i].deadCnt = 1;

			if (i == 0)
				ball[i].isRight = true;
			else
				ball[i].isRight = false;

			_vBall.push_back(ball[i]);
		}
	}
	break;
	case 3:
	{
		tagBall ball[2];
		for (int i = 0; i < 2; ++i)
		{
			ZeroMemory(&ball[i], sizeof(tagBall));
			ball[i].image = new image;
			ball[i].image->init("image/ball2.bmp", 64, 64, true, 0xff00ff);
			ball[i].x = x;
			ball[i].y = y;
			ball[i].radius = ball[i].image->getWidth() / 2;
			ball[i].rc = RectMakeCenter(ball[i].x, ball[i].y, ball[i].image->getWidth(), ball[i].image->getHeight());
			ball[i].deadCnt = 2;
			
			if (i == 0)
				ball[i].isRight = true;
			else
				ball[i].isRight = false;
			
			_vBall.push_back(ball[i]);
		}
	}
	break;
	}
}

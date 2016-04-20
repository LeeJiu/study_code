#include "stdafx.h"
#include "ball.h"
#include "playerBar.h"
#include "block.h"


ball::ball()
{
}


ball::~ball()
{
}

HRESULT ball::init()
{
	_ball.x = CENTERX;
	_ball.y = CENTERY;
	_ball.radius = 10.f;
	_ball.angle = PI / 2 * 3;
	_ball.speed = 5.f;
	_ball.coll = RectMakeCenter(_ball.x, _ball.y, _ball.radius * 2, _ball.radius * 2);

	return S_OK;
}

void ball::release()
{
}

void ball::update()
{
	move();
	barCollision();
	blockCollision();
}

void ball::render()
{
	EllipseMake(getMemDC(), _ball.x, _ball.y, _ball.radius * 2, _ball.radius * 2);
}

void ball::move()
{
	if (IntersectRect(&RectMake(0, 0, 0, 0), &RectMake(0, 0, WINSIZEX, WINSIZEY), &_ball.coll))
	{
		if (_ball.coll.right > WINSIZEX || _ball.coll.left < 0)
		{
			_ball.angle = PI - _ball.angle;
		}
		else if (_ball.coll.top < 0)
		{
			_ball.angle = PI2 - _ball.angle;
		}
	}

	_ball.x += cosf(_ball.angle) * _ball.speed;
	_ball.y += -sinf(_ball.angle) * _ball.speed;
	_ball.coll = RectMakeCenter(_ball.x, _ball.y, _ball.radius * 2, _ball.radius * 2);
}

void ball::barCollision()
{
	RECT barRect = _bar->getRect();
	if (IntersectRect(&RectMake(0, 0, 0, 0), &_ball.coll, &barRect))
	{
		if (_ball.x < barRect.left && _ball.y < barRect.top)
		{
			float distance = MY_UTIL::getDistance(_ball.x, _ball.y, barRect.left, barRect.top);
			if (distance < _ball.radius)
			{
				_ball.angle = atan2f(barRect.top - _ball.y, barRect.left - _ball.x);
			}
		}
		else if (_ball.x > barRect.right && _ball.y < barRect.top)
		{
			float distance = MY_UTIL::getDistance(_ball.x, _ball.y, barRect.right, barRect.top);
			if (distance < _ball.radius)
			{
				_ball.angle = atan2f(barRect.top - _ball.y, barRect.right - _ball.x);
			}
		}
		else if (_ball.x > barRect.right && _ball.y > barRect.bottom)
		{
			float distance = MY_UTIL::getDistance(_ball.x, _ball.y, barRect.right, barRect.bottom);
			if (distance < _ball.radius)
			{
				_ball.angle = atan2f(barRect.bottom - _ball.y, barRect.right - _ball.x);
			}
		}
		else if (_ball.x < barRect.left && _ball.y > barRect.bottom)
		{
			float distance = MY_UTIL::getDistance(_ball.x, _ball.y, barRect.left, barRect.bottom);
			if (distance < _ball.radius)
			{
				_ball.angle = atan2f(barRect.bottom - _ball.y, barRect.left - _ball.x);
			}
		}
		else
		{
			if (_ball.x >= barRect.left && _ball.x <= barRect.right)
				_ball.angle = PI2 - _ball.angle;
			else
				_ball.angle = PI - _ball.angle;
		}
	}
}

void ball::blockCollision()
{
	for (int i = 0; i < _block->getVBlock().size(); ++i)
	{
		if (_block->getVBlock()[i].broken) continue;

		RECT block = _block->getVBlock()[i].rc;

		if (IntersectRect(&RectMake(0, 0, 0, 0), &_ball.coll, &block))
		{
			if (_ball.x < block.left && _ball.y < block.top)
			{
				float distance = MY_UTIL::getDistance(_ball.x, _ball.y, block.left, block.top);
				if (distance < _ball.radius)
				{
					_ball.angle = atan2f(block.top - _ball.y, block.left - _ball.x);
					_block->getVBlock()[i].broken = true;
				}
			}
			else if (_ball.x > block.right && _ball.y < block.top)
			{
				float distance = MY_UTIL::getDistance(_ball.x, _ball.y, block.right, block.top);
				if (distance < _ball.radius)
				{
					_ball.angle = atan2f(block.top - _ball.y, block.right - _ball.x);
					_block->getVBlock()[i].broken = true;
				}
			}
			else if (_ball.x > block.right && _ball.y > block.bottom)
			{
				float distance = MY_UTIL::getDistance(_ball.x, _ball.y, block.right, block.bottom);
				if (distance < _ball.radius)
				{
					_ball.angle = atan2f(block.bottom - _ball.y, block.right - _ball.x);
					_block->getVBlock()[i].broken = true;
				}
			}
			else if (_ball.x < block.left && _ball.y > block.bottom)
			{
				float distance = MY_UTIL::getDistance(_ball.x, _ball.y, block.left, block.bottom);
				if (distance < _ball.radius)
				{
					_ball.angle = atan2f(block.bottom - _ball.y, block.left - _ball.x);
					_block->getVBlock()[i].broken = true;
				}
			}
			else
			{
				_ball.angle = PI2 - _ball.angle;
				_block->getVBlock()[i].broken = true;
			}
		}
	}
}

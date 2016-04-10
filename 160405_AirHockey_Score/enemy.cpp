#include "stdafx.h"
#include "enemy.h"
#include "ball.h"

enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	_enemy.radius = 25.f;
	_enemy.angle = 0.f;
	_enemy.image = IMAGEMANAGER->addImage("enemy", "image/enemy.bmp", 50, 50, true, 0x00ff00);
	_enemy.x = CENTERX - _enemy.image->getWidth()/2;
	_enemy.y = 100 - _enemy.image->getHeight()/2;

	_goal = RectMakeCenter(CENTERX, WINSIZEY - 20, 140, 40);

	_score = 0;

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	if (_enemy.x < _ball->getX() - 25)
		_enemy.x += 3.f;
	else if (_enemy.x > _ball->getX() + 25)
		_enemy.x -= 3.f;

	//공이 적진에 있을 때
	if (_ball->getY() + _ball->getRadius() * 2 < CENTERY
		&& _ball->getY() > 30)
	{
		//적이 공의 윗쪽일 때
		if (_enemy.y + _enemy.radius < _ball->getY())
		{
			_enemy.y += 3.f;
		}
		//적이 공의 아랫쪽일 때
		else if (_enemy.y > _ball->getY() + _ball->getRadius())
		{
			_enemy.y -= 3.f;
		}
	}

	collision();
	goal();
}

void enemy::render()
{
	IMAGEMANAGER->render("enemy", getMemDC(), _enemy.x, _enemy.y);

	char str[128];
	sprintf_s(str, "enemy : %d", _score);
	TextOut(getMemDC(), 10, CENTERY - 30, str, strlen(str));

	Rectangle(getMemDC(), _goal.left, _goal.top, _goal.right, _goal.bottom);
}

void enemy::collision()
{
	float distance = MY_UTIL::getDistance(_enemy.x, _enemy.y, _ball->getX(), _ball->getY());

	if (distance < _enemy.radius + _ball->getRadius())
	{
		float angle = MY_UTIL::getAngle(_enemy.x, _enemy.y, _ball->getX(), _ball->getY());
		_ball->setAngle(angle);
		_ball->setSpeed(10.f);
	}
}

void enemy::goal()
{
	if (IntersectRect(&_tmp, &_goal,
		&RectMake(_ball->getX(), _ball->getY(), _ball->getRadius() * 2, _ball->getRadius() * 2)))
	{
		float height = _tmp.bottom - _tmp.top;
		if (height > _ball->getRadius())
		{
			_score++;
			_ball->init();
			_enemy.x = CENTERX - _enemy.image->getWidth() / 2;
			_enemy.y = 100 - _enemy.image->getHeight() / 2;
		}
	}
}

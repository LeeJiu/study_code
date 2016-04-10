#include "stdafx.h"
#include "ball.h"


ball::ball()
{
}


ball::~ball()
{
}

HRESULT ball::init()
{
	_ball.radius = 25.f;
	_ball.angle = 0.f;
	_ball.speed = 0.f;

	_ball.image = IMAGEMANAGER->addImage("ball", "image/ball.bmp", 50, 50, true, 0x00ff00);

	_ball.x = CENTERX - _ball.image->getWidth()/2;
	_ball.y = CENTERY - _ball.image->getHeight()/2;

	return S_OK;
}

void ball::release()
{
}

void ball::update()
{
	collision();
	_ball.x += cosf(_ball.angle) * _ball.speed;
	_ball.y += -sinf(_ball.angle) * _ball.speed;
	if(_ball.speed > 0)
		_ball.speed -= .1f;
	else if (_ball.speed <= 0)
		_ball.speed = 0.f;
}

void ball::render()
{
	IMAGEMANAGER->render("ball", getMemDC(), _ball.x, _ball.y);
	
	//Rectangle(getMemDC(), _ball.x, _ball.y, _ball.x+10, _ball.y+10);
	
	char str[128];
	sprintf_s(str, "x: %.3f, y: %.3f", _ball.x, _ball.y);
	TextOut(getMemDC(), _ball.x, _ball.y, str, strlen(str));
}

void ball::collision()
{
	if (_ball.x < 0)
	{
		_ball.angle = PI - _ball.angle;
		_ball.speed += .2f;
	}
	else if (_ball.x + _ball.radius * 2 > WINSIZEX)
	{
		_ball.angle = PI - _ball.angle;
		_ball.speed += .2f;
	}
	else if (_ball.y < 0)
	{
		_ball.angle = PI2 - _ball.angle;
		_ball.speed += .2f;
	}
	else if (_ball.y + _ball.radius * 2 > WINSIZEY)
	{
		_ball.angle = PI2 - _ball.angle;
		_ball.speed += .2f;
	}
}

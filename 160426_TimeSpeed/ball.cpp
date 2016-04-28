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
	_ball = IMAGEMANAGER->addImage("ball", "image/ball.bmp", 60, 60, true, 0xff00ff);
	_x = CENTERX;
	_y = CENTERY;
	_radius = _ball->getFrameWidth() / 2;
	_rc = RectMakeCenter(_x, _y, _radius * 2, _radius * 2);
	_angle = _speed = _distance = _elapsedTime = 0.f;

	_time = 3.f;

	return S_OK;
}

void ball::release()
{
}

void ball::update()
{
	

	keyControl();
	move();
}

void ball::render()
{
	_ball->render(getMemDC(), _rc.left, _rc.top);
}

void ball::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_saveX = _ptMouse.x;
		_saveY = _ptMouse.y;
		_saveDist = MY_UTIL::getDistance(_x, _y, _saveX, _saveY);
		_angle = MY_UTIL::getAngle(_x, _y, _ptMouse.x, _ptMouse.y);
		_speed = (_saveDist / _time) * TIMEMANAGER->getElapsedTime();
	}
}

void ball::move()
{
	_distance = MY_UTIL::getDistance(_x, _y, _saveX, _saveY);
	
	_x += cosf(_angle) * _speed;
	_y += -sinf(_angle) * _speed;
	if ((_distance / _time * _speed) <= 1)
		_speed = 0.f;

	_rc = RectMakeCenter(_x, _y, _radius * 2, _radius * 2);
}

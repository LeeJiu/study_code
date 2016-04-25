#include "stdafx.h"
#include "ship.h"


ship::ship()
{
}


ship::~ship()
{
}

HRESULT ship::init(const char* imageName, float angle, float maxSpd)
{
	_image = IMAGEMANAGER->findImage(imageName);
	_x = CENTERX;
	_y = CENTERY;
	_angle = angle;
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	_speed = 0.f;
	_maxSpd = maxSpd;
	_radius = _image->getFrameWidth() / 2;
	return S_OK;
}

void ship::release()
{
}

void ship::update()
{
	keyControl();
	move();
}

void ship::render()
{
	draw();
}

void ship::draw()
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top);

	char str[128];
	sprintf_s(str, "%dµµ %3.2f", int(_angle * 180 / PI), _speed);
	TextOut(getMemDC(), _rc.left, _rc.top - 15, str, strlen(str));
}

void ship::keyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _angle += 0.06f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_angle -= 0.06f;
		if (_angle < 0) _angle += PI2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_speed += 0.02f;
		if (_speed > _maxSpd)
			_speed = _maxSpd;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_speed -= 0.02f;
		if (_speed < (_maxSpd * -1))
			_speed = _maxSpd * -1;
	}
}

void ship::move()
{
	int frame;
	float angle;

	angle = _angle + PI16;
	if (angle > PI2) _angle -= PI2;

	frame = int(_angle / PI8);
	_image->setFrameX(frame);

	_x += cosf(_angle) * _speed;
	_y += -sinf(_angle) * _speed;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

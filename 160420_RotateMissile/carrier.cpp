#include "stdafx.h"
#include "carrier.h"
#include "battle.h"


carrier::carrier()
{
}


carrier::~carrier()
{
}

HRESULT carrier::init()
{
	_carrier.carrier = IMAGEMANAGER->findImage("carrier");
	_carrier.x = WINSIZEX / 6 * 5;
	_carrier.y = CENTERY;
	_carrier.angle = PI;
	_carrier.rc = RectMakeCenter(_carrier.x, _carrier.y,
		_carrier.carrier->getFrameWidth(), _carrier.carrier->getFrameHeight());
	_carrier.speed = 0.0f;

	return S_OK;
}

void carrier::release()
{
}

void carrier::update()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_carrier.angle += 0.06f;
		if (_carrier.angle > PI * 2) _carrier.angle -= PI * 2;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_carrier.angle -= 0.06f;
		if (_carrier.angle < 0) _carrier.angle += PI * 2;
	}
	if (KEYMANAGER->isStayKeyDown('W')) _carrier.speed += 0.02f;
	if (KEYMANAGER->isStayKeyDown('S')) _carrier.speed -= 0.02f;

	int frame;
	float angle;

	frame = int(_carrier.angle / PI16);		// PI * 2 / 32
	_carrier.carrier->setFrameX(frame);

	_carrier.x += cosf(_carrier.angle) * _carrier.speed;
	_carrier.y += -sinf(_carrier.angle) * _carrier.speed;

	_carrier.rc = RectMakeCenter(_carrier.x, _carrier.y,
		_carrier.carrier->getFrameWidth(), _carrier.carrier->getFrameHeight());
}

void carrier::render()
{
	_carrier.carrier->frameRender(getMemDC(), _carrier.rc.left, _carrier.rc.top);

	char str[128];
	sprintf_s(str, "%dµµ %3.2f", int(_carrier.angle * 180 / PI), _carrier.speed);
	TextOut(getMemDC(), _carrier.rc.left, _carrier.rc.top - 20, str, strlen(str));

	sprintf_s(str, "%d frame", _carrier.carrier->getFrameX());
	TextOut(getMemDC(), _carrier.rc.right, _carrier.rc.top - 20, str, strlen(str));
}

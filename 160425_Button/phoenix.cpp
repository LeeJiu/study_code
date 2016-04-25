#include "stdafx.h"
#include "phoenix.h"


phoenix::phoenix()
{
}


phoenix::~phoenix()
{
}

HRESULT phoenix::init(const char * imageName, int x, int y)
{
	ship::init(imageName, x, y);
	
	return S_OK;
}

void phoenix::release()
{
	ship::release();
}

void phoenix::update()
{
	ship::update();
}

void phoenix::render()
{
	ship::render();
}

void phoenix::move()
{
	int frame;
	float angle;

	angle = _angle + PI / 26;
	if (angle > PI2) _angle -= PI2;

	frame = int(_angle / ((PI * 2) / 26));
	_image->setFrameX(frame);

	_x += cosf(_angle) * _speed;
	_y += -sinf(_angle) * _speed;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}
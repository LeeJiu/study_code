#include "stdafx.h"
#include "spaceShip.h"


spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}


HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("ship", "rocket.bmp", 52, 64, true, 0xff00ff);
	_ship->setX(CENTERX - _ship->getWidth() / 2);
	_ship->setY(CENTERY - _ship->getHeight() / 2 + 200);

	_missile = new missile;
	_missile->init(5, 400);

	return S_OK;
}

void spaceShip::release()
{
	_missile->release();
	SAFE_DELETE(_missile);
}

void spaceShip::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_ship->setX(_ship->getX() - 5.0f);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_ship->setX(_ship->getX() + 5.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_ship->setY(_ship->getY() - 5.0f);
	}
		
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_ship->setY(_ship->getY() + 5.f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getX() + _ship->getFrameWidth() / 2,
			_ship->getY() - 60);
	}

	_missile->update();

}

void spaceShip::render()
{
	_ship->render(getMemDC());
	_missile->render();
}
#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

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

	return S_OK;
}

void spaceShip::release()
{
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
}

void spaceShip::render()
{
	_ship->render(getMemDC());
}
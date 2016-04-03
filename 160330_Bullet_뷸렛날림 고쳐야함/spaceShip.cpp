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

	_missile = new missile;
	_missile->init(10, 400);		//미사일 많아지면 느려진다.

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

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getX() + _ship->getFrameWidth() / 2,
			_ship->getY() - 60);
	}

	_missile->update();
	collision();

}

void spaceShip::render()
{
	_ship->render(getMemDC());
	_missile->render();
}

void spaceShip::removeMissile(int arrNum)
{
	if (_missile)
	{
		_missile->removeMissile(arrNum);
	}
}

void spaceShip::collision(void)
{
	//내 총알과 적이 충돌했다면
	for (int i = 0; i < _missile->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT rc;
			if (IntersectRect(&rc, &_missile->getVBullet()[i].rc, &_em->getVMinion()[j]->getRect()))
			{
				//_missile->removeMissile(i);
				_missile->getVBullet()[i].fire = false;
				_em->removeMinion(j);
				break;
			}
		}
	}
}
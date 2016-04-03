#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 50, 1000);

	_bullet2 = new bullet2;
	_bullet2->init("missile", 4, 1000);

	_rnd = RND->getInt(4);
	_x = _y = 0;

	return S_OK;
}

void enemyManager::release()
{
	_bullet->release();
	SAFE_DELETE(_bullet);
	_bullet2->release();
	SAFE_DELETE(_bullet2);
}

void enemyManager::update()
{
	_time = TIMEMANAGER->getWorldTime();

	bulletFire();
	_bullet->update();
	_bullet2->update();

	collision();
}

void enemyManager::render()
{
	_bullet->render();
	_bullet2->render();
}


//Àû ÃÑ¾Ë ¹ß½Î
void enemyManager::bulletFire()
{
	switch (_rnd)
	{
	case 0:
		_x = 0;
		_y = RND->getFromIntTo(0, WINSIZEY);
		_rnd = RND->getInt(4);
		break;
	case 1:
		_x = WINSIZEX;
		_y = RND->getFromIntTo(0, WINSIZEY);
		_rnd = RND->getInt(4);
		break;
	case 2:
		_x = RND->getFromIntTo(0, WINSIZEX);
		_y = 0;
		_rnd = RND->getInt(4);
		break;
	case 3:
		_x = RND->getFromIntTo(0, WINSIZEX);
		_y = WINSIZEY;
		_rnd = RND->getInt(4);
		break;
	}

	float angle = MY_UTIL::getAngle(_x, _y,
		_ship->getShipImage()->getCenterX(),
		_ship->getShipImage()->getCenterY());

	_bullet->fire(_x, _y, angle, 3.0f);

	if((int)_time % 5 == 0)
		_bullet2->fire(_x, _y, angle, 3.0f);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); ++i)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0),
			&_bullet->getVBullet()[i].rc,
			&_ship->getShipImage()->boundingBox()))
		{
			_bullet->removeBullet(i);
			break;
		}
	}
	for (int i = 0; i < _bullet2->getVBullet().size(); ++i)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0),
			&_bullet2->getVBullet()[i].rc,
			&_ship->getShipImage()->boundingBox()))
		{
			_bullet2->removeBullet(i);
			break;
		}
	}
}
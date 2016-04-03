#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init(spaceShip* spaceShip)
{
	_bullet = new bullet;
	_bullet->init("bullet", 15, 600);

	_spaceShip = spaceShip;

	return S_OK;
}

void enemyManager::release()
{
	_bullet->release();
	SAFE_DELETE(_bullet);

	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		SAFE_DELETE(*_viMinion);
	}

	_vMinion.clear();
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	minionBulletFire();
	_bullet->update();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
}

//미니언 셋팅 해줄 함수
void enemyManager::setMinion()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("ufo", PointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);
		}
	}
}

//적 총알 발싸
void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();
			float angle = MY_UTIL::getAngle(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + (rc.top - rc.bottom) / 2 + 30, _spaceShip->getX(), _spaceShip->getY());
			_bullet->fire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + (rc.bottom - rc.top) / 2,
				angle, 3.0f);
		}
	}
}

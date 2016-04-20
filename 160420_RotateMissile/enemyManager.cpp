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
	_bullet->init("bullet", 15, 600);

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

	collision();
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
	/*for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + (rc.top - rc.bottom) / 2 + 30,
				-(PI / 2), 3.0f);
		}
	}*/

	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();
			_bullet->fire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + (rc.top - rc.bottom) / 2 + 30,
				MY_UTIL::getAngle(
				rc.left + (rc.right - rc.left) / 2, 
				rc.top + (rc.bottom - rc.top) / 2,
				_ship->getShipImage()->getCenterX(),
				_ship->getShipImage()->getCenterY())
				, 3.0f);
		}
	}
}

void enemyManager::removeMinion(int arrNum)
{
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_bullet->getVBullet()[i].rc, &_ship->getShipImage()->boundingBox()))
		{
			//여기 들어왔다는 것은 충돌이 됐다는 거다
			_ship->hitDamage(10);
			_bullet->removeBullet(i);
			break;
		}
	}
}
#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

//총알을 만들자
HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 15, 600);

	_bullet2 = new bullet2;
	_bullet2->init("bullet", 30, 500);

	_bullet3 = new bullet3;
	_bullet3->init("bullet", 10, 300);

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
	//적들을 업데이트
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	//총알 발사 / 업데이트
	minionBulletFire();
	_bullet->update();
	_bullet2->update();
	_bullet3->update();
	//충돌 (적 총알 -> 플레이어)
	collision();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
	_bullet2->render();
	_bullet3->render();
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

			_vMinion.push_back(ufo);	//매니저의 벡터 안에 적들을 넣는다
		}
	}
}

//보스를 한번 셋팅해보련?
void enemyManager::setBoss()
{
	enemy* ufo_boss;
	ufo_boss = new boss;
	ufo_boss->init("ufo", PointMake(800, 100));

	_vMinion.push_back(ufo_boss);	//매니저의 벡터 안에 보스를 넣는다
}

//적 총알 발사
void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		//적이 총알을 발사하는 시점이라면
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();
			
			float angle = MY_UTIL::getAngle(rc.left + (rc.right - rc.left) / 2,rc.top + (rc.bottom - rc.top) / 2,
				_ship->getShipImage()->getCenterX(), _ship->getShipImage()->getCenterY());
			
			if (!(*_viMinion)->isBoss())
			{
				_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + (rc.bottom - rc.top) / 2,
					angle, 3.0f);
			}
			else
			{
				if ((*_viMinion)->getPattern() == PATTERN_1)
				{
					_bullet2->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + (rc.bottom - rc.top) / 2);
					(*_viMinion)->setPattern(PATTERN_2);
				}
				else
				{
					_bullet3->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + (rc.bottom - rc.top) / 2);
					(*_viMinion)->setPattern(PATTERN_1);
				}
			}
		}
	}
}

//미니언 삭제
void enemyManager::removeMinion(int arrNum)
{
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

//적 총알과 플레이어 충돌 체크
void enemyManager::collision()
{
	//처음부터 적 총알의 크기까지 돌아라. 사이즈가 0이면 당연히 안돈다.
	for (int i = 0; i < _bullet->getVBullet().size(); ++i)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_bullet->getVBullet()[i].rc, &_ship->getShipImage()->boundingBox()))
		{
			_bullet->removeBullet(i);
			break;
		}
	}
}
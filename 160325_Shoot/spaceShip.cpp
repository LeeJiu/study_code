#include "stdafx.h"
#include "spaceShip.h"
#include "enemy.h"


spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}


HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("hatzling", "hatzling.bmp", 42, 44, true, 0x00ff00);

	_x = CENTERX;
	_y = WINSIZEY / 5 * 4;

	_rcShip = RectMakeCenter(_x, _y,
		_ship->getFrameWidth(), _ship->getFrameHeight());

	_ship->setX(_rcShip.left);
	_ship->setY(_rcShip.top);

	_isDead = false;

	_missile = new missile;
	_missile->init(MISSILEMAX);

	return S_OK;
}

void spaceShip::release()
{
	_missile->release();
	SAFE_DELETE(_missile);
}

void spaceShip::update(enemy** enemy)
{
	_enemy = enemy;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 5.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 5.f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 5.f;
	}
		
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 5.f;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getX() + _ship->getFrameWidth() / 2,
				_ship->getY() - _ship->getFrameHeight());
	}

	//rect 갱신
	_rcShip = RectMakeCenter(_x, _y,
		_ship->getFrameWidth(), _ship->getFrameHeight());

	//image의 위치를 rect에 맞추자
	_ship->setX(_rcShip.left);
	_ship->setY(_rcShip.top);

	hit();

	_missile->update();
}

void spaceShip::render()
{
	if (!_isDead)
	{
		_ship->render(getMemDC());
		_missile->render();
	}
}

void spaceShip::hit()
{
	for (int i = 0; i < MISSILEMAX; ++i)
	{
		if (!_missile->getMissileVec()[i].fire) continue;

		for (int i = 0; i < ENEMYMAX; ++i)
		{
			if (_enemy[i]->isDead()) continue;	//죽은 적이라면 돌지 말자
			
			//총이랑 충돌하면 총 지운다
			if (IntersectRect(&RectMake(0, 0, 0, 0),
				&_missile->getMissileVec()[i].rc, &_enemy[i]->getEnemyRect()))
			{
				_missile->getMissileVec()[i].fire = false;	//미사일의 상태를 미발사로 변경
				_enemy[i]->die();		//적이 죽는다!
				break;
			}
		}
	}
}

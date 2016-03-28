#include "stdafx.h"
#include "enemy.h"
#include "spaceShip.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init(int i)
{
	_enemy = IMAGEMANAGER->addImage("enemy", "rocket.bmp", 52, 64, true, 0xff00ff);

	_x = _enemy->getFrameWidth() * i + _enemy->getFrameWidth()/2 * (i + 1) + 20;
	_y = 0;

	_rcEnemy = RectMakeCenter(_x, _y, 
		_enemy->getFrameWidth(), _enemy->getFrameHeight());
	
	_enemy->setX(_rcEnemy.left);
	_enemy->setY(_rcEnemy.top);

	_isDead = false;

	_bullet = new bullet;
	_bullet->init(BULLETMAX);

	_count = 0;

	return S_OK;
}

void enemy::release()
{
	_bullet->release();
	SAFE_DELETE(_bullet);
}

void enemy::update(spaceShip* ship)
{
	_ship = ship;

	_y += 2.f;

	_count++;
	if (!_isDead && !_ship->isDead() && _y < _ship->getY())		//플레이어보다 밑에 있으면 안쏜다
	{
		if (_count % 10 == 0)
		{
			_bullet->fire(_rcEnemy.left + _enemy->getFrameWidth() / 2,
				_rcEnemy.top + 50, _ship->getX(), _ship->getY());
		}
	}

	_rcEnemy = RectMakeCenter(_x, _y,
		_enemy->getFrameWidth(), _enemy->getFrameHeight());

	attack();

	_bullet->update();
}

void enemy::render()
{
	_bullet->render();
	if (!_isDead)
	{
		_enemy->frameRender(getMemDC(), _rcEnemy.left, _rcEnemy.top);
	}
}

void enemy::attack()
{
	for (int i = 0; i < BULLETMAX; ++i)
	{
		if (!_bullet->getBulletVec()[i].fire) continue;

		//총이랑 충돌하면 총 지운다
		if (IntersectRect(&RectMake(0, 0, 0, 0),
			&_bullet->getBulletVec()[i].rc, &_ship->getShipRect()))
		{
			_bullet->getBulletVec()[i].fire = false;	//미사일의 상태를 미발사로 변경
			_ship->die();		//적이 죽는다!
			break;
		}
	}
}
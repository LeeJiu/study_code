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
		if (!_isDead)
		{
			_missile->fire(_ship->getX() + _ship->getFrameWidth() / 2,
				_ship->getY() - _ship->getFrameHeight());
		}
	}

	//rect ����
	_rcShip = RectMakeCenter(_x, _y,
		_ship->getFrameWidth(), _ship->getFrameHeight());

	//image�� ��ġ�� rect�� ������
	_ship->setX(_rcShip.left);
	_ship->setY(_rcShip.top);

	attack();

	collisionEnemy();

	_missile->update();
}

void spaceShip::render()
{
	_missile->render();
	if (!_isDead)
	{
		_ship->frameRender(getMemDC(), _rcShip.left, _rcShip.top);
	}
}

void spaceShip::attack()
{
	for (int i = 0; i < MISSILEMAX; ++i)
	{
		if (!_missile->getMissileVec()[i].fire) continue;

		for (int j = 0; j < ENEMYMAX; ++j)
		{
			if (_enemy[j]->isDead()) continue;	//���� ���̶�� ���� ����
			
			//���̶� �浹�ϸ� �� �����
			if (IntersectRect(&RectMake(0, 0, 0, 0),
				&_missile->getMissileVec()[i].rc, &_enemy[j]->getEnemyRect()))
			{
				_missile->getMissileVec()[i].fire = false;	//�̻����� ���¸� �̹߻�� ����
				_enemy[j]->die();		//���� �״´�!
				break;
			}
		}
	}
}

void spaceShip::collisionEnemy()
{
	for (int i = 0; i < ENEMYMAX; ++i)
	{
		if (_enemy[i]->isDead()) continue;	//���� ���̶�� ���� ����

		//���̶� �浹�ϸ� �״´�
		if (IntersectRect(&RectMake(0, 0, 0, 0),
			&_rcShip, &_enemy[i]->getEnemyRect()))
		{
			die();
			break;
		}
	}
}

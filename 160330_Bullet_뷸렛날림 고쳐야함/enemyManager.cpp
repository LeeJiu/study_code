#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

//�Ѿ��� ������
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
	//������ ������Ʈ
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	//�Ѿ� �߻� / ������Ʈ
	minionBulletFire();
	_bullet->update();
	_bullet2->update();
	_bullet3->update();
	//�浹 (�� �Ѿ� -> �÷��̾�)
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

//�̴Ͼ� ���� ���� �Լ�
void enemyManager::setMinion()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("ufo", PointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);	//�Ŵ����� ���� �ȿ� ������ �ִ´�
		}
	}
}

//������ �ѹ� �����غ���?
void enemyManager::setBoss()
{
	enemy* ufo_boss;
	ufo_boss = new boss;
	ufo_boss->init("ufo", PointMake(800, 100));

	_vMinion.push_back(ufo_boss);	//�Ŵ����� ���� �ȿ� ������ �ִ´�
}

//�� �Ѿ� �߻�
void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); _viMinion++)
	{
		//���� �Ѿ��� �߻��ϴ� �����̶��
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

//�̴Ͼ� ����
void enemyManager::removeMinion(int arrNum)
{
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

//�� �Ѿ˰� �÷��̾� �浹 üũ
void enemyManager::collision()
{
	//ó������ �� �Ѿ��� ũ����� ���ƶ�. ����� 0�̸� �翬�� �ȵ���.
	for (int i = 0; i < _bullet->getVBullet().size(); ++i)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_bullet->getVBullet()[i].rc, &_ship->getShipImage()->boundingBox()))
		{
			_bullet->removeBullet(i);
			break;
		}
	}
}
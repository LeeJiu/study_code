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
	_ship = IMAGEMANAGER->addImage("ship", "image/rocket.bmp", 52, 64, true, 0xff00ff);
	_ship->setX(CENTERX - _ship->getWidth() / 2);
	_ship->setY(CENTERY - _ship->getHeight() / 2 + 200);

	_missile = new missile;
	_missile->init(10, 400);

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 10, _ship->getWidth(), 5);

	_currentHP = 1000;
	_maxHP = 1000;

	_hpBar->gauge(_currentHP, _maxHP);

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

	/* progressBar */

	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 10);
	_hpBar->gauge(_currentHP, _maxHP);
	_hpBar->update();

	/* save or load */

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("saveData.txt", vStr);
	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("saveData.txt");

		_currentHP = atoi(vStr[0].c_str());
		_maxHP = atoi(vStr[1].c_str());
		_ship->setX((float)atof(vStr[2].c_str()));
		_ship->setY((float)atof(vStr[3].c_str()));
	}
	
	_missile->update();
	collision();

}

void spaceShip::render()
{
	_ship->render(getMemDC());
	_missile->render();
	_hpBar->render();
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
				_missile->removeMissile(i);
				_em->removeMinion(j);
				break;
			}
		}
	}
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}
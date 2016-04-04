#include "stdafx.h"
#include "enemy.h"
#include "player.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}


HRESULT enemy::init()
{
	//player 초기화
	IMAGEMANAGER->addFrameImage("enemy_walk", "sakura_walk.bmp", 336, 190, 6, 2, true, 0x00ff00);
	IMAGEMANAGER->addFrameImage("enemy_attack", "sakura_attack.bmp", 240, 190, 2, 2, true, 0x00ff00);

	_enemy.image = IMAGEMANAGER->addFrameImage("enemy_idle", "sakura_idle.bmp", 180, 194, 3, 2, true, 0x00ff00);
	_enemy.x = CENTERX + CENTERX / 5 * 4;
	_enemy.y = CENTERY;
	_enemy.enemy = RectMakeCenter(_enemy.x, _enemy.y, _enemy.image->getFrameWidth(), _enemy.image->getFrameHeight());
	_enemy.state = R_IDLE_E;
	_enemy.maxHp = _enemy.curHp = 100;

	_index = _count = 0;

	//hp bar 초기화
	IMAGEMANAGER->addImage("enemy_bgBar", "bar_bg.bmp", 200, 20, true, 0x00ff00);
	IMAGEMANAGER->addImage("enemy_hpBar", "bar_hp.bmp", 200, 20, true, 0x00ff00);

	_hpBar = new progressBar;
	_hpBar->init("enemy_bgBar", "enemy_hpBar", _enemy.maxHp, _enemy.curHp);
	_hpBar->setBar(_enemy.x, _enemy.y - _hpBar->getBgImage()->getFrameHeight(),
		70, 10);

	return S_OK;
}

void enemy::release()
{

}

void enemy::update()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_enemy.state = L_WALK_E;
		_enemy.x -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_enemy.state = R_WALK_E;
		_enemy.x += 3.f;
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		if (_enemy.state == R_IDLE_E || _enemy.state == R_WALK_E)
		{
			_enemy.state = R_ATTACK_E;
			_index = 0;
		}
		else if (_enemy.state == L_IDLE_E || _enemy.state == L_WALK_E)
		{
			_enemy.state = L_ATTACK_E;
			_index = IMAGEMANAGER->findImage("enemy_attack")->getMaxFrameX();
		}
		collision();
	}

	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_enemy.state = L_IDLE_E;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		_enemy.state = R_IDLE_E;
	}

	_enemy.enemy = RectMakeCenter(_enemy.x, _enemy.y, _enemy.image->getFrameWidth(), _enemy.image->getFrameHeight());

	//플레이어를 따라다니는 hp bar의 위치 세팅
	_hpBar->setPosition(_enemy.x, _enemy.y - _hpBar->getBgImage()->getFrameHeight());

	setFrame();
}

void enemy::render()
{
	switch (_enemy.state)
	{
	case R_IDLE_E: case L_IDLE_E:
		IMAGEMANAGER->frameRender("enemy_idle", getMemDC(), _enemy.x, _enemy.y, _enemy.image->getFrameX(), _enemy.image->getFrameY());
		break;
	case R_WALK_E: case L_WALK_E:
		IMAGEMANAGER->frameRender("enemy_walk", getMemDC(), _enemy.x, _enemy.y, _enemy.image->getFrameX(), _enemy.image->getFrameY());
		break;
	case R_ATTACK_E: case L_ATTACK_E:
		IMAGEMANAGER->frameRender("enemy_attack", getMemDC(), _enemy.x - 20, _enemy.y, _enemy.image->getFrameX(), _enemy.image->getFrameY());
		break;
	}

	_hpBar->render();
}

void enemy::setFrame()
{
	switch (_enemy.state)
	{
	case R_IDLE_E:
	{
		_enemy.image = IMAGEMANAGER->findImage("enemy_idle");
		_count++;
		_enemy.image->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _enemy.image->getMaxFrameX())
			{
				_index = 0;
			}
			_enemy.image->setFrameX(_index);
		}
	}
	break;
	case L_IDLE_E:
	{
		_enemy.image = IMAGEMANAGER->findImage("enemy_idle");
		_count++;
		_enemy.image->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
			{
				_index = _enemy.image->getMaxFrameX();
			}
			_enemy.image->setFrameX(_index);
		}
	}
	break;
	case R_WALK_E:
	{
		_enemy.image = IMAGEMANAGER->findImage("enemy_walk");
		_count++;
		_enemy.image->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _enemy.image->getMaxFrameX())
			{
				_index = 0;
			}
			_enemy.image->setFrameX(_index);
		}
	}
	break;
	case L_WALK_E:
	{
		_enemy.image = IMAGEMANAGER->findImage("enemy_walk");
		_count++;
		_enemy.image->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
			{
				_index = _enemy.image->getMaxFrameX();
			}
			_enemy.image->setFrameX(_index);
		}
	}
	break;
	case R_ATTACK_E:
	{
		_enemy.image = IMAGEMANAGER->findImage("enemy_attack");
		_count++;
		_enemy.image->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _enemy.image->getMaxFrameX())
			{
				_enemy.state = R_IDLE_E;
				_index = 0;
			}
			_enemy.image->setFrameX(_index);
		}
	}
	break;
	case L_ATTACK_E:
	{
		_enemy.image = IMAGEMANAGER->findImage("enemy_attack");
		_count++;
		_enemy.image->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
			{
				_enemy.state = L_IDLE_E;
				_index = _enemy.image->getMaxFrameX();
			}
			_enemy.image->setFrameX(_index);
		}
	}
	break;
	}
}

void enemy::hit()
{
	_enemy.curHp -= 10;
	_hpBar->decreaseBar(10);
}

void enemy::collision()
{
	if (_enemy.state == R_ATTACK_E)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_enemy.enemy, &_player->getRect()))
		{
			_player->hit();
		}
	}
	else if (_enemy.state == L_ATTACK_E)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_enemy.enemy, &_player->getRect()))
		{
			_player->hit();
		}
	}
}
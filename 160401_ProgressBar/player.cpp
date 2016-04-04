#include "stdafx.h"
#include "player.h"
#include "enemy.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	//player 초기화
	IMAGEMANAGER->addFrameImage("walk", "sakura_walk.bmp", 336, 190, 6, 2, true, 0x00ff00);
	IMAGEMANAGER->addFrameImage("attack", "sakura_attack.bmp", 240, 190, 2, 2, true, 0x00ff00);

	_player.image = IMAGEMANAGER->addFrameImage("idle", "sakura_idle.bmp", 180, 194, 3, 2, true, 0x00ff00);
	_player.x = CENTERX / 5;
	_player.y = CENTERY;
	_player.player = RectMakeCenter(_player.x, _player.y, _player.image->getFrameWidth(), _player.image->getFrameHeight());
	_player.state = R_IDLE;
	_player.maxHp = _player.curHp = 100;

	_index = _count = 0;

	//hp bar 초기화
	IMAGEMANAGER->addImage("bgBar", "bar_bg.bmp", 200, 20, true, 0x00ff00);
	IMAGEMANAGER->addImage("hpBar", "bar_hp.bmp", 200, 20, true, 0x00ff00);

	_hpBar = new progressBar;
	_hpBar->init("bgBar", "hpBar", _player.maxHp, _player.curHp);
	_hpBar->setBar(_player.x, _player.y - _hpBar->getBgImage()->getFrameHeight(),
		70, 10);

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.state = L_WALK;
		_player.x -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.state = R_WALK;
		_player.x += 3.f;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_player.state == R_IDLE || _player.state == R_WALK)
		{
			_player.state = R_ATTACK;
			_index = 0;
		}
		else if (_player.state == L_IDLE || _player.state == L_WALK)
		{
			_player.state = L_ATTACK;
			_index = IMAGEMANAGER->findImage("attack")->getMaxFrameX();
		}
		collision();
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_player.state = L_IDLE;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player.state = R_IDLE;
	}

	_player.player = RectMakeCenter(_player.x, _player.y, _player.image->getFrameWidth(), _player.image->getFrameHeight());

	//플레이어를 따라다니는 hp bar의 위치 세팅
	_hpBar->setPosition(_player.x, _player.y - _hpBar->getBgImage()->getFrameHeight());

	

	setFrame();
}

void player::render()
{
	switch (_player.state)
	{
	case R_IDLE: case L_IDLE:
		IMAGEMANAGER->frameRender("idle", getMemDC(), _player.x, _player.y, _player.image->getFrameX(), _player.image->getFrameY());
		break;
	case R_WALK: case L_WALK:
		IMAGEMANAGER->frameRender("walk", getMemDC(), _player.x, _player.y, _player.image->getFrameX(), _player.image->getFrameY());
		break;
	case R_ATTACK: case L_ATTACK:
		IMAGEMANAGER->frameRender("attack", getMemDC(), _player.x - 20, _player.y, _player.image->getFrameX(), _player.image->getFrameY());
		break;
	}

	_hpBar->render();
}

void player::setFrame()
{
	switch (_player.state)
	{
	case R_IDLE:
	{
		_player.image = IMAGEMANAGER->findImage("idle");
		_count++;
		_player.image->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _player.image->getMaxFrameX())
			{
				_index = 0;
			}
			_player.image->setFrameX(_index);
		}
	}
	break;
	case L_IDLE:
	{
		_player.image = IMAGEMANAGER->findImage("idle");
		_count++;
		_player.image->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
			{
				_index = _player.image->getMaxFrameX();
			}
			_player.image->setFrameX(_index);
		}
	}
	break;
	case R_WALK:
	{
		_player.image = IMAGEMANAGER->findImage("walk");
		_count++;
		_player.image->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _player.image->getMaxFrameX())
			{
				_index = 0;
			}
			_player.image->setFrameX(_index);
		}
	}
	break;
	case L_WALK:
	{
		_player.image = IMAGEMANAGER->findImage("walk");
		_count++;
		_player.image->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
			{
				_index = _player.image->getMaxFrameX();
			}
			_player.image->setFrameX(_index);
		}
	}
	break;
	case R_ATTACK:
	{
		_player.image = IMAGEMANAGER->findImage("attack");
		_count++;
		_player.image->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _player.image->getMaxFrameX())
			{
				_player.state = R_IDLE;
				_index = 0;
			}
  			 _player.image->setFrameX(_index);
		}
	}
	break;
	case L_ATTACK:
	{
		_player.image = IMAGEMANAGER->findImage("attack");
		_count++;
		_player.image->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
			{
				_player.state = L_IDLE;
				_index = _player.image->getMaxFrameX();
			}
			_player.image->setFrameX(_index);
		}
	}
	break;
	}
}

void player::hit()
{
	_player.curHp -= 10;
	_hpBar->decreaseBar(10);
}

void player::collision()
{
	if (_player.state == R_ATTACK)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player.player, &_enemy->getRect()))
		{
			_enemy->hit();
		}
	}
	else if (_player.state == L_ATTACK)
	{
		if (IntersectRect(&RectMake(0, 0, 0, 0), &_player.player, &_enemy->getRect()))
		{
			_enemy->hit();
		}
	}
}
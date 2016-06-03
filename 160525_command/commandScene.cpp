#include "stdafx.h"
#include "commandScene.h"


commandScene::commandScene()
{
}


commandScene::~commandScene()
{
}

HRESULT commandScene::init()
{
	_kusanagi = IMAGEMANAGER->findImage("kusanagi_idle");

	_state = IDLE;
	_isRight = true;

	_x = CENTERX;
	_y = CENTERY;
	_rc = RectMakeCenter(_x, _y, _kusanagi->getFrameWidth(), _kusanagi->getFrameHeight());

	_fCommandClear = 2.5f;
	_fCommandTime = 0.0f;

	return S_OK;
}

void commandScene::release()
{
}

void commandScene::update()
{
	_rc = RectMakeCenter(_x, _y, _kusanagi->getFrameWidth(), _kusanagi->getFrameHeight());

	if ( KEYMANAGER->isStayKeyDown( VK_LEFT ) )
	{
		_isRight = false;
		if(_state != RUN)
			_state = WALK;
	}
	if ( KEYMANAGER->isStayKeyDown( VK_RIGHT ) )
	{
		_isRight = true;
		if (_state != RUN)
			_state = WALK;
	}

	if ( KEYMANAGER->isOnceKeyDown( VK_LEFT ) )
	{
		_isRight = false;
		_vCommand.push_back( key_left );
	}
	if ( KEYMANAGER->isOnceKeyDown( VK_RIGHT ) )
	{
		_isRight = true;
		_vCommand.push_back( key_right );
	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_vCommand.push_back(key_a);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = IDLE;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state = IDLE;
	}

	command();
	setImage();
}

void commandScene::render()
{
	_kusanagi->frameRender(getMemDC(), _rc.left, _rc.top, _curFrameX, _curFrameY);
}

void commandScene::command()
{
	if ( _vCommand.size() > 0 ) _fCommandTime += 0.1f;
	if ( _fCommandTime > _fCommandClear )
	{
		_fCommandTime = 0.f;
		_vCommand.clear();
	}

	if (_vCommand.size() > 1)
	{
		if ((_vCommand[0] == key_left && _vCommand[1] == key_left)
			|| (_vCommand[0] == key_right && _vCommand[1] == key_right))
		{
			_state = RUN;
		}
	}

	if (_vCommand.size() > 2)
	{
		if (_vCommand[0] == key_left && _vCommand[1] == key_right && _vCommand[2] == key_a)
		{
			_state = COMMAND1;
			if (_isRight)
				_curFrameX = 0;
			else
				_curFrameX = IMAGEMANAGER->findImage("kusanagi_commad1")->getMaxFrameX();
		}
	}
}

void commandScene::setImage()
{
	switch (_state)
	{
	case IDLE:
		_kusanagi = IMAGEMANAGER->findImage("kusanagi_idle");
		break;
	case WALK:
		_kusanagi = IMAGEMANAGER->findImage("kusanagi_walk");
		break;
	case RUN:
		_kusanagi = IMAGEMANAGER->findImage("kusanagi_run");
		break;
	case COMMAND1:
		_kusanagi = IMAGEMANAGER->findImage("kusanagi_command1");
		break;
	}

	setFrame();
}

void commandScene::setFrame()
{
	_count++;

	if (_isRight)
	{
		_curFrameY = 0;
		_kusanagi->setFrameY(_curFrameY);
		if (_count % 10 == 0)
		{
			_curFrameX++;
			if (_curFrameX > _kusanagi->getMaxFrameX())
			{
				_curFrameX = 0;
				if (_state == COMMAND1)
				{
					_state = IDLE;
				}
			}
			_kusanagi->setFrameX(_curFrameX);
		}
	}
	else
	{
		_curFrameY = 1;
		_kusanagi->setFrameY(_curFrameY);
		if (_count % 10 == 0)
		{
			_curFrameX--;
			if (_curFrameX < 0)
			{
				_curFrameX = _kusanagi->getMaxFrameX();
				if (_state == COMMAND1)
				{
					_state = IDLE;
				}
			}
			_kusanagi->setFrameX(_curFrameX);
		}
	}
}

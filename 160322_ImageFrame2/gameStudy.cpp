#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init();

	_bgImage = new image;
	_shadow = new image;
	_sakuraIdle = new image;
	_sakuraWalk = new image;
	_sakuraJump = new image;

	_bgImage->init("sakura_bg.bmp", WINSIZEX, WINSIZEY, false, false);
	_shadow->init("shadow.bmp", 60, 30, true, RGB(0, 255, 0));
	_sakuraIdle->init("sakura_idle.bmp", CENTERX, CENTERY, 180, 194, 3, 2, true, RGB(0, 255, 0));
	_sakuraWalk->init("sakura_walk.bmp", CENTERX, CENTERY, 336, 190, 6, 2, true, RGB(0, 255, 0));
	_sakuraJump->init("sakura_jump.bmp", CENTERX, CENTERY, 360, 194, 3, 2, true, RGB(0, 255, 0));

	_x = _sakuraIdle->getX();
	_y = _sakuraIdle->getY();
	_oldY = 0;
	_jumpPw = 0.f;
	_gravity = 0.f;

	_isIdle = true;
	_isRight = true;
	_isJump = false;
	_count = 0;
	_index = 0;
	_resizeX = _resizeY = _reAlpha = 0;

	return S_OK;
}

void gameStudy::release()
{
	SAFE_RELEASE(_sakuraIdle);
	SAFE_RELEASE(_sakuraWalk);

	SAFE_DELETE(_sakuraIdle);
	SAFE_DELETE(_sakuraWalk);

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isIdle = false;		//walk motion
		if (_isRight) _isRight = !_isRight;
		_x -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isIdle = false;		//walk motion
		if (!_isRight) _isRight = !_isRight;
		_x += 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && !_isJump)
	{
		_isIdle = false;
		_y -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !_isJump)
	{
		_isIdle = false;
		_y += 3.f;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!_isJump)
		{
			_oldY = _y;
			_isIdle = false;
			_isJump = true;
			_jumpPw = 4.f;
			_gravity = 0.1f;
		}
	}
	
	//키를 떼면, idle motion
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && !_isJump) _isIdle = true;
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && !_isJump) _isIdle = true;
	if (KEYMANAGER->isOnceKeyUp(VK_UP) && !_isJump) _isIdle = true;
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN) && !_isJump) _isIdle = true;

	move();

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//이 사이에서 그려주면 됨.

	_bgImage->render(backDC, 0, 0);

	if (_isIdle)
	{
		_shadow->alphaRender(backDC, _x, _y + 82, 150);
		_sakuraIdle->frameRender(backDC, _x, _y, _sakuraIdle->getFrameX(), _sakuraIdle->getFrameY());
	}
	else if (!_isIdle)
	{
		if (_isJump)
		{
			_shadow->alphaRender(backDC, _x, _oldY + 82, 0, 0, _shadow->getFrameWidth(), _shadow->getFrameHeight(), _resizeX, _resizeY, 150 - _reAlpha);
			_sakuraJump->frameRender(backDC, _x - 40, _y, _sakuraJump->getFrameX(), _sakuraJump->getFrameY());
		}
		else
		{
			_shadow->alphaRender(backDC, _x, _y + 82, 150);
			_sakuraWalk->frameRender(backDC, _x, _y, _sakuraWalk->getFrameX(), _sakuraWalk->getFrameY());
		}
	}


	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::move()
{
	if (_isRight && !_isIdle && !_isJump)
	{
		_count++;
		_sakuraWalk->setFrameY(0);		//오른쪽으로 걷는 이미지 프레임 Y좌표
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _sakuraWalk->getMaxFrameX())	//인덱스가 마지막 프레임보다 크면
				_index = 0;								//첫 번째 인덱스로 / 프레임 루프 돌자

			_sakuraWalk->setFrameX(_index);				//이미지 프레임 X좌표를 지정
		}
	}
	else if (!_isRight && !_isIdle && !_isJump)
	{
		_count++;
		_sakuraWalk->setFrameY(1);		//왼쪽으로 걷는 이미지 프레임 Y좌표
		if (_count % FRAME == 0)
		{
			_index--;					//좌우 반전 시킨 이미지라서 오른쪽부터 인덱스를 읽어와야함
			if (_index < 0)				//인덱스가 첫 번째 프레임보다 작아지면
				_index = _sakuraWalk->getMaxFrameX();	//마지막 인덱스로 / 프레임 루프 돌자

			_sakuraWalk->setFrameX(_index);
		}
	}
	else if (_isRight && _isIdle && !_isJump)
	{
		_count++;
		_sakuraIdle->setFrameY(0);		//오른쪽으로 걷다가 idle 이미지 프레임 Y좌표
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _sakuraIdle->getMaxFrameX())	//인덱스가 마지막 프레임보다 크면
				_index = 0;								//첫 번째 인덱스로 / 프레임 루프 돌자

			_sakuraIdle->setFrameX(_index);				//이미지 프레임 X좌표를 지정
		}
	}
	else if (!_isRight && _isIdle && !_isJump)
	{
		_count++;
		_sakuraIdle->setFrameY(1);		//왼쪽으로 걷다가 idle 이미지 프레임 Y좌표
		if (_count % FRAME == 0)
		{
			_index--;					//좌우 반전 시킨 이미지라서 오른쪽부터 인덱스를 읽어와야함
			if (_index < 0)				//인덱스가 첫 번째 프레임보다 작아지면
				_index = _sakuraIdle->getMaxFrameX();	//마지막 인덱스로 / 프레임 루프 돌자

			_sakuraIdle->setFrameX(_index);
		}
	}
	else if (_isJump && _isRight && !_isIdle)
	{
		_y -= _jumpPw;
		_jumpPw -= _gravity;

		_count++;
		_sakuraJump->setFrameY(0);

		int height = _sakuraJump->getFrameHeight();

		if (_count % FRAME == 0)
		{
			if (_jumpPw > 0 && _oldY > _y)
			{
				_resizeX += 5;
				_resizeY += 5;
				_reAlpha += 10;
				_sakuraJump->setFrameX(0);
			}
			else if (_jumpPw < 0 && _oldY - (height / 2) > _y)
			{
				if (_shadow->getFrameWidth() - _resizeX < _shadow->getFrameWidth()
					&& _shadow->getFrameHeight() - _resizeY < _shadow->getFrameHeight())
				{
					_resizeX -= 5;
					_resizeY -= 5;
					_reAlpha -= 10;
				}
				_sakuraJump->setFrameX(1);
			}
			else if (_jumpPw < 0 && _oldY > _y && _oldY - (height / 2) < _y)
			{
				if (_shadow->getFrameWidth() - _resizeX < _shadow->getFrameWidth()
					&& _shadow->getFrameHeight() - _resizeY < _shadow->getFrameHeight())
				{
					_resizeX -= 5;
					_resizeY -= 5;
					_reAlpha -= 10;
				}
				_sakuraJump->setFrameX(2);
				_y = _oldY;
				_gravity = 0;
				_jumpPw = 0;
			}
			else if (_jumpPw == 0 && _oldY == _y)
			{
				_resizeX = 0;
				_resizeY = 0;
				_isJump = false;
				_isIdle = true;
			}
		}
	}
	else if (_isJump && !_isRight && !_isIdle)
	{
		_y -= _jumpPw;
		_jumpPw -= _gravity;

		_count++;
		_sakuraJump->setFrameY(1);

		int height = _sakuraJump->getFrameHeight();

		if (_count % FRAME == 0)
		{
			if (_jumpPw > 0 && _oldY > _y)
			{
				_resizeX += 5;
				_resizeY += 5;
				_reAlpha += 10;
				_sakuraJump->setFrameX(2);
			}
			else if (_jumpPw < 0 && _oldY - (height / 2) > _y)
			{
				if (_shadow->getFrameWidth() - _resizeX < _shadow->getFrameWidth()
					&& _shadow->getFrameHeight() - _resizeY < _shadow->getFrameHeight())
				{
					_resizeX -= 5;
					_resizeY -= 5;
					_reAlpha -= 10;
				}
				_sakuraJump->setFrameX(1);
			}
			else if (_jumpPw < 0 && _oldY > _y && _oldY - (height / 2) < _y)
			{
				if (_shadow->getFrameWidth() - _resizeX < _shadow->getFrameWidth()
					&& _shadow->getFrameHeight() - _resizeY < _shadow->getFrameHeight())
				{
					_resizeX -= 5;
					_resizeY -= 5;
					_reAlpha -= 10;
				}
				_sakuraJump->setFrameX(0);
				_y = _oldY;
				_gravity = 0;
				_jumpPw = 0;
			}
			else if (_jumpPw == 0 && _oldY == _y)
			{
				_resizeX = 0;
				_resizeY = 0;
				_isJump = false;
				_isIdle = true;
			}
		}
	}
}

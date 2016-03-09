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

	_jumpPower = _gravity = _isJump = _jumpCnt = 0;

	_rc = RectMakeCenter(WINSIZEX / 3, WINSIZEY - 100, 50, 50);

	_ptLand[0].x = WINSIZEX / 3;
	_ptLand[0].y = WINSIZEY - 50;
	_width[0] = 300 + RND->getInt(300);		//넓이 300~600
	_height = 50;
	
	_ptLand[1].x = _ptLand[0].x + _width[0] + INTERVAL;	//바닥 간격은 300
	_ptLand[1].y = WINSIZEY - 50;
	_width[1] = 300 + RND->getInt(300);		//넓이 300~600

	for (int i = 0; i < 2; ++i)
	{
		_land[i] = RectMakeCenter(_ptLand[i].x, _ptLand[i].y, _width[i], _height);
	}

	for (int i = 0; i < 3; ++i)
	{
		switch (i)
		{
		case 0:		//가로로 긴 애
			_ptHurdle[0].x = RND->getFromIntTo(100, 300);
			_ptHurdle[0].y = RND->getFromIntTo(200, 350);
			_hurdle[0] = RectMakeCenter(_ptHurdle[0].x, _ptHurdle[0].y, 300, 50);
			break;
		case 1:		//세로로 긴 애
			_ptHurdle[1].x = _hurdle[0].right + RND->getFromIntTo(100, 700);
			_ptHurdle[1].y = RND->getFromIntTo(100, 150);
			_hurdle[1] = RectMakeCenter(_ptHurdle[1].x, _ptHurdle[1].y, 50, 300);
			break;
		case 2:		//정사각형
			_ptHurdle[2].x = _hurdle[1].right + RND->getFromIntTo(100, 700);
			_ptHurdle[2].y = RND->getFromIntTo(200, 350);
			_hurdle[2] = RectMakeCenter(_ptHurdle[2].x, _ptHurdle[2].y, 50, 50);
			break;
		}
	}

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_jumpCnt == 0)
		{
			_jumpCnt++;
			_jumpPower = 4;
			_gravity = 0.1f;
		}
		else if (_jumpCnt == 1)
		{
			_jumpCnt++;
			_jumpPower += 4;
			_gravity = 0.1f;
		}
	}

	if (!IntersectRect(&_tmp, &_rc, &_land[0]) && !IntersectRect(&_tmp, &_rc, &_land[1]))
	{
		_gravity = 0.1f;
		_rc.top -= _jumpPower;
		_rc.bottom -= _jumpPower;
		_jumpPower -= _gravity;
	}
	//천장 밖으로 나가지마
	if (_rc.top < 0)
	{
		_jumpPower = 0;
		_rc.top = 0;
		_rc.bottom = 50;
	}
	//바닥과의 충돌
	if (IntersectRect(&_tmp, &_rc, &_land[0]) || IntersectRect(&_tmp, &_rc, &_land[1]))
	{
		_jumpPower = _gravity = _jumpCnt = 0;
		int height = _rc.bottom - _rc.top;
		_rc.bottom = _land[0].top;
		_rc.top = _rc.bottom - height;
	}
	//가로로 긴 애랑 충돌
	if (IntersectRect(&_tmp, &_rc, &_hurdle[0]))
	{
		//밑에서 박았을 때
		if (_rc.left > _hurdle[0].left && _rc.bottom > _hurdle[0].bottom)
		{
			_jumpPower = 0;
			_rc.top = _hurdle[0].bottom;
			_rc.bottom = _rc.top + 50;
		}
		else
		{
			_jumpPower = _gravity = _jumpCnt = 0;
			_rc.bottom = _hurdle[0].top;
			_rc.top = _rc.bottom - 50;
		}
	}
	//세로로 긴 애랑 충돌
	if (IntersectRect(&_tmp, &_rc, &_hurdle[1]))
	{
		_rc.right = _hurdle[1].left;
		_rc.left = _rc.right - 50;
	}
	//정사각형이랑 충돌 / 화면 밖으로 나가면
	if (IntersectRect(&_tmp, &_rc, &_hurdle[2]) || _rc.right < 0)
	{
		KillTimer(_hWnd, 1);
		MessageBox(_hWnd, "게임은 다시 시작된다!", "DEAD", NULL);
		//게임을 재시작하자
		init();
	}

	//바닥을 그려주자
	for (int i = 0; i < 2; ++i)
	{
		_ptLand[i].x -= 5;

		if (_land[0].right < 0)
		{
			_ptLand[0].x = _ptLand[1].x + _width[1] + INTERVAL;
			_width[0] = 300 + RND->getInt(300);
		}
		if (_land[1].right < 0)
		{
			_ptLand[1].x = _ptLand[0].x + _width[0] + INTERVAL;
			_width[1] = 300 + RND->getInt(300);
		}
		_land[i] = RectMakeCenter(_ptLand[i].x, _ptLand[i].y, _width[i], _height);
	}

	//장애물을 그려주자
	for (int i = 0; i < 3; ++i)
	{
		_ptHurdle[i].x -= 5;

		if (_hurdle[0].right < 0)
		{
			_ptHurdle[0].x = _hurdle[2].right + RND->getFromIntTo(300, 500);
			_ptHurdle[0].y = RND->getFromIntTo(200, 350);
		}
		if (_hurdle[1].right < 0)
		{
			_ptHurdle[1].x = _hurdle[0].right + RND->getFromIntTo(300, 500);
			_ptHurdle[1].y = RND->getFromIntTo(100, 150);
		}
		if (_hurdle[2].right < 0)
		{
			_ptHurdle[2].x = _hurdle[1].right + RND->getFromIntTo(300, 500);
			_ptHurdle[2].y = RND->getFromIntTo(200, 350);
		}
	}
	_hurdle[0] = RectMakeCenter(_ptHurdle[0].x, _ptHurdle[0].y, 300, 50);
	_hurdle[1] = RectMakeCenter(_ptHurdle[1].x, _ptHurdle[1].y, 50, 300);
	_hurdle[2] = RectMakeCenter(_ptHurdle[2].x, _ptHurdle[2].y, 50, 50);

	//플레이어의 위치를 다시 그려주자
	_rc = RectMake(_rc.left, _rc.top, 50, 50);

	gameNode::update();

}

void gameStudy::render(HDC hdc)
{
	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);

	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _land[i].left, _land[i].top, _land[i].right, _land[i].bottom);
	}
	for (int i = 0; i < 3; i++)
	{
		Rectangle(hdc, _hurdle[i].left, _hurdle[i].top, _hurdle[i].right, _hurdle[i].bottom);
	}

	sprintf_s(check, "jumpCount : %-5d", _jumpCnt);
	TextOut(hdc, 10, 10, check, strlen(check));
}

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

	_gravity = _jumpPower = _isJump = _jumpHurdle = _score = 0;

	_rc = RectMakeCenter(WINSIZEX / 6, WINSIZEY / 2, 50, 50);

	_pt[0].x = WINSIZEX / 3 * 2;
	_pt[0].y = WINSIZEY - RND->getInt(WINSIZEY / 3);
	_hurdle[0]._downRc = RectMakeCenter(_pt[0].x, _pt[0].y, 50, 400);
	_hurdle[0]._upRc = RectMakeCenter(_pt[0].x, _pt[0].y - 500, 50, 400);
	
	_pt[1].x = _pt[0].x + INTERVAL;
	_pt[1].y = WINSIZEY - RND->getInt(WINSIZEY / 2);
	_hurdle[1]._downRc = RectMakeCenter(_pt[1].x, _pt[1].y, 50, 400);
	_hurdle[1]._upRc = RectMakeCenter(_pt[1].x, _pt[1].y - 500, 50, 400);


	_land = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 50, 900, 100);

	return S_OK;
}

void gameStudy::release()
{
	gameNode::release();
}

void gameStudy::update()
{
	_score++;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_jumpPower = 3;
		_gravity = 0.1f;
		_isJump = true;
	}

	if (_isJump)
	{
		_rc.top -= _jumpPower;
		_rc.bottom -= _jumpPower;
		_jumpPower -= _gravity;
		if (_rc.top <= 0 || _rc.bottom >= _land.top)//천장에 닿거나 바닥에 닿으면
			_isJump = false;
	}
	else if(!_isJump && _rc.bottom < _land.top)		//천장에 붙지 말고, 바닥에서 바운스 하지 마라
	{
		_rc.top += _jumpPower;
		_rc.bottom += _jumpPower;
		_jumpPower += _gravity;
	}

	for (int i = 0; i < 2; ++i)
	{
		if (IntersectRect(&_tmp, &_rc, &_hurdle[i]._downRc)
			|| IntersectRect(&_tmp, &_rc, &_hurdle[i]._upRc))
		{
			KillTimer(_hWnd, 1);
			MessageBox(_hWnd, _scoreShow, "Score", NULL);
			//게임을 재시작하자
			init();		//이래도 되나?
		}
		if (_pt[i].x + 25 <= _rc.left && _rc.right <= _pt[i].x + 80)
		{
			_jumpHurdle = true;
			_score += (_jumpHurdle * 100) / 2;
		}
		else
			_jumpHurdle = false;
	}

	//기둥을 왼쪽으로 이동하자
	_pt[0].x -= 3;
	_pt[1].x -= 3;

	if (_pt[0].x < 0)
	{
		_pt[0].x = _pt[1].x + INTERVAL;
		_pt[0].y = WINSIZEY - RND->getInt(WINSIZEY / 2);
		_hurdle[0]._downRc = RectMakeCenter(_pt[0].x, _pt[0].y, 50, 400);
		_hurdle[0]._upRc = RectMakeCenter(_pt[0].x, _pt[0].y - 500, 50, 400);
	}
	if (_pt[1].x < 0)
	{
		_pt[1].x = _pt[0].x + INTERVAL;
		_pt[1].y = WINSIZEY - RND->getInt(WINSIZEY / 2);
		_hurdle[1]._downRc = RectMakeCenter(_pt[1].x, _pt[1].y, 50, 400);
		_hurdle[1]._upRc = RectMakeCenter(_pt[1].x, _pt[1].y - 500, 50, 400);
	}

	for (int i = 0; i < 2; ++i)
	{
		_hurdle[i]._downRc = RectMakeCenter(_pt[i].x, _pt[i].y, 50, 400);
		_hurdle[i]._upRc = RectMakeCenter(_pt[i].x, _pt[i].y - 500, 50, 400);
	}

	int _x, _y;
	_x = _rc.left, _y = _rc.top;
	_rc = RectMake(_x, _y, 50, 50);

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
	
	SetDCBrushColor(hdc, RGB(255, 0, 0));
	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);

	SetDCBrushColor(hdc, RGB(0, 255, 0));
	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _hurdle[i]._downRc.left, _hurdle[i]._downRc.top, _hurdle[i]._downRc.right, _hurdle[i]._downRc.bottom);
		Rectangle(hdc, _hurdle[i]._upRc.left, _hurdle[i]._upRc.top, _hurdle[i]._upRc.right, _hurdle[i]._upRc.bottom);
	}

	SetDCBrushColor(hdc, RGB(128, 128, 128));
	Rectangle(hdc, _land.left, _land.top, _land.right, _land.bottom);
	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);

	sprintf_s(_scoreShow, "Score : %-5d", _score);
	TextOut(hdc, 10, 10, _scoreShow, strlen(_scoreShow));
}

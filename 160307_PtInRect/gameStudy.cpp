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

	_changeDir = _changeColor = false;

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_rc = RectMakeCenter(_x, _y, 100, 100);

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (!_changeDir)
	{
		_x -= 5;
		_rc = RectMakeCenter(_x, _y, 100, 100);
		if (_rc.left < 0)
			_changeDir = true;
	}
	else
	{
		_x += 5;
		_rc = RectMakeCenter(_x, _y, 100, 100);
		if (_rc.right > WINSIZEX)
			_changeDir = false;
		PtInRect(&_rc, _ptMouse);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_rc, _ptMouse))
		{
			if (_changeColor)
				_changeColor = false;
			else
				_changeColor = true;
		}
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	HBRUSH MyBrush, OldBrush;
	MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);
	if (_changeColor)
	{
		SetDCBrushColor(hdc, RGB(255, 0, 0));
		Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
	else
	{
		SetDCBrushColor(hdc, RGB(0, 0, 255));
		Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);
}

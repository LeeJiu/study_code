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

	_randNum = RND->getInt(TEETHMAX);			//0~19중에 꽝 하나 고르기
	_height = WINSIZEY / 4;
	_GameStart = true;

	for (int i = 0; i < TEETHMAX; ++i)
	{
		if (i / 10 == 0)
		{
			_tooth[i]._isBlind = true;
			_tooth[i]._isBoom = false;
			_tooth[i]._rcTooth = RectMakeCenter((WINSIZEX / 10 * (i % 10)) + 30, _height * 1, 60, 80);
		}
		else
		{
			_tooth[i]._isBlind = true;
			_tooth[i]._isBoom = false;
			_tooth[i]._rcTooth = RectMakeCenter((WINSIZEX / 10 * (i % 10)) + 50, _height * 3, 60, 80);
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
	if (_GameStart)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < TEETHMAX; ++i)
			{
				if (PtInRect(&_tooth[i]._rcTooth, _ptMouse))
				{
					_tooth[i]._isBlind = false;				//누르면 까라
					if (i == _randNum)
						_tooth[i]._isBoom = true;
				}
			}
		}

		//꽝 눌렀으면
		if (_tooth[_randNum]._isBoom)
		{
			for (int i = 0; i < TEETHMAX; ++i)
			{
				if (i / 10 == 0)
				{
					_tooth[i]._rcTooth = RectMakeCenter((WINSIZEX / 10 * (i % 10)) + 30, _height * 2 - 30, 60, 80);
				}
				else
				{
					_tooth[i]._rcTooth = RectMakeCenter((WINSIZEX / 10 * (i % 10)) + 50, _height * 2 + 30, 60, 80);
				}
			}
			_GameStart = false;
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			init();
			_GameStart = true;
		}
	}


	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//HBRUSH MyBrush, OldBrush;
	//MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	//OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

	HDC MemDC;
	HBITMAP MyBitmap, OldBitmap;
	MemDC = CreateCompatibleDC(hdc);
	MyBitmap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

	for (int i = 0; i < TEETHMAX; ++i)
	{
		if (_tooth[i]._isBlind)
		{
			//SetDCBrushColor(hdc, RGB(0, 128, 0));
			//Rectangle(hdc, _tooth[i]._rcTooth.left, _tooth[i]._rcTooth.top, _tooth[i]._rcTooth.right, _tooth[i]._rcTooth.bottom);
			if (i / 10 == 0)
				BitBlt(hdc, _tooth[i]._rcTooth.left, _tooth[i]._rcTooth.top, 60, 80, MemDC, 0, 0, SRCCOPY);
			else
				BitBlt(hdc, _tooth[i]._rcTooth.left, _tooth[i]._rcTooth.top, 60, 80, MemDC, 65, 0, SRCCOPY);
		}
		else
		{
			//SetDCBrushColor(hdc, RGB(255, 255, 255));
			//Rectangle(hdc, _tooth[i]._rcTooth.left, _tooth[i]._rcTooth.top, _tooth[i]._rcTooth.right, _tooth[i]._rcTooth.bottom);
			
			if (i / 10 == 0)
				BitBlt(hdc, _tooth[i]._rcTooth.left, _tooth[i]._rcTooth.top, 60, 80, MemDC, 0, 0, SRCCOPY);
			else
				BitBlt(hdc, _tooth[i]._rcTooth.left, _tooth[i]._rcTooth.top, 60, 80, MemDC, 65, 0, SRCCOPY);

			SetBkMode(hdc, TRANSPARENT);
			if (!_tooth[i]._isBoom)
			{
				SetTextColor(hdc, RGB(0, 0, 0));
				SetTextAlign(hdc, TA_CENTER);
				if (i / 10 == 0)
					TextOut(hdc, _tooth[i]._rcTooth.left + 35, _tooth[i]._rcTooth.top + 30, "Pass", strlen("Pass"));
				else
					TextOut(hdc, _tooth[i]._rcTooth.left + 30, _tooth[i]._rcTooth.top + 20, "Pass", strlen("Pass"));
			}
			else
			{
				SetTextColor(hdc, RGB(255, 0, 0));
				SetTextAlign(hdc, TA_CENTER);
				TextOut(hdc, _tooth[i]._rcTooth.left + 33, _tooth[i]._rcTooth.top + 23, "Boom!!", strlen("Boom!!"));
				SetTextColor(hdc, RGB(0, 0, 255));
				TextOut(hdc,CENTERX, 10, "Press Enter Key To Restart", strlen("Press Enter Key To Restart"));
			}
		}
	}

	//SelectObject(hdc, OldBrush);
	//DeleteObject(MyBrush);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

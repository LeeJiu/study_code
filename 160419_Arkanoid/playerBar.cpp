#include "stdafx.h"
#include "playerBar.h"


playerBar::playerBar()
{
}


playerBar::~playerBar()
{
}

HRESULT playerBar::init()
{
	_bar.x = CENTERX;
	_bar.y = WINSIZEY / 5 * 4;
	_bar.rc = RectMakeCenter(_bar.x, _bar.y, 100, 20);

	return S_OK;
}

void playerBar::release()
{
}

void playerBar::update()
{
	move();
}

void playerBar::render()
{
	Rectangle(getMemDC(), _bar.rc.left, _bar.rc.top, _bar.rc.right, _bar.rc.bottom);
}

void playerBar::move()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_bar.rc.left > 0)
		{
			_bar.x -= 5.f;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_bar.rc.right < WINSIZEX)
		{
			_bar.x += 5.f;
		}
	}
	_bar.rc = RectMakeCenter(_bar.x, _bar.y, 100, 20);
}

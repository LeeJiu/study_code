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

	isCollide = false;
	
	radius = 50;

	rt = RectMakeCenter(CENTERX, CENTERY, 100, 100);
	cc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	cc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);
	
	if (IntersectRect(&RectMake(0, 0, 0, 0), &cc, &rt))
	{
		if (_ptMouse.x < rt.left && _ptMouse.y < rt.top)	//좌상단
		{
			int x, y;
			float distance;
			x = rt.left - _ptMouse.x;
			y = rt.top - _ptMouse.y;
			distance = sqrt((x * x)+(y * y));
			if (distance < radius)
				isCollide = true;
			else
				isCollide = false;
		}
		else if (_ptMouse.x > rt.right && _ptMouse.y < rt.top)//우상단
		{
			int x, y;
			float distance;
			x = _ptMouse.x - rt.right;
			y = rt.top - _ptMouse.y;
			distance = sqrt((x * x) + (y * y));
			if (distance < radius)
				isCollide = true;
			else
				isCollide = false;
		}
		else if (_ptMouse.x < rt.left && _ptMouse.y > rt.bottom)//좌하단
		{
			int x, y;
			float distance;
			x = rt.left - _ptMouse.x;
			y = _ptMouse.y - rt.bottom;
			distance = sqrt((x * x) + (y * y));
			if (distance < radius)
				isCollide = true;
			else
				isCollide = false;
		}
		else if (_ptMouse.x > rt.right && _ptMouse.y > rt.bottom)//우하단
		{
			int x, y;
			float distance;
			x = _ptMouse.x - rt.right;
			y = _ptMouse.y - rt.bottom;
			distance = sqrt((x * x) + (y * y));
			if (distance < radius)
				isCollide = true;
			else
				isCollide = false;
		}
		else
		{
			isCollide = true;
		}
	}
	else
	{
		isCollide = false;
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
	EllipseMakeCenter(hdc, _ptMouse.x, _ptMouse.y, 100, 100);
	if(isCollide)
		TextOut(hdc, 10, 10, "충돌", strlen("충돌"));
	else
		TextOut(hdc, 10, 10, "안충돌", strlen("안충돌"));
}

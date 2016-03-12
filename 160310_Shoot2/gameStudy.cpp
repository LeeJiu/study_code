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

	x = CENTERX;
	y = WINSIZEY;
	gunX = CENTERX;
	gunY = WINSIZEY - 80;
	angle = 90.f;

	circle = RectMakeCenter(x, y, 100, 100);

	ZeroMemory(bullet, sizeof(tagBullet));
	for (int i = 0; i < BULLETMAX; i++)
	{
		bullet[i].bulletSpd = 5.f;
	}

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (angle <= 180)
		{
			angle += 1.f;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (angle >= 0)
		{
			angle -= 1.f;
		}
	}
	
	gunX = cosf(angle*(PI / 180)) * 80 + CENTERX;
	gunY = -sinf(angle*(PI / 180)) * 80 + WINSIZEY;
	
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		bulletFire();
	}
	bulletMove();

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	EllipseMakeCenter(hdc, x, y, 100, 100);
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, gunX, gunY);

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!bullet[i].isFire) continue;
		Ellipse(hdc, bullet[i].bullet.left, bullet[i].bullet.top, bullet[i].bullet.right, bullet[i].bullet.bottom);
	}

	char str[128];
	sprintf_s(str, "gunX : %.2f gunY : %.2f", gunX, gunY);
	TextOut(hdc, 50, 50, str, strlen(str));
}

void gameStudy::bulletFire()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (bullet[i].isFire) continue;
		bullet[i].isFire = true;
		bullet[i].x = gunX;
		bullet[i].y = gunY;
		bullet[i].angle = angle;		//발사 각도 저장
		bullet[i].bullet = RectMakeCenter(bullet[i].x, bullet[i].y, 10, 10);
		break;
	}
}

void gameStudy::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!bullet[i].isFire) continue;
		
		//벽에 닿으면 튕기는 코드 / 과제
		if (bullet[i].x + 5 >= WINSIZEX)
		{
			bullet[i].x = WINSIZEX - 5;
			bullet[i].angle = 180 - bullet[i].angle;
		}
		else if (bullet[i].y - 5 <= 0)
		{
			bullet[i].y = 5;
			bullet[i].angle = 360 - bullet[i].angle;
		}
		else if(bullet[i].x - 5 <= 0)
		{
			bullet[i].x = 5;
			bullet[i].angle = 180 - bullet[i].angle;
		}
		else if (bullet[i].y + 5 >= WINSIZEY)
		{
			bullet[i].y = WINSIZEY - 5;
			bullet[i].angle = 360 - bullet[i].angle;
		}
		
		//밖으로 나가면 재장전되는 코드
		//화면 밖으로 나갈 때 IntersectRect 써보자
		/*if (bullet[i].x - 10 < 0 || bullet[i].x + 10 > WINSIZEX
		|| bullet[i].y - 10 < 0 || bullet[i].y + 10 > WINSIZEY)
		{
			bullet[i].isFire = false;
			break;
		}*/


		bullet[i].x += cosf(bullet[i].angle * (PI / 180)) * bullet[i].bulletSpd;
		bullet[i].y += -sinf(bullet[i].angle* (PI / 180)) * bullet[i].bulletSpd;
		bullet[i].bullet = RectMakeCenter(bullet[i].x, bullet[i].y, 10, 10);
	}
}
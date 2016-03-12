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
	gravity = 0.1f;

	circle = RectMakeCenter(x, y, 100, 100);

	ZeroMemory(bullet, sizeof(tagBullet));
	for (int i = 0; i < BULLETMAX; i++)
	{
		bullet[i].bulletSpd = 3.f;
		bullet[i].bulletPwX = 3.f;
		bullet[i].bulletPwY = 3.f;
	}

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		if (angle <= 180)
		{
			angle += 1.f;
		}
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		if (angle >= 0)
		{
			angle -= 1.f;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (x >= 50)
			x -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (x <= WINSIZEX - 50)
			x += 5;
	}
	
	gunX = cosf(angle*(PI / 180)) * 80 + x;
	gunY = -sinf(angle*(PI / 180)) * 80 + y;
	
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
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
		bullet[i].bulletSpd = 3.f;
		bullet[i].bulletPwX = 3.f;
		bullet[i].bulletPwY = 3.f;
		bullet[i].bullet = RectMakeCenter(bullet[i].x, bullet[i].y, 10, 10);
		break;
	}
}

void gameStudy::bulletMove()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!bullet[i].isFire) continue;
		
		//밖으로 나가면 재장전되는 코드
		//화면 밖으로 나갈 때 IntersectRect 써보자
		if (!IntersectRect(&RectMake(0, 0, 0, 0), &bullet[i].bullet, &RectMake(0, 0, WINSIZEX, WINSIZEY)))
		{
			bullet[i].isFire = false;
			break;
		}

		bullet[i].bulletPwY -= gravity;

		bullet[i].x += cosf(bullet[i].angle * (PI / 180)) * bullet[i].bulletSpd * bullet[i].bulletPwX;
		bullet[i].y += -sinf(bullet[i].angle* (PI / 180)) * bullet[i].bulletSpd * bullet[i].bulletPwY;
		bullet[i].bullet = RectMakeCenter(bullet[i].x, bullet[i].y, 10, 10);
	}
}
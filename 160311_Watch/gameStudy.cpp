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

	GetLocalTime(&st);

	ptHour.x = cosf((90 - ((st.wHour % 12) * 30 + (st.wMinute * 0.5))) * (PI / 180)) * 100 + CENTERX;
	ptHour.y = -sinf((90 - ((st.wHour % 12) * 30 + (st.wMinute * 0.5))) * (PI / 180)) * 100 + CENTERY;
	ptMinute.x = cosf((90 - st.wMinute * 6) * (PI / 180)) * 200 + CENTERX;
	ptMinute.y = -sinf((90 - st.wMinute * 6) * (PI / 180)) * 200 + CENTERY;
	ptSecond.x = cosf((90 - st.wSecond * 6) * (PI / 180)) * 150 + CENTERX;
	ptSecond.y = -sinf((90 - st.wSecond * 6) * (PI / 180)) * 150 + CENTERY;
	
	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	GetLocalTime(&st);

	ptHour.x = cosf((90 - ((st.wHour % 12) * 30 + (st.wMinute * 0.5))) * (PI / 180)) * 100 + CENTERX;
	ptHour.y = -sinf((90 - ((st.wHour % 12) * 30 + (st.wMinute * 0.5))) * (PI / 180)) * 100 + CENTERY;
	ptMinute.x = cosf((90 - st.wMinute * 6) * (PI / 180)) * 200 + CENTERX;
	ptMinute.y = -sinf((90 - st.wMinute * 6) * (PI / 180)) * 200 + CENTERY;
	ptSecond.x = cosf((90 - st.wSecond * 6) * (PI / 180)) * 150 + CENTERX;
	ptSecond.y = -sinf((90 - st.wSecond * 6) * (PI / 180)) * 150 + CENTERY;

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	EllipseMakeCenter(hdc, CENTERX, CENTERY, 500, 500);

	HPEN hourPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	HPEN minPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN secPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	
	HPEN oldPen = (HPEN)SelectObject(hdc, hourPen);

	LineMake(hdc, CENTERX, CENTERY, ptHour.x, ptHour.y);
	
	oldPen = (HPEN)SelectObject(hdc, minPen);
	LineMake(hdc, CENTERX, CENTERY, ptMinute.x, ptMinute.y);

	oldPen = (HPEN)SelectObject(hdc, secPen);
	LineMake(hdc, CENTERX, CENTERY, ptSecond.x, ptSecond.y);

	SelectObject(hdc, oldPen);
	DeleteObject(hourPen);
	DeleteObject(minPen);
	DeleteObject(secPen);
}
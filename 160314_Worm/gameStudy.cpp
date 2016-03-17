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

	mGameStart = true;

	mAngle = 1.57f;
	mSpeed = 2.f;
	mRadius = 10.f;
	mWormCnt = 0;
	mItemX = RND->getFromIntTo(100, WINSIZEX - 100);
	mItemY = RND->getFromIntTo(100, WINSIZEY - 100);

	for (int i = 0; i < WORMMAX; ++i)
	{
		//mWorm[i].x = CENTERX;
		//mWorm[i].y = CENTERY;
		mWorm[i].isTail = false;
		mWorm[i].isMove = false;
	}
	mWorm[0].x = CENTERX;
	mWorm[0].y = CENTERY;
	mWorm[0].isTail = true;
	mWorm[0].isMove = true;

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (mGameStart)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			mAngle += 0.1f;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			mAngle -= 0.1f;
		}

		if (collision())
		{
			mGameStart = false;
		}
		move();
	}
	else
	{
		release();
		if(mWormCnt >= WORMMAX)
			MessageBox(_hWnd, "Won!", "Game Result", MB_OK);
		else
			MessageBox(_hWnd, "Lose!", "Game Result", MB_OK);
		init();
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	for (int i = 0; i < WORMMAX; ++i)
	{
		if (!mWorm[i].isMove) continue;
		EllipseMakeCenter(hdc, mWorm[i].x, mWorm[i].y, mRadius * 2, mRadius * 2);
	}
	EllipseMakeCenter(hdc, mItemX, mItemY, 20, 20);
}

void gameStudy::move()
{
	mWorm[0].x += cosf(mAngle) * mSpeed;
	mWorm[0].y += -sinf(mAngle) * mSpeed;

	for (int i = 1; i < WORMMAX; ++i)
	{
		if (!mWorm[i].isMove) continue;

		float dist = sqrtf((mWorm[i].x - mWorm[i - 1].x) * (mWorm[i].x - mWorm[i - 1].x)
			+ (mWorm[i].y - mWorm[i - 1].y) * (mWorm[i].y - mWorm[i - 1].y));
		float angle = getAngle(mWorm[i].x, mWorm[i].y, mWorm[i - 1].x, mWorm[i - 1].y);
		
		if (dist > mRadius * 2)
		{
			mWorm[i].x += cosf(angle) * mSpeed;
			mWorm[i].y += -sinf(angle) * mSpeed;
		}
	}
}

float gameStudy::getAngle(float x1, float y1, float x2, float y2)
{
	float x = x2 - x1;
	float y = y2 - y1;
	float dist = sqrtf((x * x) + (y * y));

	float angle = acosf( x / dist );

	if (y > 0)
	{
		angle = PI * 2 - angle;
		if (angle >= PI * 2) angle -= PI * 2;
	}

	return angle;
}

bool gameStudy::collision()
{
	float dist1 = sqrtf((mItemX - mWorm[0].x) * (mItemX - mWorm[0].x)
		+ (mItemY - mWorm[0].y) * (mItemY - mWorm[0].y));

	if (dist1 < mRadius * 2)
	{
		mWormCnt++;
		if (mWormCnt >= WORMMAX)
			return true;
		mWorm[mWormCnt].isMove = true;
		mWorm[mWormCnt].x = mWorm[mWormCnt - 1].x + mRadius + cosf(PI - mAngle) * mSpeed;
		mWorm[mWormCnt].y = mWorm[mWormCnt - 1].y + mRadius - sinf(PI - mAngle) * mSpeed;
		mItemX = RND->getFromIntTo(100, WINSIZEX - 100);
		mItemY = RND->getFromIntTo(100, WINSIZEY - 100);
	}

	//3번째 애부터는 충돌하면 죽는다
	for (int i = 3; i < WORMMAX; ++i)
	{
		if (!mWorm[i].isMove) continue;

		float dist2 = sqrtf((mWorm[i].x - mWorm[0].x) * (mWorm[i].x - mWorm[0].x)
			+ (mWorm[i].y - mWorm[0].y) * (mWorm[i].y - mWorm[0].y));

		if (dist2 < mRadius * 2)
			return true;
	}
	//머리가 화면 밖으로 나가면
	if (mWorm[0].x - mRadius < 0 || mWorm[0].x + mRadius > WINSIZEX
		|| mWorm[0].y - mRadius < 0 || mWorm[0].y + mRadius > WINSIZEY)
		return true;
	return false;
}
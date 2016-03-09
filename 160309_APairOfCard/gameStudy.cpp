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

	timeCnt = openCnt = first = second = clearCnt = 0;

	_GameStart = true;

	for (int i = 0; i < COLORNUM; ++i)
	{
		mColor[i].r = RND->getInt(255);
		mColor[i].g = RND->getInt(255);
		mColor[i].b = RND->getInt(255);
		mColor[i].cnt = 0;
	}

	for (int i = 0; i < CARDNUM; ++i)
	{
		mCard[i].isBlind = true;
		mCard[i].color = mColor[i % 10];
	}

	shuffle(mCard);

	for (int i = 0; i < CARDNUM; ++i)
	{
		mCard[i].card = RectMake(WINSIZEX / 5 * ((i + 1) % 5) + 50, WINSIZEY / 4 * ((i + 1) % 4) + 30, 60, 90);
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
			for (int i = 0; i < CARDNUM; ++i)
			{
				if (PtInRect(&mCard[i].card, _ptMouse))
				{
					if (!mCard[i].isBlind) continue;
					if (openCnt == 0)
					{
						mCard[i].isBlind = false;
						openCnt++;
						first = i;		//첫 번째 뒤집은 카드의 인덱스를 저장
						break;
					}
					else if (openCnt == 1)
					{
						mCard[i].isBlind = false;
						openCnt++;
						second = i;		//두 번째 뒤집은 카드의 인덱스를 저장
						break;
					}
				}
			}
		}

		//두 개를 뒤집었으면
		if (openCnt == 2)
		{
			//두 카드의 색상이 같으면
			if (mCard[first].color.r == mCard[second].color.r
				&& mCard[first].color.g == mCard[second].color.g
				&& mCard[first].color.b == mCard[second].color.b)
			{
				clearCnt++;
				openCnt = 0;
			}
			else
			{
				openCnt++;
			}
		}
		else if (openCnt == 3)
		{
			timeCnt++;
			if (timeCnt % 50 == 0)
			{
				mCard[first].isBlind = true;
				mCard[second].isBlind = true;
				openCnt = 0;
				timeCnt = 0;
			}
		}

		if (clearCnt == 10)
		{
			_GameStart = false;
		}
	}
	else
	{
		if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
			init();
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	HBRUSH MyBrush, OldBrush;
	MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

	for (int i = 0; i < CARDNUM; ++i)
	{
		if (mCard[i].isBlind && _GameStart)
		{
			SetDCBrushColor(hdc, RGB(255, 255, 255));
			Rectangle(hdc, mCard[i].card.left, mCard[i].card.top, mCard[i].card.right, mCard[i].card.bottom);
		}
		else if (!mCard[i].isBlind && _GameStart)
		{
			SetDCBrushColor(hdc, RGB(mCard[i].color.r, mCard[i].color.g, mCard[i].color.b));
			Rectangle(hdc, mCard[i].card.left, mCard[i].card.top, mCard[i].card.right, mCard[i].card.bottom);
		}
	}
	
	if (!_GameStart)
	{
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, CENTERX, CENTERY, "Press Enter Key To Restart", strlen("Press Enter Key To Restart"));
	}

	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);
}

void gameStudy::shuffle(tagCard * card)
{
	int dest, sour;
	tagCard tmp;

	for (int i = 0; i < 50; ++i)
	{
		dest = RND->getInt(CARDNUM);
		sour = RND->getInt(CARDNUM);

		tmp = card[dest];
		card[dest] = card[sour];
		card[sour] = tmp;
	}
}

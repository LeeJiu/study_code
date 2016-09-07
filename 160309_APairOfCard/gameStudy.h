#pragma once

#include "gameNode.h"

/*#define CARDNUM 20*/
const int CardNum = 20;
const int ColorNum = CardNum / 2;
/*#define COLORNUM 10*/

struct tagColor
{
	int r, g, b, cnt;
};

struct tagCard
{
	tagColor color;
	RECT card;
	bool isBlind;
};

class gameStudy : public gameNode
{
private:
	tagColor mColor[ColorNum];
	tagCard mCard[CardNum];
	int timeCnt, openCnt, clearCnt, first, second;
	bool _GameStart;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void shuffle(tagCard* card);
};


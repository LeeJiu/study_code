#pragma once
#include "gameNode.h"

#define ROW 10
#define COLUMN 6

enum eState
{
	START, NORMAL, END
};

struct tagNode
{
	int x, y;
	tagNode* next;
	tagNode* down;
	eState state;
};

struct tagPlayer
{
	RECT player;
	int x, y;
	int num;
	tagNode* next;
	bool isNext;
	bool isEnd;
};

class ladder : public gameNode
{
private:
	tagNode _node[ROW][COLUMN];
	tagPlayer _player[COLUMN];

	int _moveCnt;
	bool _isMove;

public:
	ladder();
	~ladder();

	HRESULT init();
	void release();
	void update();
	void render();

	void move();
};


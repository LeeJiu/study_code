#pragma once
#include "gameNode.h"
#include <algorithm>

enum TILETYPE
{
	START, END, BLOCK, CHECK, OPEN, NONE
};

struct tagTile
{
	tagTile* parent;
	RECT rc;
	TILETYPE type;
	POINT pos;
	int f;
	int g;
	int h;
};


class tile : public gameNode
{
private:
	tagTile _tile[TILEROW][TILECOL];

	int _startX, _startY, _endX, _endY;
	bool _remove, _start, _end;

	vector<tagTile*> _vOpenList;
	vector<tagTile*>::iterator _viOpenList;

	vector<tagTile*> _vCloseList;
	vector<tagTile*>::iterator _viCloseList;


public:
	tile();
	~tile();

	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();
	void inputCloseList();
	void checkOpenList(int x, int y);
	bool checkCloseList(int x, int y);
	void searchVicinity();
	
	void reset();

	void drawRoad(tagTile* tile);

	static bool Compare(tagTile* start, tagTile* end)
	{
		return start->f < end->f;
	}
};


#pragma once

#pragma warning(disable : 4996)

#include "gameNode.h"
#include "button.h"

struct tagTile
{
	image* tile;
	POINT imagePos;		//가져올 이미지의 좌표
	POINT screenPos;	//화면 상의 좌표
	int index;
	int tileIdx;
	bool draw;
};


class mapTool : public gameNode
{
private:
	image* _tileImage;

	vector<tagTile> _vTile;
	vector<tagTile>::iterator _viTile;

	RECT rc[TILEMAX];

	button* _btLeft;
	button* _btRight;

	int _tileFrameX, _tileFrameY;

public:
	mapTool();
	~mapTool();

	HRESULT init();
	void release();
	void update();
	void render();

	//=====================추가할 함수=====================
	void keyControl();
	void changeTile();
	void inputTile(int idx);

	void saveMapData();
	void loadMapData();

	//=====================버		튼=====================
	static int _tileIndex;
	
	static void onLeftButton();
	static void onRightButton();
};


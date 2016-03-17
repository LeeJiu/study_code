#pragma once

#include "gameNode.h"

#define PUZZLENUM 9

struct tagPuzzle
{
	RECT puzzle;
	int idx;
};


class gameStudy : public gameNode
{
private:
	image* _background;
	tagPuzzle _puzzle[PUZZLENUM];
	int clearCnt;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	int shuffle(tagPuzzle * pz);
};
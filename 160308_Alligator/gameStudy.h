#pragma once

#include "gameNode.h"
#define TEETHMAX 20
struct tagTeeth
{
	RECT _rcTooth;
	bool _isBoom;
	bool _isBlind;
};

class gameStudy : public gameNode
{
private:
	tagTeeth _tooth[TEETHMAX];
	int _randNum, _height;
	bool _GameStart;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


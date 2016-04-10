#pragma once
#include "gameNode.h"

class balloon;

class player : public gameNode
{
private:
	image* _targetImage;
	RECT _leftTarget, _rightTarget;
	POINT _leftPt, _rightPt;
	int _score;


	balloon* _balloon;

public:
	player();
	~player();

	HRESULT init(const char* imageName);
	void release();
	void update();
	void render();

	void move();
	void collision(bool isRight);
	void score(int arrNum);

	void setBalloonMemoryLink(balloon* balloon) { _balloon = balloon; }
};


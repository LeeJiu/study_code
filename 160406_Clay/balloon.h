#pragma once
#include "gameNode.h"

enum BALLOONTYPE
{
	ORIGINAL,
	DOUBLE,
	BOMB
};

struct tagBalloon
{
	image* image;
	RECT rc;
	BALLOONTYPE type;
	float x, y;
	float angle;
	float speed;
	float gravityPw;
	bool bomb;
	bool fire;
};

class balloon : public gameNode
{
private:
	vector<tagBalloon> _vBalloon;
	vector<tagBalloon>::iterator _viBalloon;

	int _balloonMax, _count, _currentFrameX, _currentFrameY;
	float _time;
	float _gravity;
	bool _isRight;

public:
	balloon();
	~balloon();

	HRESULT init(const char* imageName, int balloonMax);
	void release();
	void update();
	void render();

	void fire();
	void move();
	void setFrame();
	void setBombImage(const char* imageName, int arrNum);

	vector<tagBalloon>& getVBalloon() { return _vBalloon; }
	vector<tagBalloon>::iterator getVIBalloon() { return _viBalloon; }
};


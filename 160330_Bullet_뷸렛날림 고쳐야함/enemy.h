#pragma once

#include "gameNode.h"

enum tagPattern
{
	PATTERN_1,
	PATTERN_2
};

class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;

	tagPattern _pattern;

	int _currentFrameX;
	int _currentFrameY;

	int _count;
	int _fireCount;
	int _rndFireCount;

	bool _isBoss;

public:
	enemy();
	~enemy();

	HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	void release();
	void update();
	void render();

	virtual void move();
	void draw();

	virtual bool bulletCountFire();
	virtual bool isBoss() { return _isBoss; }

	inline RECT getRect() { return _rc; }
	virtual void setPattern(tagPattern pattern) { _pattern = pattern; }
	virtual tagPattern getPattern() { return _pattern; }
};


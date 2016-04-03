#pragma once
#include "enemy.h"



class boss : public enemy
{
public:
	boss();
	~boss();

	HRESULT init(const char* imageName, POINT position);
	void update();
	bool bulletCountFire();
	bool isBoss() { return _isBoss; }
	void setPattern(tagPattern pattern) { _pattern = pattern; }
	tagPattern getPattern() { return _pattern; }
};


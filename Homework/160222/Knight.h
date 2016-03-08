#pragma once
#include "Human.h"
class Knight :
	public Human
{
private:
	int _chivalry;

public:
	Knight();
	Knight(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int luk, int dex, int chivalry);
	~Knight();

	void ShowInfo() const;
};


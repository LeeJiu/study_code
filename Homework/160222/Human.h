#pragma once
#include "Race.h"
class Human :
	public Race
{
protected:
	int _luk;
	int _dex;

public:
	Human();
	Human(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int luk, int dex);
	~Human();

	void ShowInfo() const;
};


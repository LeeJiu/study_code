#pragma once
#include "Human.h"
class Cleric :
	public Human
{
private:
	int _holyPow;

public:
	Cleric();
	Cleric(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int luk, int dex, int holyPow);
	~Cleric();

	void ShowInfo() const;
};


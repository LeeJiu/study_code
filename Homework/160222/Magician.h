#pragma once
#include "Human.h"
class Magician :
	public Human
{
private:
	int _intell;

public:
	Magician();
	Magician(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int luk, int dex, int intell);
	~Magician();

	void ShowInfo() const;
};


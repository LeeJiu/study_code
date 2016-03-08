#pragma once
#include "Elf.h"
class Summoner :
	public Elf
{
private:
	int _spiritAff;

public:
	Summoner();
	Summoner(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireAff, int waterAff, int earthAff, int windAff, int spiritAff);
	~Summoner();

	void ShowInfo() const;
};


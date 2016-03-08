#pragma once
#include "Race.h"
class Elf :
	public Race
{
protected:
	int _fireAff;
	int _waterAff;
	int _earthAff;
	int _windAff;

public:
	Elf();
	Elf(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireAff, int waterAff, int earthAff, int windAff);
	~Elf();

	void ShowInfo() const;
};


#pragma once
#include "Elf.h"
class Archer :
	public Elf
{
private:
	int _accuracy;

public:
	Archer();
	Archer(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireAff, int waterAff, int earthAff, int windAff, int accuracy);
	~Archer();

	void ShowInfo() const;
};


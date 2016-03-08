#pragma once
#include "Elf.h"
class Druid :
	public Elf
{
private:
	int _cure;

public:
	Druid();
	Druid(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireAff, int waterAff, int earthAff, int windAff, int cure);
	~Druid();

	void ShowInfo() const;
};


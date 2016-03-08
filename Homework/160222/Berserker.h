#pragma once
#include "Giant.h"
class Berserker :
	public Giant
{
private:
	int _critical;

public:
	Berserker();
	Berserker(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireRes, int waterRes, int earthRes, int windRes, int critical);
	~Berserker();

	void ShowInfo() const;
};


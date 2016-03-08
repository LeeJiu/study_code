#pragma once
#include "Giant.h"
class Fighter :
	public Giant
{
private:
	int _agility;

public:
	Fighter();
	Fighter(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireRes, int waterRes, int earthRes, int windRes, int agility);
	~Fighter();

	void ShowInfo() const;
};


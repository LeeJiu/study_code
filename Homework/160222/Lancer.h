#pragma once
#include "Giant.h"
class Lancer :
	public Giant
{
private:
	int _stamina;

public:
	Lancer();
	Lancer(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int fireRes, int waterRes, int earthRes, int windRes, int stamina);
	~Lancer();

	void ShowInfo() const;
};


#pragma once
#include "Race.h"
class Giant :
	public Race
{
protected:
	int _fireRes;
	int _waterRes;
	int _earthRes;
	int _windRes;

public:
	Giant();
	Giant(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def
		, int _fireRes, int _waterRes, int _earthRes, int _windRes);
	~Giant();

	void ShowInfo() const;
};


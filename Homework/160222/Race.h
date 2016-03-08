#pragma once
#include <iostream>
using namespace std;


class Race
{
protected:
	char * _raceName;
	int _pow;
	int _def;
	float _speed;
	float _attSpd;
	int _hp;
	int _mp;
	char * _introduce;

public:
	Race();
	Race(const char * raceName, char* intro, int hp, int mp, float spd, float attspd, int pow, int def);
	virtual ~Race();

	virtual void ShowInfo() const;
};


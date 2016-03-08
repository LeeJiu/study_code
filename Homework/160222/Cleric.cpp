#include "Cleric.h"



Cleric::Cleric()
{
	cout << "Cleric Create" << endl;
}

Cleric::Cleric(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int luk, int dex, int holyPow)
	: Human(raceName, intro, hp, mp, spd, attspd, pow, def, luk, dex), _holyPow(holyPow)
{
	cout << "Cleric Create" << endl;
}


Cleric::~Cleric()
{
	cout << "Cleric Destroy" << endl;
}

void Cleric::ShowInfo() const
{
	cout << "���� �̸� : " << _raceName << endl;
	cout << "���� Ư�� : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
	cout << "==================�ΰ� ���� Ư��===================" << endl;
	cout << "luk : " << _luk << endl;
	cout << "dex : " << _dex << endl;
	cout << "=================������ ���� Ư��==================" << endl;
	cout << "�ż��� : " << _holyPow << endl;
}

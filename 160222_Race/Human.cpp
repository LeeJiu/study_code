#include "Human.h"



Human::Human()
{
	cout << "Human Create" << endl;
}

Human::Human(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int luk, int dex)
	: Race(raceName, intro, hp, mp, spd, attspd, pow, def), _luk(luk), _dex(dex)
{
	cout << "Human Create" << endl;
}


Human::~Human()
{
	cout << "Human Destroy" << endl;
}

void Human::ShowInfo() const
{
	cout << "종족 이름 : " << _raceName << endl;
	cout << "종족 특성 : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
	cout << "==================인간 종족 특성===================" << endl;
	cout << "luk : " << _luk << endl;
	cout << "dex : " << _dex << endl;
}

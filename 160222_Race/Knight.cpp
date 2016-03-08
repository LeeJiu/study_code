#include "Knight.h"



Knight::Knight()
{
	cout << "Knight Create" << endl;
}

Knight::Knight(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int luk, int dex, int chivalry)
	: Human(raceName, intro, hp, mp, spd, attspd, pow, def, luk, dex), _chivalry(chivalry)
{
	cout << "Knight Create" << endl;
}


Knight::~Knight()
{
	cout << "Knight Destroy" << endl;
}

void Knight::ShowInfo() const
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
	cout << "==================기사 직업 특성===================" << endl;
	cout << "기사도 : " << _chivalry << endl;
}

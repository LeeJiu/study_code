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
	cout << "==================��� ���� Ư��===================" << endl;
	cout << "��絵 : " << _chivalry << endl;
}

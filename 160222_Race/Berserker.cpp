#include "Berserker.h"



Berserker::Berserker()
{
	cout << "Berserker Create" << endl;
}

Berserker::Berserker(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fireRes, int waterRes, int earthRes, int windRes, int critical)
	: Giant(raceName, intro, hp, mp, spd, attspd, pow, def, fireRes, waterRes, earthRes, windRes), _critical(critical)
{
	cout << "Berserker Create" << endl;
}


Berserker::~Berserker()
{
	cout << "Berserker Destroy" << endl;
}

void Berserker::ShowInfo() const
{
	cout << "종족 이름 : " << _raceName << endl;
	cout << "종족 특성 : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
	cout << "================자이언트 종족 특성=================" << endl;
	cout << "불 저항력 : " << _fireRes << endl;
	cout << "물 저항력 : " << _waterRes << endl;
	cout << "땅 저항력 : " << _earthRes << endl;
	cout << "바람 저항력 : " << _windRes << endl;
	cout << "=================광전사 직업 특성==================" << endl;
	cout << "치명률 : " << _critical << endl;
}

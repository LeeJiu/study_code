#include "Druid.h"



Druid::Druid()
{
	cout << "Druid Create" << endl;
}

Druid::Druid(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fireAff, int waterAff, int earthAff, int windAff, int cure)
	: Elf(raceName, intro, hp, mp, spd, attspd, pow, def, fireAff, waterAff, earthAff, windAff), _cure(cure)
{
	cout << "Druid Create" << endl;
}


Druid::~Druid()
{
	cout << "Druid Destroy" << endl;
}

void Druid::ShowInfo() const
{
	cout << "종족 이름 : " << _raceName << endl;
	cout << "종족 특성 : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
	cout << "==================엘프 종족 특성===================" << endl;
	cout << "불 친화력 : " << _fireAff << endl;
	cout << "물 친화력 : " << _waterAff << endl;
	cout << "땅 친화력 : " << _earthAff << endl;
	cout << "바람 친화력 : " << _windAff << endl;
	cout << "================드루이드 직업 특성=================" << endl;
	cout << "치유력 : " << _cure << endl;
}

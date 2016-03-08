#include "Summoner.h"



Summoner::Summoner()
{
	cout << "Summoner Create" << endl;
}

Summoner::Summoner(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fireAff, int waterAff, int earthAff, int windAff, int spiritAff)
	: Elf(raceName, intro, hp, mp, spd, attspd, pow, def, fireAff, waterAff, earthAff, windAff), _spiritAff(spiritAff)
{
	cout << "Summoner Create" << endl;
}


Summoner::~Summoner()
{
	cout << "Summoner Destroy" << endl;
}

void Summoner::ShowInfo() const
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
	cout << "================정령술사 직업 특성=================" << endl;
	cout << "정령 친화력 : " << _spiritAff << endl;
}

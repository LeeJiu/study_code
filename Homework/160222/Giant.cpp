#include "Giant.h"



Giant::Giant()
{
	cout << "Giant Create" << endl;
}

Giant::Giant(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fire, int water, int earth, int wind)
	:Race(raceName, intro, hp, mp, spd, attspd, pow, def), _fireRes(fire), _waterRes(water), _earthRes(earth), _windRes(wind)
{
	cout << "Giant Create" << endl;
}


Giant::~Giant()
{
	cout << "Giant Destroy" << endl;
}

void Giant::ShowInfo() const
{
	cout << "���� �̸� : " << _raceName << endl;
	cout << "���� Ư�� : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
	cout << "================���̾�Ʈ ���� Ư��=================" << endl;
	cout << "�� ���׷� : " << _fireRes << endl;
	cout << "�� ���׷� : " << _waterRes << endl;
	cout << "�� ���׷� : " << _earthRes << endl;
	cout << "�ٶ� ���׷� : " << _windRes << endl;
}

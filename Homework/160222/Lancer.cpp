#include "Lancer.h"



Lancer::Lancer()
{
	cout << "Lancer Create" << endl;
}

Lancer::Lancer(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fireRes, int waterRes, int earthRes, int windRes, int stamina)
	: Giant(raceName, intro, hp, mp, spd, attspd, pow, def, fireRes, waterRes, earthRes, windRes), _stamina(stamina)
{
	cout << "Lancer Create" << endl;
}


Lancer::~Lancer()
{
	cout << "Lancer Destroy" << endl;
}

void Lancer::ShowInfo() const
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
	cout << "==================���� ���� Ư��===================" << endl;
	cout << "�ٷ� : " << _stamina << endl;
}

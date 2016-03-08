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
	cout << "���� �̸� : " << _raceName << endl;
	cout << "���� Ư�� : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
	cout << "==================���� ���� Ư��===================" << endl;
	cout << "�� ģȭ�� : " << _fireAff << endl;
	cout << "�� ģȭ�� : " << _waterAff << endl;
	cout << "�� ģȭ�� : " << _earthAff << endl;
	cout << "�ٶ� ģȭ�� : " << _windAff << endl;
	cout << "================���ɼ��� ���� Ư��=================" << endl;
	cout << "���� ģȭ�� : " << _spiritAff << endl;
}

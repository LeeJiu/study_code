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
	cout << "================����̵� ���� Ư��=================" << endl;
	cout << "ġ���� : " << _cure << endl;
}

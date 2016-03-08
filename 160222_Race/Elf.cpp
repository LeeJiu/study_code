#include "Elf.h"



Elf::Elf()
{
	cout << "Elf Create" << endl;
}

Elf::Elf(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fireAff, int waterAff, int earthAff, int windAff)
	: Race(raceName, intro, hp, mp, spd, attspd, pow, def)
	, _fireAff(fireAff), _waterAff(waterAff), _earthAff(earthAff), _windAff(windAff)
{
	cout << "Elf Create" << endl;
}


Elf::~Elf()
{
	cout << "Elf Destroy" << endl;
}

void Elf::ShowInfo() const
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
}

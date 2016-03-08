#include "Archer.h"



Archer::Archer()
{
	cout << "Archer Create" << endl;
}

Archer::Archer(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def
	, int fireAff, int waterAff, int earthAff, int windAff, int accuracy)
	: Elf(raceName, intro, hp, mp, spd, attspd, pow, def, fireAff, waterAff, earthAff, windAff), _accuracy(accuracy)
{
	cout << "Archer Create" << endl;
}



Archer::~Archer()
{
	cout << "Archer Destroy" << endl;
}

void Archer::ShowInfo() const
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
	cout << "==================�ü� ���� Ư��===================" << endl;
	cout << "���߷� : " << _accuracy << endl;
}

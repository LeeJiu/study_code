#include "Race.h"



Race::Race() : _introduce("������ ����. ��� ���������� ���̰� �����ϴ�.")
, _hp(0), _mp(100000), _pow(0), _def(0), _speed(0), _attSpd(0)
{
	int len = strlen("������ ����");
	_raceName = new char[len + 1];
	strcpy_s(_raceName, len + 1, "������ ����");

	cout << "Race Create" << endl;
}

Race::Race(const char * raceName, char * intro, int hp, int mp, float spd, float attspd, int pow, int def)
	: _introduce(intro)
	, _hp(hp), _mp(mp), _pow(pow), _def(def), _speed(spd), _attSpd(attspd)
{
	int len = strlen(raceName);
	_raceName = new char[len + 1];
	strcpy_s(_raceName, len + 1, raceName);

	cout << "Race Create" << endl;
}


Race::~Race()
{
	delete[] _raceName;
	cout << "Race Destroy" << endl;
}

void Race::ShowInfo() const
{
	cout << "���� �̸� : " << _raceName << endl;
	cout << "���� Ư�� : " << _introduce << endl;
	cout << "HP : " << _hp << endl;
	cout << "MP : " << _mp << endl;
	cout << "pow : " << _pow << endl;
	cout << "def : " << _def << endl;
	cout << "spd : " << _speed << endl;
	cout << "attspd : " << _attSpd << endl;
}

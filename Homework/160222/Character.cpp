#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
	delete _character;
}

void Character::Create()
{
	int selRace, job;
	int luk, dex;
	int fireAff, waterAff, earthAff, windAff;
	int fireRes, waterRes, earthRes, windRes;

	SetBasicInfo();

	cout << "���� ����(1 to �ΰ�, 2 to ����, 3 to ���̾�Ʈ) : ";
	cin >> selRace;
	
	switch (selRace)
	{
	case 1:
		cout << "[�ΰ� Ư��]" << endl;
		cout << "luk �Է� : "; cin >> luk;
		cout << "dex �Է� : "; cin >> dex;
		cout << "�ΰ� ���� ����(1 to ���, 2 to ������, 3 to ������) : "; cin >> job;
		if (job == 1)
		{
			int chivalry;
			cout << "��絵 : ";
			cin >> chivalry;
			_character = new Knight("�ΰ�", "������ ���ɼ��� ����", _hp, _mp, _speed, _attSpd, _pow, _def, luk, dex, chivalry);
		}
		else if (job == 2)
		{
			int intell;
			cout << "���� : ";
			cin >> intell;
			_character = new Magician("�ΰ�", "������ ���ɼ��� ����", _hp, _mp, _speed, _attSpd, _pow, _def, luk, dex, intell);
		}
		else if (job == 3)
		{
			int holyPow;
			cout << "�ż��� : ";
			cin >> holyPow;
			_character = new Cleric("�ΰ�", "������ ���ɼ��� ����", _hp, _mp, _speed, _attSpd, _pow, _def, luk, dex, holyPow);
		}
		break;
	case 2:
		cout << "[���� Ư��]" << endl;
		cout << "�� ģȭ�� �Է� : "; cin >> fireAff;
		cout << "�� ģȭ�� �Է� : "; cin >> waterAff;
		cout << "�� ģȭ�� �Է� : "; cin >> earthAff;
		cout << "�ٶ� ģȭ�� �Է� : "; cin >> windAff;
		cout << "���� ���� ����(1 to �ü�, 2 to ���ɼ���, 3 to ����̵�) : "; cin >> job;
		if (job == 1)
		{
			int accuracy;
			cout << "���߷� : ";
			cin >> accuracy;
			_character = new Archer("����", "������ �Ƹ��ٿ��� ����", _hp, _mp, _speed, _attSpd, _pow, _def, fireAff, waterAff, earthAff, windAff, accuracy);
		}
		else if (job == 2)
		{
			int spiritAff;
			cout << "���� ģȭ�� : ";
			cin >> spiritAff;
			_character = new Summoner("����", "������ �Ƹ��ٿ��� ����", _hp, _mp, _speed, _attSpd, _pow, _def, fireAff, waterAff, earthAff, windAff, spiritAff);
		}
		else if (job == 3)
		{
			int cure;
			cout << "ġ���� : ";
			cin >> cure;
			_character = new Druid("����", "������ �Ƹ��ٿ��� ����", _hp, _mp, _speed, _attSpd, _pow, _def, fireAff, waterAff, earthAff, windAff, cure);
		}
		break;
	case 3:
		cout << "[���̾�Ʈ Ư��]" << endl;
		cout << "�� ���׷� �Է� : "; cin >> fireRes;
		cout << "�� ���׷� �Է� : "; cin >> waterRes;
		cout << "�� ���׷� �Է� : "; cin >> earthRes;
		cout << "�ٶ� ���׷� �Է� : "; cin >> windRes;
		if (job == 1)
		{
			int critical;
			cout << "ġ��� : ";
			cin >> critical;
			_character = new Berserker("���̾�Ʈ", "���԰� ������� ����", _hp, _mp, _speed, _attSpd, _pow, _def, fireRes, waterRes, earthRes, windRes, critical);
		}
		else if (job == 2)
		{
			int agility;
			cout << "��ø�� : ";
			cin >> agility;
			_character = new Berserker("���̾�Ʈ", "���԰� ������� ����", _hp, _mp, _speed, _attSpd, _pow, _def, fireRes, waterRes, earthRes, windRes, agility);
		}
		else if (job == 3)
		{
			int stamina;
			cout << "�ٷ� : ";
			cin >> stamina;
			_character = new Berserker("���̾�Ʈ", "���԰� ������� ����", _hp, _mp, _speed, _attSpd, _pow, _def, fireRes, waterRes, earthRes, windRes, stamina);
		}
		break;
	}
}

void Character::SetBasicInfo()
{
	cout << "[��� ������ ����� �ɷ�ġ]" << endl;
	cout << "HP : ";
	cin >> _hp;
	cout << "MP : ";
	cin >> _mp;
	cout << "pow : ";
	cin >> _pow;
	cout << "def : ";
	cin >> _def;
	cout << "spd : ";
	cin >> _speed;
	cout << "attspd : ";
	cin >> _attSpd;
}

void Character::ShowAllInfo() const
{
	_character->ShowInfo();
}

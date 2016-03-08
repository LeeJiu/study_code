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

	cout << "종족 선택(1 to 인간, 2 to 엘프, 3 to 자이언트) : ";
	cin >> selRace;
	
	switch (selRace)
	{
	case 1:
		cout << "[인간 특성]" << endl;
		cout << "luk 입력 : "; cin >> luk;
		cout << "dex 입력 : "; cin >> dex;
		cout << "인간 직업 선택(1 to 기사, 2 to 마법사, 3 to 성직자) : "; cin >> job;
		if (job == 1)
		{
			int chivalry;
			cout << "기사도 : ";
			cin >> chivalry;
			_character = new Knight("인간", "무한한 가능성의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, luk, dex, chivalry);
		}
		else if (job == 2)
		{
			int intell;
			cout << "지능 : ";
			cin >> intell;
			_character = new Magician("인간", "무한한 가능성의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, luk, dex, intell);
		}
		else if (job == 3)
		{
			int holyPow;
			cout << "신성력 : ";
			cin >> holyPow;
			_character = new Cleric("인간", "무한한 가능성의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, luk, dex, holyPow);
		}
		break;
	case 2:
		cout << "[엘프 특성]" << endl;
		cout << "불 친화력 입력 : "; cin >> fireAff;
		cout << "물 친화력 입력 : "; cin >> waterAff;
		cout << "땅 친화력 입력 : "; cin >> earthAff;
		cout << "바람 친화력 입력 : "; cin >> windAff;
		cout << "엘프 직업 선택(1 to 궁수, 2 to 정령술사, 3 to 드루이드) : "; cin >> job;
		if (job == 1)
		{
			int accuracy;
			cout << "명중률 : ";
			cin >> accuracy;
			_character = new Archer("엘프", "지혜와 아름다움의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, fireAff, waterAff, earthAff, windAff, accuracy);
		}
		else if (job == 2)
		{
			int spiritAff;
			cout << "정령 친화력 : ";
			cin >> spiritAff;
			_character = new Summoner("엘프", "지혜와 아름다움의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, fireAff, waterAff, earthAff, windAff, spiritAff);
		}
		else if (job == 3)
		{
			int cure;
			cout << "치유력 : ";
			cin >> cure;
			_character = new Druid("엘프", "지혜와 아름다움의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, fireAff, waterAff, earthAff, windAff, cure);
		}
		break;
	case 3:
		cout << "[자이언트 특성]" << endl;
		cout << "불 저항력 입력 : "; cin >> fireRes;
		cout << "물 저항력 입력 : "; cin >> waterRes;
		cout << "땅 저항력 입력 : "; cin >> earthRes;
		cout << "바람 저항력 입력 : "; cin >> windRes;
		if (job == 1)
		{
			int critical;
			cout << "치명률 : ";
			cin >> critical;
			_character = new Berserker("자이언트", "강함과 용맹함의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, fireRes, waterRes, earthRes, windRes, critical);
		}
		else if (job == 2)
		{
			int agility;
			cout << "민첩성 : ";
			cin >> agility;
			_character = new Berserker("자이언트", "강함과 용맹함의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, fireRes, waterRes, earthRes, windRes, agility);
		}
		else if (job == 3)
		{
			int stamina;
			cout << "근력 : ";
			cin >> stamina;
			_character = new Berserker("자이언트", "강함과 용맹함의 종족", _hp, _mp, _speed, _attSpd, _pow, _def, fireRes, waterRes, earthRes, windRes, stamina);
		}
		break;
	}
}

void Character::SetBasicInfo()
{
	cout << "[모든 종족의 공통된 능력치]" << endl;
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

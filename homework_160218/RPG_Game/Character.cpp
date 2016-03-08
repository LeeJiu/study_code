#include "Character.h"


Character::Character(char* pName) : _hp(1000), _mp(1000), _skillNum(0)
{
	_name = new char[strlen(pName) + 1];
	strcpy_s(_name, strlen(pName) + 1, pName);
}

Character::~Character()
{
	delete[] _name;
	for (int i = 0; i < 3; i++)
		delete _skill[i];
}

void Character::SetSkill(char * pSkillName, int nMin, int nMax)
{
	if (_skillNum >= 3)
	{
		cout << "더 이상 스킬을 추가할 수 없습니다." << endl;
		return;
	}
	_skill[_skillNum++] = new Skill(pSkillName, nMin, nMax);
}

void Character::ShowSkillList() const
{
	char* skill;
	int min, max;
	cout << "\t[스킬 목록]" << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		skill = _skill[i]->GetSkillName();
		min = _skill[i]->GetMinDamege();
		max = _skill[i]->GetMaxDamege();
		cout << i + 1 << ". " << skill << " (min~max) : " << min << " ~ " << max << endl;
	}
	cout << endl << endl;
}

int Character::GetHp() const
{
	return _hp;
}

int Character::GetMp() const
{
	return _mp;
}

char * Character::GetName() const
{
	return _name;
}

char * Character::GetSkill()
{
	srand((size_t)time(NULL));

	char * skill;
	int randNum = rand() % 3;		//랜덤으로 스킬을 가져오기 위해서 0~2

	skill = _skill[randNum]->GetSkillName();

	return skill;
}

void Character::Attack(Character & pEnemy, char * pSkill)
{
	srand((size_t)time(NULL));

	if (pEnemy.isDead(pEnemy))
		return;

	char* pCmpSkill;
	int damege, mp;
	int minDam, maxDam;
	bool mpCheck;
	//스킬 이름 찾기
	for (int i = 0; i < 3; i++)
	{
		pCmpSkill = _skill[i]->GetSkillName();		//스킬 이름 저장
		if (strcmp(pSkill, pCmpSkill) == 0)
		{
			minDam = _skill[i]->GetMinDamege();
			maxDam = _skill[i]->GetMaxDamege();
			damege = rand() % (maxDam - minDam) + minDam;		//랜덤 데미지
			mp = minDam * 0.5;		//마나 소모량 = minDam*0.5
			break;
		}
	}

	mpCheck = this->ConsumeMp(mp);	//마나 사용

	if(!mpCheck)	//마나 부족
		pEnemy.Hit(0);
	else
		pEnemy.Hit(damege);			//적 체력 감소


	cout << "MP " << mp << "을 소모합니다. 남은 MP : " << this->GetMp() << endl << endl;
	cout << "===============================================================" << endl;
	cout << damege << " Hit!!" << endl;
	cout << pEnemy.GetName() << "의 남은 HP : " << pEnemy.GetHp() << endl;
	
	Sleep(2000);
	system("cls");
}

void Character::Hit(int nDamege)
{
	if (nDamege > _hp)
		_hp = 0;
	else
	{
		_hp -= nDamege;
		_mp += nDamege * 0.2;		//맞을 때마다 데미지의 20%를 마나회복
	}
}

bool Character::ConsumeMp(int nMp)
{
	if (nMp > _mp)
	{
		cout << "마나가 부족합니다." << endl;
		return false;
	}
	else
	{ 
		_mp -= nMp;
		return true;
	}
}

bool Character::isDead(Character & pEnemy)
{
	if (pEnemy.GetHp() <= 0)
		return true;
	else return false;
}
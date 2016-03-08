#include "Skill.h"


Skill::Skill(char * pSkillName, int nMin, int nMax) 
	: _minDam(nMin), _maxDam(nMax)
{
	_skillName = new char[strlen(pSkillName) + 1];
	strcpy_s(_skillName, strlen(pSkillName) + 1, pSkillName);

	//cout << _skillName << ", " << _minDam << ", " << _maxDam << endl;	//스킬 초기화 확인용
}

Skill::~Skill()
{
	delete[] _skillName;
}

char * Skill::GetSkillName() const
{
	return _skillName;
}

int Skill::GetMinDamege() const
{
	return _minDam;
}

int Skill::GetMaxDamege() const
{
	return _maxDam;
}

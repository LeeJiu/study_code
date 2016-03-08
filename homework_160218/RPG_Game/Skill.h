#pragma once
#include <iostream>
using namespace std;


class Skill
{
private:
	char * _skillName;
	int _minDam;
	int _maxDam;

public:
	Skill(char* pSkillName, int nMin, int nMax);
	~Skill();

	char* GetSkillName() const;
	int GetMinDamege() const;
	int GetMaxDamege() const;
};


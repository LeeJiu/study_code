#pragma once
#include "Skill.h"
#include <Windows.h>
#include <ctime>


class Character
{
private:
	Skill * _skill[3];
	char * _name;
	int _hp;
	int _mp;
	int _skillNum;

public:
	Character(char * pName);
	~Character();

	void SetSkill(char * pSkillName, int nMin, int nMax);
	int GetHp() const;
	int GetMp() const;
	char* GetName() const;
	void ShowSkillList() const;

	char* GetSkill();
	void Hit(int nDamege);
	void Attack(Character& pEnemy, char* pSkill);
	bool isDead(Character& pEnemy);
	bool ConsumeMp(int nMp);
};


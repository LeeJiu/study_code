#pragma once
#include "Race.h"
#include "Archer.h"
#include "Berserker.h"
#include "Cleric.h"
#include "Druid.h"
#include "Fighter.h"
#include "Knight.h"
#include "Lancer.h"
#include "Magician.h"
#include "Summoner.h"
class Character
{
private:
	Race * _character;
	int _pow, _def, _hp, _mp;
	float _speed, _attSpd;

public:
	Character();
	~Character();

	void Create();
	void SetBasicInfo();
	void ShowAllInfo() const;
};


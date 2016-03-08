#pragma once
#include "Character.h"

class CharacterHandler
{
private:
	Character * _player[2];
	int _count;

public:
	CharacterHandler();
	~CharacterHandler();

	void MakeCharacter();
	void PlayGame();
};


#include "CharacterHandler.h"



CharacterHandler::CharacterHandler() : _count(0)
{
}


CharacterHandler::~CharacterHandler()
{
	for (int i = 0; i < _count; i++)
		delete _player[i];
}

void CharacterHandler::MakeCharacter()
{
	char name[20];
	char skill[20];
	int min, max;

	cout << "플레이어 " << _count + 1 << "의 이름: ";
	cin >> name;

	_player[_count] = new Character(name);

	for (int i = 0; i < 3; i++)
	{
		cout << "스킬 " << i + 1 << " : ";
		cin >> skill;
		cout << "최소 데미지 : ";
		cin >> min;
		cout << "최대 데미지 : ";
		cin >> max;
		_player[_count]->SetSkill(skill, min, max);
	}
	_count++;

	Sleep(2000);
	system("cls");
}

void CharacterHandler::PlayGame()
{
	char skill[20];
	char * randSkill;

	for (int i = 0; ; i++)
	{
		if (i % 2 == 0)
		{
			_player[0]->ShowSkillList();
			cout << _player[0]->GetName() << "의 스킬 입력: ";
			cin >> skill;
			_player[0]->Attack(*_player[1], skill);
			if (_player[0]->isDead(*_player[1]))
			{
				cout << _player[0]->GetName() << "의 승!" << endl;
				break;
			}
		}
		else
		{
			_player[1]->ShowSkillList();
			randSkill = _player[1]->GetSkill();
			cout << _player[1]->GetName() << "의 스킬 입력: " << randSkill << endl;
			_player[1]->Attack(*_player[0], randSkill);
			if (_player[1]->isDead(*_player[0]))
			{
				cout << _player[1]->GetName() << "의 승!" << endl;
				break;
			}
		}
	}
}

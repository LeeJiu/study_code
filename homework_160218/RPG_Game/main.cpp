#include "CharacterHandler.h"


int main(void)
{
	CharacterHandler manager;

	cout << "\t<게임을 시작합니다!>" << endl << endl;
	//플레이어 1, 2를 만든다.
	manager.MakeCharacter();
	manager.MakeCharacter();
	//게임을 시작한다.
	manager.PlayGame();

	return 0;
}
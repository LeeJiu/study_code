#include "CharacterHandler.h"


int main(void)
{
	CharacterHandler manager;

	cout << "\t<������ �����մϴ�!>" << endl << endl;
	//�÷��̾� 1, 2�� �����.
	manager.MakeCharacter();
	manager.MakeCharacter();
	//������ �����Ѵ�.
	manager.PlayGame();

	return 0;
}
#include "Handler.h"

int main(void)
{
	Handler manager;
	int select;

	while (true)
	{
		manager.ShowMenu();
		cout << "���� : ";
		cin >> select;

		switch (select)
		{
		case 1:
			manager.EnterStore();
			break;
		case 2:
			manager.EnterInventory();
			break;
		case 3:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}

		if (select == 3)
			break;
	}


	return 0;
}
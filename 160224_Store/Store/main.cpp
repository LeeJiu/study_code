#include "Handler.h"

int main(void)
{
	Handler manager;
	int select;

	while (true)
	{
		manager.ShowMenu();
		cout << "선택 : ";
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
			cout << "프로그램을 종료합니다." << endl;
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}

		if (select == 3)
			break;
	}


	return 0;
}
#include "Handler.h"



Handler::Handler()
{
}


Handler::~Handler()
{
}

void Handler::ShowMenu() const
{
	cout << "1. 상점 입장" << endl;
	cout << "2. 인벤토리 확인" << endl;
	cout << "3. 종료" << endl;
}

void Handler::EnterItemInfo()
{
	int select;
	
	cout << "확인할 아이템 번호 입력 : ";
	cin >> select;

	while (true)
	{
		system("cls");

		player.ShowItemInfo(select);
		player.ShowMoney();

		cout << "1. 판매   2. 이전 화면" << endl;
		cout << "선택 : ";
		cin >> select;

		if (select == 1)
		{
			player.SellItem(select);
			break;
		}
		else
		{
			cout << "이전 화면으로 넘어갑니다." << endl;
			Sleep(500);
			system("cls");
			break;
		}
	}
}

void Handler::EnterStore()
{
	int select, selNum;

	while (true)
	{
		system("cls");
		
		owner.ShowItemList();
		player.ShowItemList();

		player.ShowMoney();

		cout << "1. 구매   2. 판매   3. 아이템 정보   4. 나가기" << endl;
		cout << "선택 : ";
		cin >> select;

		if (select == 1)
		{
			Buy();
			Sleep(500);
			system("cls");
		}
		else if (select == 2)
		{
			cout << "판매할 아이템 번호 입력 : ";
			cin >> selNum;
			player.SellItem(selNum);
		}
		else if (select == 3)
		{
			EnterStoreItemInfo();
		}
		else
		{
			cout << "상점을 나갑니다." << endl;
			Sleep(500);
			system("cls");
			break;
		}
	}
}

void Handler::EnterStoreItemInfo()
{
	int select, select2;

	cout << "확인할 아이템 번호 입력 : ";
	cin >> select;

	while (true)
	{
		system("cls");

		owner.ShowItemInfo(select);

		player.ShowMoney();

		cout << "1. 구매   2. 이전 화면" << endl;
		cout << "선택 : ";
		cin >> select2;

		if (select2 == 1)
		{
			player.BuyItem(owner.GetItem(select));
			break;
		}
		else
		{
			cout << "이전 화면으로 넘어갑니다." << endl;
			Sleep(500);
			system("cls");
			break;
		}
	}

}

void Handler::EnterInventory()
{
	int select;

	while (true)
	{
		system("cls");

		player.ShowItemList();
		player.ShowMoney();

		cout << "1. 정보보기    2. 나가기" << endl;
		cout << "선택 : ";
		cin >> select;

		if (select == 1)
		{
			EnterItemInfo();
		}
		else
		{
			cout << "인벤토리를 나갑니다." << endl;
			Sleep(500);
			system("cls");
			break;
		}
	}


}

void Handler::Buy()
{
	int num;
	cout << "구매할 아이템 번호 입력 : ";
	cin >> num;

	//상점의 아이템을 받아와서 플레이어의 인벤에 저장
	player.BuyItem(owner.GetItem(num));
}
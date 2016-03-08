#include "Handler.h"



Handler::Handler()
{
}


Handler::~Handler()
{
}

void Handler::ShowMenu() const
{
	cout << "1. ���� ����" << endl;
	cout << "2. �κ��丮 Ȯ��" << endl;
	cout << "3. ����" << endl;
}

void Handler::EnterItemInfo()
{
	int select;
	
	cout << "Ȯ���� ������ ��ȣ �Է� : ";
	cin >> select;

	while (true)
	{
		system("cls");

		player.ShowItemInfo(select);
		player.ShowMoney();

		cout << "1. �Ǹ�   2. ���� ȭ��" << endl;
		cout << "���� : ";
		cin >> select;

		if (select == 1)
		{
			player.SellItem(select);
			break;
		}
		else
		{
			cout << "���� ȭ������ �Ѿ�ϴ�." << endl;
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

		cout << "1. ����   2. �Ǹ�   3. ������ ����   4. ������" << endl;
		cout << "���� : ";
		cin >> select;

		if (select == 1)
		{
			Buy();
			Sleep(500);
			system("cls");
		}
		else if (select == 2)
		{
			cout << "�Ǹ��� ������ ��ȣ �Է� : ";
			cin >> selNum;
			player.SellItem(selNum);
		}
		else if (select == 3)
		{
			EnterStoreItemInfo();
		}
		else
		{
			cout << "������ �����ϴ�." << endl;
			Sleep(500);
			system("cls");
			break;
		}
	}
}

void Handler::EnterStoreItemInfo()
{
	int select, select2;

	cout << "Ȯ���� ������ ��ȣ �Է� : ";
	cin >> select;

	while (true)
	{
		system("cls");

		owner.ShowItemInfo(select);

		player.ShowMoney();

		cout << "1. ����   2. ���� ȭ��" << endl;
		cout << "���� : ";
		cin >> select2;

		if (select2 == 1)
		{
			player.BuyItem(owner.GetItem(select));
			break;
		}
		else
		{
			cout << "���� ȭ������ �Ѿ�ϴ�." << endl;
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

		cout << "1. ��������    2. ������" << endl;
		cout << "���� : ";
		cin >> select;

		if (select == 1)
		{
			EnterItemInfo();
		}
		else
		{
			cout << "�κ��丮�� �����ϴ�." << endl;
			Sleep(500);
			system("cls");
			break;
		}
	}


}

void Handler::Buy()
{
	int num;
	cout << "������ ������ ��ȣ �Է� : ";
	cin >> num;

	//������ �������� �޾ƿͼ� �÷��̾��� �κ��� ����
	player.BuyItem(owner.GetItem(num));
}
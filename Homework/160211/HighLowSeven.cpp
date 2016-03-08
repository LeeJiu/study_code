#include "HighLowSeven.h"



HighLowSeven::HighLowSeven()
{
	srand((unsigned int)time(NULL));

	//���� �ʱ�ȭ
	int num;
	int cnt = 0;
	_money = 10000;

	for (int i = 0; i < 52; i++)
	{
		num = i / 13;
		switch (num)
		{
		case 0:
			_card[i].shape = "��";
			break;
		case 1:
			_card[i].shape = "��";
			break;
		case 2:
			_card[i].shape = "��";
			break;
		case 3:
			_card[i].shape = "��";
			break;
		}
		num = i % 13 + 1;
		_card[i].number = num;
	}

	//shuffle
	int dst, src;
	for (int i = 0; i < 150; i++)
	{
		dst = rand() % 52;
		src = rand() % 52;

		stCard temp = _card[dst];
		_card[dst] = _card[src];
		_card[src] = temp;
	}


	int betting, choice;
	for (int i = 0; i < 47; i++)
	{
		system("cls");
		cout << "HighLowSeven Game Start!\t\t\t" << "���� �õ�: " << ++cnt << endl << endl;
		
		//ī�� 6�� �̱�
		for (int j = i; j < i + 6; j++)
		{
			if (j == i + 5)
			{
				cout << "??" << endl << endl;
				continue;
			}
			CardPrint(j);
		}
		
		cout << "���� ������: " << _money << endl;
		cout << "High(input : 1), Low(input : 0), Seven(input : 7) ? ";
		
		while (true)
		{
			cin >> choice;
			if ((choice > 1 && choice != 7) || (choice < 0 && choice != 7) || cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "�߸��� �����Դϴ�. �ٽ� �Է�: ";
				continue;
			}
			else
				break;
		}

		while (true)
		{
			cout << "���ñ� �Է�: ";
			cin >> betting;
			if (betting < 100)
			{
				cout << "�⺻ ���ñݺ��� ���� ���ñ��Դϴ�. �ٽ� �Է�: ";
				continue;
			}
			else if (betting > _money)
			{
				cout << "���ñ��� �����ݺ��� �����ϴ�. �ٽ� �Է�: ";
				continue;
			}
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "�߸��� �����Դϴ�. �ٽ� �Է�: ";
				continue;
			}
			else
				break;
		}

		switch (choice)
		{
		case 0:		//Low
			if (_card[i + 5].number < 7)
			{
				_money += betting;
				cout << "�������ϴ�. ���ñ��� �޽��ϴ�." << endl;
			}
			else
			{
				_money -= betting;
				cout << "Ʋ�Ƚ��ϴ�. ���ñ��� �ҽ��ϴ�." << endl;
			}
			break;
		case 1:		//High
			if (_card[i + 5].number > 7)
			{
				_money += betting;
				cout << "�������ϴ�. ���ñ��� �޽��ϴ�." << endl;
			}
			else
			{
				_money -= betting;
				cout << "Ʋ�Ƚ��ϴ�. ���ñ��� �ҽ��ϴ�." << endl;
			}
			break;
		case 7:		//Seven
			if (_card[i + 5].number == 7)
			{
				_money += betting*13;
				cout << "�������ϴ�. 13���� ���ñ��� �޽��ϴ�." << endl;
			}
			else
			{
				_money -= betting;
				cout << "Ʋ�Ƚ��ϴ�. ���ñ��� �ҽ��ϴ�." << endl;
			}
			break;
		}
		if (_money < 100)
		{
			cout << "���ñ��� �����մϴ�. ������ �����մϴ�." << endl;
			break;
		}
		Sleep(500);
	}
	cout << "========================================================================" << endl;
	cout << "The End" << endl;
	cout << "���� ������: " << _money << endl;
}


HighLowSeven::~HighLowSeven()
{
}

void HighLowSeven::CardPrint(int num)
{
	switch (_card[num].number)
	{
	case 1:
		cout << _card[num].shape << "A\t";
		break;
	case 11:
		cout << _card[num].shape << "J\t";
		break;
	case 12:
		cout << _card[num].shape << "Q\t";
		break;
	case 13:
		cout << _card[num].shape << "K\t";
		break;
	default:
		cout << _card[num].shape << _card[num].number << "\t";
		break;
	}
}

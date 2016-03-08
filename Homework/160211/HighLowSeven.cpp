#include "HighLowSeven.h"



HighLowSeven::HighLowSeven()
{
	srand((unsigned int)time(NULL));

	//변수 초기화
	int num;
	int cnt = 0;
	_money = 10000;

	for (int i = 0; i < 52; i++)
	{
		num = i / 13;
		switch (num)
		{
		case 0:
			_card[i].shape = "♠";
			break;
		case 1:
			_card[i].shape = "◆";
			break;
		case 2:
			_card[i].shape = "♥";
			break;
		case 3:
			_card[i].shape = "♣";
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
		cout << "HighLowSeven Game Start!\t\t\t" << "현재 시도: " << ++cnt << endl << endl;
		
		//카드 6장 뽑기
		for (int j = i; j < i + 6; j++)
		{
			if (j == i + 5)
			{
				cout << "??" << endl << endl;
				continue;
			}
			CardPrint(j);
		}
		
		cout << "현재 소지금: " << _money << endl;
		cout << "High(input : 1), Low(input : 0), Seven(input : 7) ? ";
		
		while (true)
		{
			cin >> choice;
			if ((choice > 1 && choice != 7) || (choice < 0 && choice != 7) || cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "잘못된 선택입니다. 다시 입력: ";
				continue;
			}
			else
				break;
		}

		while (true)
		{
			cout << "베팅금 입력: ";
			cin >> betting;
			if (betting < 100)
			{
				cout << "기본 베팅금보다 적은 베팅금입니다. 다시 입력: ";
				continue;
			}
			else if (betting > _money)
			{
				cout << "베팅금이 소지금보다 많습니다. 다시 입력: ";
				continue;
			}
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "잘못된 베팅입니다. 다시 입력: ";
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
				cout << "맞혔습니다. 베팅금을 받습니다." << endl;
			}
			else
			{
				_money -= betting;
				cout << "틀렸습니다. 베팅금을 잃습니다." << endl;
			}
			break;
		case 1:		//High
			if (_card[i + 5].number > 7)
			{
				_money += betting;
				cout << "맞혔습니다. 베팅금을 받습니다." << endl;
			}
			else
			{
				_money -= betting;
				cout << "틀렸습니다. 베팅금을 잃습니다." << endl;
			}
			break;
		case 7:		//Seven
			if (_card[i + 5].number == 7)
			{
				_money += betting*13;
				cout << "맞혔습니다. 13배의 베팅금을 받습니다." << endl;
			}
			else
			{
				_money -= betting;
				cout << "틀렸습니다. 베팅금을 잃습니다." << endl;
			}
			break;
		}
		if (_money < 100)
		{
			cout << "베팅금이 부족합니다. 게임을 종료합니다." << endl;
			break;
		}
		Sleep(500);
	}
	cout << "========================================================================" << endl;
	cout << "The End" << endl;
	cout << "남은 소지금: " << _money << endl;
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

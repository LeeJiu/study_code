#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main(void)
{
	int puzzle[25] = { 0, };
	int inputNum = 0;
	int clear = 0;
	
	//input number 1~24
	for (int i = 0; i < 24; i++)
	{
		puzzle[i] = i + 1;
	}

	//shuffle
	srand((unsigned int)time(NULL));
	int dst = 0;
	int src = 0;
	int tmp = 0;
	for (int i = 0; i < 50; i++)
	{
		dst = rand() % 24;
		src = rand() % 24;

		tmp = puzzle[dst];
		puzzle[dst] = puzzle[src];
		puzzle[src] = tmp;
	}

	int idx = 24;
	while (true)
	{
		//draw
		for (int i = 0; i < 25; i++)
		{
			cout << puzzle[i] << "\t";
			if (i % 5 == 4)
				cout << endl << endl;;
		}

		cout << "���� �Է�(8,2,4,6/�����¿�): ";
		cin >> inputNum;

		//������ �ƴ� �ٸ� ���� �Է��߰ų�, ���� ���� ���� �Է����� ��
		while (!cin.good() || (inputNum != 8 && inputNum != 2 && inputNum != 4 && inputNum != 6))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�ٽ� �Է�: ";
			cin >> inputNum;
			continue;
		}

		switch (inputNum)
		{
		case 8:	//��
			if (idx < 5)
			{
				cout << "������ �� ���� �����Դϴ�." << endl;
				Sleep(1000);
			}
			else
			{
				tmp = puzzle[idx];
				puzzle[idx] = puzzle[idx - 5];
				puzzle[idx - 5] = tmp;
				idx -= 5;
			}
			break;
		case 2:	//��
			if (idx > 19)
			{
				cout << "������ �� ���� �����Դϴ�." << endl;
				Sleep(1000);
			}
			else
			{
				tmp = puzzle[idx];
				puzzle[idx] = puzzle[idx + 5];
				puzzle[idx + 5] = tmp;
				idx += 5;
			}
			break;
		case 4:	//��
			if (idx % 5 == 0)
			{
				cout << "������ �� ���� �����Դϴ�." << endl;
				Sleep(1000);
			}
			else
			{
				tmp = puzzle[idx];
				puzzle[idx] = puzzle[idx - 1];
				puzzle[idx - 1] = tmp;
				idx -= 1;
			}
			break;
		case 6:	//��
			if (idx % 5 == 4)
			{
				cout << "������ �� ���� �����Դϴ�." << endl;
				Sleep(1000);
			}
			else
			{
				tmp = puzzle[idx];
				puzzle[idx] = puzzle[idx + 1];
				puzzle[idx + 1] = tmp;
				idx += 1;
			}
			break;
		}

		system("cls");

		//clear check
		for (int i = 0; i < 24; i++)
		{
			if (puzzle[i] == i + 1)
			{
				clear++;
			}
			else
			{
				clear = 0;
				break;
			}
		}
		if (clear == 24)
		{
			cout << "clear!" << endl;
			break;
		}
	}


	return 0;
}
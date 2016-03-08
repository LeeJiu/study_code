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

		cout << "방향 입력(8,2,4,6/상하좌우): ";
		cin >> inputNum;

		//정수가 아닌 다른 값을 입력했거나, 범위 밖의 값을 입력했을 때
		while (!cin.good() || (inputNum != 8 && inputNum != 2 && inputNum != 4 && inputNum != 6))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "다시 입력: ";
			cin >> inputNum;
			continue;
		}

		switch (inputNum)
		{
		case 8:	//상
			if (idx < 5)
			{
				cout << "움직일 수 없는 방향입니다." << endl;
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
		case 2:	//하
			if (idx > 19)
			{
				cout << "움직일 수 없는 방향입니다." << endl;
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
		case 4:	//좌
			if (idx % 5 == 0)
			{
				cout << "움직일 수 없는 방향입니다." << endl;
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
		case 6:	//우
			if (idx % 5 == 4)
			{
				cout << "움직일 수 없는 방향입니다." << endl;
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
#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int bingo[25] = { 0, };
	int inputNum = 0;
	int bingoCnt = 0;

	//1~25 숫자 채우기
	for (int i = 0; i < 25; i++)
	{
		bingo[i] = i + 1;
	}

	//빙고판 셔플
	srand((unsigned)time(NULL));
	int dst = 0;
	int src = 0;
	int tmp = 0;
	for (int i = 0; i < 50; i++)
	{
		dst = rand() % 25;
		src = rand() % 25;

		tmp = bingo[dst];
		bingo[dst] = bingo[src];
		bingo[src] = tmp;
	}

	// 빙고판 그려줌
	for (int i = 0; i < 25; i++)
	{
		cout << bingo[i] << "\t";
		if (i % 5 == 4)
			cout << endl << endl;;
	}
	cout << endl;

	while (true)
	{
		//사용자 입력
		cout << "숫자 입력: ";
		cin >> inputNum;
		
		//정수가 아닌 다른 값을 입력했거나, 범위 밖의 값을 입력했을 때
		while (!cin.good() || inputNum < 1 || inputNum > 25)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "다시 입력: ";
			cin >> inputNum;
			continue;
		}

		//빙고 숫자 확인 & 변경
		for (int i = 0; i < 25; i++)
		{
			if (bingo[i] == inputNum)	//사용자 입력과 빙고판 값이 같으면
				bingo[i] = 35;			//#의 아스키코드 값을 저장
		}

		//화면 클리어
		system("cls");

		// 빙고판 그려줌
		for (int i = 0; i < 25; i++)
		{
			if (bingo[i] == 35)
				cout << "★" << "\t";
			else
				cout << bingo[i] << "\t";
			if (i % 5 == 4)
				cout << endl << endl;
		}
		cout << endl;


		bingoCnt = 0;
		//빙고 위치 확인
		//라인마다 카운트
		for (int i = 0; i < 5; i++)
		{	//가로
			if(bingo[5 * i] == 35 && bingo[5 * i +1] == 35 && bingo[5 * i +2] == 35 && bingo[5 * i +3] == 35 && bingo[5 * i +4] == 35)
				bingoCnt++;
			//세로
			if (bingo[i] == 35 && bingo[i + 5] == 35 && bingo[i + 10] == 35 && bingo[i + 15] == 35 && bingo[i + 20] == 35)
				bingoCnt++;
		}
		//하드 코딩이라니ㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜㅜ
		if (bingo[0] == 35 && bingo[6] == 35 && bingo[12] == 35 && bingo[18] == 35 && bingo[24] == 35)
			bingoCnt++;

		if (bingo[4] == 35 && bingo[8] == 35 && bingo[12] == 35 && bingo[16] == 35 && bingo[20] == 35)
			bingoCnt++;
		

		if (bingoCnt >= 5)
		{
			cout << bingoCnt << " 빙고!" << endl << endl;
			break;
		}
	}

	return 0;
}
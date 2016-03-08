#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int randNum[3] = { 0, };	//난수 3개 저장 변수
	int inputNum[3] = { 0, };

	srand((unsigned)time(NULL));	//난수 발생

	for (int i = 0; i < 3; i++)
	{
		randNum[i] = rand() % 10;	//난수 3개 저장
		if (randNum[0] == 0)			//만약 첫번째가 0이라면
			randNum[0] = rand() % 9 + 1;		//1~9까지의 랜덤 수를 저장
		for (int j = 0; j < i; j++)			//같은 수가 있는지 확인
		{
			if (randNum[i] == randNum[j])	//같으면
			{
				i--;		//다시 난수를 저장하러 가렴
				break;
			}
		}
	}

	//난수 3개 확인용 출력
	/*for (int i = 0; i < 3; i++)
		cout << randNum[i];
	cout << endl;*/

	int ballcnt = 0;		//ball 카운트
	int strikecnt = 0;	//strike 카운트
	int cnt = 0;			//시도 카운트
	for (cnt = 0; cnt < 10; cnt++)		//10번의 기회
	{
		cout << cnt + 1 << "번째 시도" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << j + 1 << "번째 정수 입력: ";
			cin >> inputNum[j];		//사용자 입력
		}

		//판정
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (randNum[j] == inputNum[k])
				{
					ballcnt++;
					if (j == k)		//위치도 동일하면
					{
						ballcnt--;	//ball이 아니라
						strikecnt++;	//strike
					}
				}
			}
		}
		cout << "Ball: " << ballcnt << " Strike: " << strikecnt << endl;
		if (ballcnt == 0 && strikecnt == 0)
			cout << " Foul!" << endl;
		if (strikecnt == 3)
		{
			cout << "Right!" << endl;
			break;
		}
		ballcnt = 0;
		strikecnt = 0;
	}

	if (cnt == 10)
	{
		cout << "답은 ";
		for (int i = 0; i < 3; i++)
			cout << randNum[i];
		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int num = 0;				//사용자 입력 변수
	int count = 0;			//시도 횟수 저장 변수
	int randNum = 0;		//난수 저장 변수
	srand((unsigned)time(NULL));	//난수 생성기 초기화
	randNum = rand() % 1001;		//난수 범위 지정, 0~1000

	//cout << randNum << endl;		//확인용
	cout << "Up&Down Game Start!" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "번째 시도: ";
		cin >> num;			//플레이어 입력
		while (num < 0 || num > 1000)		//플레이어의 입력 실수
		{
			cout << "잘못된 입력입니다. 0~1000범위의 수를 입력하세요." << endl;
			cout << "다시 시도: ";
			cin >> num;		//재입력
		}

		if (num < randNum)	//난수보다 작으면
			cout << "Up" << endl;
		else if (num >randNum)	//난수보다 크면
			cout << "Down" << endl;
		else if (num == randNum)	//정답
		{
			cout << "Right!" << endl;
			break;
		}
		count++;
	}

	if (count == 10)	//10번 안에 성공 하지 못했을 경우
		cout << "Fail! Random number: " << randNum << endl;

	return 0;
}
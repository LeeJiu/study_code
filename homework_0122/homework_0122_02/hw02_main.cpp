#include <iostream>
using namespace std;

int main(void)
{
	int num = 1; //초기 값( 2^0 = 1)

	//0~10000 2^n 출력
	while (true)	//무한루프
	{
		if (num >= 0 && num <= 10000)		// 0 <= num <= 10000
		{
			cout << num << endl;
			num = num << 1;		// 왼쪽 시프트 비트 연산
		}
		else
			break;		// 조건이 맞지 않으면 반복문 탈출
	}

	return 0;
}
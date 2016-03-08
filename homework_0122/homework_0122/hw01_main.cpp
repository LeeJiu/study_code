#include <iostream>
using namespace std;

int main(void)
{
	// 0~99 짝수 출력
	cout << "0~99 중에 짝수를 출력합니다." << endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			cout << i << "\t";
	}
	cout << endl;

	return 0;
}
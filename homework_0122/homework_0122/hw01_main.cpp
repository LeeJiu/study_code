#include <iostream>
using namespace std;

int main(void)
{
	// 0~99 ¦�� ���
	cout << "0~99 �߿� ¦���� ����մϴ�." << endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			cout << i << "\t";
	}
	cout << endl;

	return 0;
}
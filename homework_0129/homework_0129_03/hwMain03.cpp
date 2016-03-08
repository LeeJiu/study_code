#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int rotto[45];
	int num = 0;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 45; i++)
	{
		rotto[i] = i + 1;	//1~45
	}

	cout << "�� �� �� ��Ŵ�? ";
	cin >> num;

	while (0 < num)
	{
		//shuffle
		int dest;
		int sour;
		int temp;
		for (int i = 0; i < 90; i++)
		{
			//0~44 ���� ����
			dest = rand() % 45;
			sour = rand() % 45;

			temp = rotto[dest];
			rotto[dest] = rotto[sour];
			rotto[sour] = temp;
		}

		cout << "Rotto ��÷ ���: ";
		for (int i = 0; i < 6; i++)
		{
			cout << rotto[i] << " ";
		}
		cout << endl;
		num--;
	}
	return 0;
}
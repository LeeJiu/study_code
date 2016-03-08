#include <iostream>
using namespace std;

int main(void)
{
	int matrix[30][30] = { 0, };
	int input;
	int i = 0, j = 0;
	int number = 1;

	cout << "정수 입력: ";
	cin >> input;

	for (i = 0; i < input; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i % 2 == 0)
			{
				matrix[i - j][j] = number;
			}
			else if (i % 2 == 1)
			{
				matrix[j][i - j] = number;
			}
			number++;
		}
	}

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input - i; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}

	return 0;
}
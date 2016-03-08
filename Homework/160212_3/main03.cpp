#include <iostream>
using namespace std;

int main(void)
{
	int matrix[30][30] = { 0, };
	int number = 1;
	int input;

	cout << "정수 입력: ";
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (i % 2 == 0)
			{
				matrix[i][j] = number;
				number++;
			}
			else if (i % 2 == 1)
			{
				matrix[i][input-j-1] = number;
				number++;
			}
		}
	}

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
			cout << matrix[i][j] << "\t";
		cout << endl << endl;
	}

	return 0;
}
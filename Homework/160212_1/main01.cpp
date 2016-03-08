#include <iostream>
using namespace std;

int main(void)
{
	int matrix[30][30] = {0, };
	int input;
	int i = 0, j = 0;
	int number = 1;
	int plusRow = 2;
	int plusColumn = 1;

	cout << "정수 입력: ";
	cin >> input;

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input-i; j++)
		{
			matrix[i][j] = number;
			number += plusRow +j;
		}
		plusRow++;
		number = matrix[i][0] + plusColumn;
		plusColumn++;
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
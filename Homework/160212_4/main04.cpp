#include <iostream>
using namespace std;

int main(void)
{
	int matrix[30][30] = { 0, };
	int number = 1;
	int row = 0, col = -1, direct = 1;		//0���� �����Ϸ��� col�� -1����
	int output, input;

	cout << "���� �Է�: ";
	cin >> input;

	output = input;

	while (true)
	{
		for (int i = 0; i < input; i++)
		{
			col += direct;
			matrix[row][col] = number;
			number++;
		}
		input--;
		
		for (int i = 0; i < input; i++)
		{
			row += direct;
			matrix[row][col] = number;
			number++;
		}
		direct *= -1;		//���μ��� �ѹ��� �ϰ� ���� �ε����� �ι����������

		if (input == 0)		//������ ���̰� 0�� �Ǹ�
			break;
	}




	for (int i = 0; i < output; i++)
	{
		for (int j = 0; j < output; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}

	return 0;
}
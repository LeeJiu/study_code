#include <iostream>
using namespace std;

int main(void)
{
	int matrix[30][30] = { 0, };
	int number = 1;
	int row = 0, col = -1, direct = 1;		//0부터 시작하려면 col이 -1부터
	int output, input;

	cout << "정수 입력: ";
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
		direct *= -1;		//가로세로 한번씩 하고 나면 인덱스를 인버스해줘야함

		if (input == 0)		//정방형 길이가 0이 되면
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
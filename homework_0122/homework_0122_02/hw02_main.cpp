#include <iostream>
using namespace std;

int main(void)
{
	int num = 1; //�ʱ� ��( 2^0 = 1)

	//0~10000 2^n ���
	while (true)	//���ѷ���
	{
		if (num >= 0 && num <= 10000)		// 0 <= num <= 10000
		{
			cout << num << endl;
			num = num << 1;		// ���� ����Ʈ ��Ʈ ����
		}
		else
			break;		// ������ ���� ������ �ݺ��� Ż��
	}

	return 0;
}
#include <iostream>
using namespace std;

int main(void)
{
	char str[100];
	int len;

	cout << "���ڿ� �Է�: ";
	cin >> str;

	len = strlen(str);

	int temp;
	for (int i = 0; i <= len / 2; i++)
	{
		if(i % 2 == 1 && len % 2 == 0)		//¦����°�� ¦�����϶�
		{
			temp = str[i];
			str[i] = str[len - i];
			str[len - i] = temp;
		}
		else if (i % 2 == 1 && len % 2 == 1)		//¦����°�� Ȧ�����϶�
		{
			temp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = temp;
		}
	}

	cout << str << endl;



	return 0;
}
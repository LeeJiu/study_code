#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int num = 0;				//����� �Է� ����
	int count = 0;			//�õ� Ƚ�� ���� ����
	int randNum = 0;		//���� ���� ����
	srand((unsigned)time(NULL));	//���� ������ �ʱ�ȭ
	randNum = rand() % 1001;		//���� ���� ����, 0~1000

	//cout << randNum << endl;		//Ȯ�ο�
	cout << "Up&Down Game Start!" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "��° �õ�: ";
		cin >> num;			//�÷��̾� �Է�
		while (num < 0 || num > 1000)		//�÷��̾��� �Է� �Ǽ�
		{
			cout << "�߸��� �Է��Դϴ�. 0~1000������ ���� �Է��ϼ���." << endl;
			cout << "�ٽ� �õ�: ";
			cin >> num;		//���Է�
		}

		if (num < randNum)	//�������� ������
			cout << "Up" << endl;
		else if (num >randNum)	//�������� ũ��
			cout << "Down" << endl;
		else if (num == randNum)	//����
		{
			cout << "Right!" << endl;
			break;
		}
		count++;
	}

	if (count == 10)	//10�� �ȿ� ���� ���� ������ ���
		cout << "Fail! Random number: " << randNum << endl;

	return 0;
}
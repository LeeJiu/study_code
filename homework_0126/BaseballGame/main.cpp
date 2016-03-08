#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int randNum[3] = { 0, };	//���� 3�� ���� ����
	int inputNum[3] = { 0, };

	srand((unsigned)time(NULL));	//���� �߻�

	for (int i = 0; i < 3; i++)
	{
		randNum[i] = rand() % 10;	//���� 3�� ����
		if (randNum[0] == 0)			//���� ù��°�� 0�̶��
			randNum[0] = rand() % 9 + 1;		//1~9������ ���� ���� ����
		for (int j = 0; j < i; j++)			//���� ���� �ִ��� Ȯ��
		{
			if (randNum[i] == randNum[j])	//������
			{
				i--;		//�ٽ� ������ �����Ϸ� ����
				break;
			}
		}
	}

	//���� 3�� Ȯ�ο� ���
	/*for (int i = 0; i < 3; i++)
		cout << randNum[i];
	cout << endl;*/

	int ballcnt = 0;		//ball ī��Ʈ
	int strikecnt = 0;	//strike ī��Ʈ
	int cnt = 0;			//�õ� ī��Ʈ
	for (cnt = 0; cnt < 10; cnt++)		//10���� ��ȸ
	{
		cout << cnt + 1 << "��° �õ�" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << j + 1 << "��° ���� �Է�: ";
			cin >> inputNum[j];		//����� �Է�
		}

		//����
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (randNum[j] == inputNum[k])
				{
					ballcnt++;
					if (j == k)		//��ġ�� �����ϸ�
					{
						ballcnt--;	//ball�� �ƴ϶�
						strikecnt++;	//strike
					}
				}
			}
		}
		cout << "Ball: " << ballcnt << " Strike: " << strikecnt << endl;
		if (ballcnt == 0 && strikecnt == 0)
			cout << " Foul!" << endl;
		if (strikecnt == 3)
		{
			cout << "Right!" << endl;
			break;
		}
		ballcnt = 0;
		strikecnt = 0;
	}

	if (cnt == 10)
	{
		cout << "���� ";
		for (int i = 0; i < 3; i++)
			cout << randNum[i];
		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int bingo[25] = { 0, };
	int inputNum = 0;
	int bingoCnt = 0;

	//1~25 ���� ä���
	for (int i = 0; i < 25; i++)
	{
		bingo[i] = i + 1;
	}

	//������ ����
	srand((unsigned)time(NULL));
	int dst = 0;
	int src = 0;
	int tmp = 0;
	for (int i = 0; i < 50; i++)
	{
		dst = rand() % 25;
		src = rand() % 25;

		tmp = bingo[dst];
		bingo[dst] = bingo[src];
		bingo[src] = tmp;
	}

	// ������ �׷���
	for (int i = 0; i < 25; i++)
	{
		cout << bingo[i] << "\t";
		if (i % 5 == 4)
			cout << endl << endl;;
	}
	cout << endl;

	while (true)
	{
		//����� �Է�
		cout << "���� �Է�: ";
		cin >> inputNum;
		
		//������ �ƴ� �ٸ� ���� �Է��߰ų�, ���� ���� ���� �Է����� ��
		while (!cin.good() || inputNum < 1 || inputNum > 25)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�ٽ� �Է�: ";
			cin >> inputNum;
			continue;
		}

		//���� ���� Ȯ�� & ����
		for (int i = 0; i < 25; i++)
		{
			if (bingo[i] == inputNum)	//����� �Է°� ������ ���� ������
				bingo[i] = 35;			//#�� �ƽ�Ű�ڵ� ���� ����
		}

		//ȭ�� Ŭ����
		system("cls");

		// ������ �׷���
		for (int i = 0; i < 25; i++)
		{
			if (bingo[i] == 35)
				cout << "��" << "\t";
			else
				cout << bingo[i] << "\t";
			if (i % 5 == 4)
				cout << endl << endl;
		}
		cout << endl;


		bingoCnt = 0;
		//���� ��ġ Ȯ��
		//���θ��� ī��Ʈ
		for (int i = 0; i < 5; i++)
		{	//����
			if(bingo[5 * i] == 35 && bingo[5 * i +1] == 35 && bingo[5 * i +2] == 35 && bingo[5 * i +3] == 35 && bingo[5 * i +4] == 35)
				bingoCnt++;
			//����
			if (bingo[i] == 35 && bingo[i + 5] == 35 && bingo[i + 10] == 35 && bingo[i + 15] == 35 && bingo[i + 20] == 35)
				bingoCnt++;
		}
		//�ϵ� �ڵ��̶�Ϥ̤̤̤̤̤̤̤̤̤̤̤̤̤̤�
		if (bingo[0] == 35 && bingo[6] == 35 && bingo[12] == 35 && bingo[18] == 35 && bingo[24] == 35)
			bingoCnt++;

		if (bingo[4] == 35 && bingo[8] == 35 && bingo[12] == 35 && bingo[16] == 35 && bingo[20] == 35)
			bingoCnt++;
		

		if (bingoCnt >= 5)
		{
			cout << bingoCnt << " ����!" << endl << endl;
			break;
		}
	}

	return 0;
}
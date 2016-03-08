#include "Gambling.h"

Gambling::Gambling()
{
	int trump[52];
	int dest, sour, temp;
	int myMoney = 10000;
	int saveIdx = 0;
	int bettingPoint = 0, beforePoint = 0, afterPoint = 0, betPnt_shape = 0;
	int bettingMoney = 0;
	bool clear = false;

	//trump 1~52
	for (int i = 0; i < 52; i++)
	{
		trump[i] = i + 1;
	}

	//shuffle
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 150; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = trump[dest];
		trump[dest] = trump[sour];
		trump[sour] = temp;
	}

	while (true)
	{
		cout << "Trump Game Start!" << endl << endl;
		//ī�� 3�� �̾Ƽ� ���
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				if (trump[saveIdx] > 0 && trump[saveIdx] < 14)
				{
					beforePoint = trump[saveIdx];
					if (beforePoint == 1) cout << "  ��A  ";
					else if(beforePoint == 11) cout << "  ��J  ";
					else if (beforePoint == 12) cout << "  ��Q  ";
					else if (beforePoint == 13) cout << "  ��K  ";
					else cout << "  ��" << beforePoint << "  ";
				}
				else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
				{
					beforePoint = trump[saveIdx] - 13;
					if (beforePoint == 1) cout << "  ��A  ";
					else if (beforePoint == 11) cout << "  ��J  ";
					else if (beforePoint == 12) cout << "  ��Q  ";
					else if (beforePoint == 13) cout << "  ��K  ";
					else cout << "  ��" << beforePoint << "  ";
				}
				else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
				{
					beforePoint = trump[saveIdx] - 26;
					if (beforePoint == 1) cout << "  ��A  ";
					else if (beforePoint == 11) cout << "  ��J  ";
					else if (beforePoint == 12) cout << "  ��Q  ";
					else if (beforePoint == 13) cout << "  ��K  ";
					else cout << "  ��" << beforePoint << "  ";
				}
				else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
				{
					beforePoint = trump[saveIdx] - 39;
					if (beforePoint == 1) cout << "  ��A  ";
					else if (beforePoint == 11) cout << "  ��J  ";
					else if (beforePoint == 12) cout << "  ��Q  ";
					else if (beforePoint == 13) cout << "  ��K  ";
					else cout << "  ��" << beforePoint << "  ";
				}
				saveIdx++;
				break;
			case 1:
				if (trump[saveIdx] > 0 && trump[saveIdx] < 14)
				{
					bettingPoint = trump[saveIdx];
					betPnt_shape = 1;
					cout << "??";
				}
				else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
				{
					bettingPoint = trump[saveIdx] - 13;
					betPnt_shape = 2;
					cout << "??";
				}
				else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
				{
					bettingPoint = trump[saveIdx] - 26;
					betPnt_shape = 3;
					cout << "??";
				}
				else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
				{
					bettingPoint = trump[saveIdx] - 39;
					betPnt_shape = 4;
					cout << "??";
				}
				saveIdx++;
				break;
			case 2:
				if (trump[saveIdx] > 0 && trump[saveIdx] < 14)
				{
					afterPoint = trump[saveIdx];
					if (afterPoint == 1) cout << "  ��A" << endl << endl;
					else if (afterPoint == 11) cout << "  ��J" << endl << endl;
					else if (afterPoint == 12) cout << "  ��Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ��K" << endl << endl;
					else cout << "  ��" << afterPoint << "  " << endl << endl;
				}
				else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
				{
					afterPoint = trump[saveIdx] - 13;
					if (afterPoint == 1) cout << "  ��A" << endl << endl;
					else if (afterPoint == 11) cout << "  ��J" << endl << endl;
					else if (afterPoint == 12) cout << "  ��Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ��K" << endl << endl;
					else cout << "  ��" << afterPoint << endl << endl;
				}
				else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
				{
					afterPoint = trump[saveIdx] - 26;
					if (afterPoint == 1) cout << "  ��A" << endl << endl;
					else if (afterPoint == 11) cout << "  ��J" << endl << endl;
					else if (afterPoint == 12) cout << "  ��Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ��K" << endl << endl;
					else cout << "  ��" << afterPoint << endl << endl;
				}
				else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
				{
					afterPoint = trump[saveIdx] - 39;
					if (afterPoint == 1) cout << "  ��A" << endl << endl;
					else if (afterPoint == 11) cout << "  ��J" << endl << endl;
					else if (afterPoint == 12) cout << "  ��Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ��K" << endl << endl;
					else cout << "  ��" << afterPoint << endl << endl;
				}
				saveIdx++;
				break;
			}
		}

		//����
		cout << "���� ������ : " << myMoney << endl << endl;
		cout << "������ ���� �ʰ�, �ٷ� die�� �ϸ� �⺻ ���ñ� 100���� �����˴ϴ�." << endl;
		cout << "�� �����Ͻðڽ��ϱ�? (die = -1) : ";
		cin >> bettingMoney;
		while (true)
		{
			if (bettingMoney > myMoney && bettingMoney != -1)
			{
				cout << "���ñ��� �����ݺ��� Ů�ϴ�. �ٽ� �Է����ּ���. : ";
				cin >> bettingMoney;
				continue;
			}
			else if (bettingMoney < 100 && bettingMoney != -1)
			{
				cout << "���ñ��� �ʹ� �����ϴ�. �ٽ� �Է����ּ���. : ";
				cin >> bettingMoney;
				continue;
			}
			else
			{
				break;
			}
		}

		//clear check
		if (bettingPoint > beforePoint && bettingPoint < afterPoint)
			clear = true;
		else if (bettingPoint > afterPoint && bettingPoint < beforePoint)
			clear = true;
		else
			clear = false;


		cout << "=================================================================" << endl;
		//���ñ� ����
		if (bettingMoney == -1)		//die ���� ��
		{
			myMoney -= 100;
			if (betPnt_shape == 1)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 2)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 3)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 4)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			cout << "�÷��̾ Die�� �߱� ������ 100���� �����˴ϴ�." << endl;
			cout << "���� ������: " << myMoney << endl;
		}
		else if (!clear && bettingMoney != -1)	//����
		{
			myMoney -= bettingMoney;
			if (betPnt_shape == 1)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 2)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 3)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 4)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			cout << "Ʋ�Ƚ��ϴ�. ���ñ� �����մϴ�." << endl;
			cout << "���� ������: " << myMoney << endl;
		}
		else if (clear && bettingMoney != -1)	//����
		{
			myMoney += bettingMoney;
			if (betPnt_shape == 1)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 2)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 3)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			else if (betPnt_shape == 4)
			{
				if (bettingPoint == 1) cout << "������ ī��� [ ��A ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 11) cout << "������ ī��� [ ��J ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 12) cout << "������ ī��� [ ��Q ] �����ϴ�." << endl << endl;
				else if (bettingPoint == 13) cout << "������ ī��� [ ��K ] �����ϴ�." << endl << endl;
				else cout << "������ ī��� [ ��" << bettingPoint << " ] �����ϴ�." << endl << endl;
			}
			cout << "�¾ҽ��ϴ�. ���ñ� �޽��ϴ�." << endl;
			cout << "���� ������: " << myMoney << endl;
		}

		//�������� �� �и���
		if (myMoney == 0 || myMoney < 100)
		{
			cout << "�������� �����ؼ� ������ �ߴ��մϴ�." << endl;
			break;
		}

		Sleep(2000);
		system("cls");

		if (saveIdx == 51)
		{
			//���������� ���� �ϳ��� ī�带 �����ְ� ������ ������.
			cout << "������ ���� ī��" << endl << endl;
			if (trump[saveIdx] > 0 && trump[saveIdx] < 14)
			{
				bettingPoint = trump[saveIdx];
				if (bettingPoint == 1) cout << "  ��A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ��J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ��Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ��K" << endl << endl;
				else cout << "  ��" << bettingPoint << endl << endl;
			}
			else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
			{
				bettingPoint = trump[saveIdx] - 13;
				if (bettingPoint == 1) cout << "  ��A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ��J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ��Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ��K" << endl << endl;
				else cout << "  ��" << bettingPoint << endl << endl;
			}
			else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
			{
				bettingPoint = trump[saveIdx] - 26;
				if (bettingPoint == 1) cout << "  ��A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ��J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ��Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ��K" << endl << endl;
				else cout << "  ��" << bettingPoint << endl << endl;
			}
			else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
			{
				bettingPoint = trump[saveIdx] - 39;
				if (bettingPoint == 1) cout << "  ��A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ��J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ��Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ��K" << endl << endl;
				else cout << "  ��" << bettingPoint << endl << endl;
			}
			cout << "���� ������ : " << myMoney << endl << endl;
			break;
		}
	}
}


Gambling::~Gambling()
{
}

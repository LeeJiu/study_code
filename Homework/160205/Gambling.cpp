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
		//카드 3개 뽑아서 출력
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				if (trump[saveIdx] > 0 && trump[saveIdx] < 14)
				{
					beforePoint = trump[saveIdx];
					if (beforePoint == 1) cout << "  ♠A  ";
					else if(beforePoint == 11) cout << "  ♠J  ";
					else if (beforePoint == 12) cout << "  ♠Q  ";
					else if (beforePoint == 13) cout << "  ♠K  ";
					else cout << "  ♠" << beforePoint << "  ";
				}
				else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
				{
					beforePoint = trump[saveIdx] - 13;
					if (beforePoint == 1) cout << "  ◆A  ";
					else if (beforePoint == 11) cout << "  ◆J  ";
					else if (beforePoint == 12) cout << "  ◆Q  ";
					else if (beforePoint == 13) cout << "  ◆K  ";
					else cout << "  ◆" << beforePoint << "  ";
				}
				else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
				{
					beforePoint = trump[saveIdx] - 26;
					if (beforePoint == 1) cout << "  ♥A  ";
					else if (beforePoint == 11) cout << "  ♥J  ";
					else if (beforePoint == 12) cout << "  ♥Q  ";
					else if (beforePoint == 13) cout << "  ♥K  ";
					else cout << "  ♥" << beforePoint << "  ";
				}
				else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
				{
					beforePoint = trump[saveIdx] - 39;
					if (beforePoint == 1) cout << "  ♣A  ";
					else if (beforePoint == 11) cout << "  ♣J  ";
					else if (beforePoint == 12) cout << "  ♣Q  ";
					else if (beforePoint == 13) cout << "  ♣K  ";
					else cout << "  ♣" << beforePoint << "  ";
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
					if (afterPoint == 1) cout << "  ♠A" << endl << endl;
					else if (afterPoint == 11) cout << "  ♠J" << endl << endl;
					else if (afterPoint == 12) cout << "  ♠Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ♠K" << endl << endl;
					else cout << "  ♠" << afterPoint << "  " << endl << endl;
				}
				else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
				{
					afterPoint = trump[saveIdx] - 13;
					if (afterPoint == 1) cout << "  ◆A" << endl << endl;
					else if (afterPoint == 11) cout << "  ◆J" << endl << endl;
					else if (afterPoint == 12) cout << "  ◆Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ◆K" << endl << endl;
					else cout << "  ◆" << afterPoint << endl << endl;
				}
				else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
				{
					afterPoint = trump[saveIdx] - 26;
					if (afterPoint == 1) cout << "  ♥A" << endl << endl;
					else if (afterPoint == 11) cout << "  ♥J" << endl << endl;
					else if (afterPoint == 12) cout << "  ♥Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ♥K" << endl << endl;
					else cout << "  ♥" << afterPoint << endl << endl;
				}
				else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
				{
					afterPoint = trump[saveIdx] - 39;
					if (afterPoint == 1) cout << "  ♣A" << endl << endl;
					else if (afterPoint == 11) cout << "  ♣J" << endl << endl;
					else if (afterPoint == 12) cout << "  ♣Q" << endl << endl;
					else if (afterPoint == 13) cout << "  ♣K" << endl << endl;
					else cout << "  ♣" << afterPoint << endl << endl;
				}
				saveIdx++;
				break;
			}
		}

		//베팅
		cout << "남은 소지금 : " << myMoney << endl << endl;
		cout << "베팅을 하지 않고, 바로 die를 하면 기본 베팅금 100원이 차감됩니다." << endl;
		cout << "얼마 베팅하시겠습니까? (die = -1) : ";
		cin >> bettingMoney;
		while (true)
		{
			if (bettingMoney > myMoney && bettingMoney != -1)
			{
				cout << "베팅금이 소지금보다 큽니다. 다시 입력해주세요. : ";
				cin >> bettingMoney;
				continue;
			}
			else if (bettingMoney < 100 && bettingMoney != -1)
			{
				cout << "베팅금이 너무 적습니다. 다시 입력해주세요. : ";
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
		//베팅금 차감
		if (bettingMoney == -1)		//die 했을 때
		{
			myMoney -= 100;
			if (betPnt_shape == 1)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♠A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♠J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♠Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♠K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♠" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 2)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ◆A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ◆J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ◆Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ◆K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ◆" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 3)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♥A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♥J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♥Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♥K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♥" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 4)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♣A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♣J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♣Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♣K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♣" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			cout << "플레이어가 Die를 했기 때문에 100원이 차감됩니다." << endl;
			cout << "현재 소지금: " << myMoney << endl;
		}
		else if (!clear && bettingMoney != -1)	//실패
		{
			myMoney -= bettingMoney;
			if (betPnt_shape == 1)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♠A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♠J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♠Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♠K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♠" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 2)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ◆A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ◆J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ◆Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ◆K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ◆" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 3)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♥A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♥J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♥Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♥K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♥" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 4)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♣A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♣J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♣Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♣K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♣" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			cout << "틀렸습니다. 베팅금 차감합니다." << endl;
			cout << "현재 소지금: " << myMoney << endl;
		}
		else if (clear && bettingMoney != -1)	//성공
		{
			myMoney += bettingMoney;
			if (betPnt_shape == 1)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♠A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♠J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♠Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♠K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♠" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 2)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ◆A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ◆J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ◆Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ◆K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ◆" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 3)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♥A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♥J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♥Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♥K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♥" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			else if (betPnt_shape == 4)
			{
				if (bettingPoint == 1) cout << "가려진 카드는 [ ♣A ] 였습니다." << endl << endl;
				else if (bettingPoint == 11) cout << "가려진 카드는 [ ♣J ] 였습니다." << endl << endl;
				else if (bettingPoint == 12) cout << "가려진 카드는 [ ♣Q ] 였습니다." << endl << endl;
				else if (bettingPoint == 13) cout << "가려진 카드는 [ ♣K ] 였습니다." << endl << endl;
				else cout << "가려진 카드는 [ ♣" << bettingPoint << " ] 였습니다." << endl << endl;
			}
			cout << "맞았습니다. 베팅금 받습니다." << endl;
			cout << "현재 소지금: " << myMoney << endl;
		}

		//소지금이 다 털리면
		if (myMoney == 0 || myMoney < 100)
		{
			cout << "소지금이 부족해서 게임을 중단합니다." << endl;
			break;
		}

		Sleep(2000);
		system("cls");

		if (saveIdx == 51)
		{
			//마지막으로 남은 하나의 카드를 보여주고 게임을 끝낸다.
			cout << "마지막 남은 카드" << endl << endl;
			if (trump[saveIdx] > 0 && trump[saveIdx] < 14)
			{
				bettingPoint = trump[saveIdx];
				if (bettingPoint == 1) cout << "  ♠A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ♠J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ♠Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ♠K" << endl << endl;
				else cout << "  ♠" << bettingPoint << endl << endl;
			}
			else if (trump[saveIdx] > 13 && trump[saveIdx] < 27)
			{
				bettingPoint = trump[saveIdx] - 13;
				if (bettingPoint == 1) cout << "  ◆A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ◆J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ◆Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ◆K" << endl << endl;
				else cout << "  ◆" << bettingPoint << endl << endl;
			}
			else if (trump[saveIdx] > 26 && trump[saveIdx] < 40)
			{
				bettingPoint = trump[saveIdx] - 26;
				if (bettingPoint == 1) cout << "  ♥A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ♥J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ♥Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ♥K" << endl << endl;
				else cout << "  ♥" << bettingPoint << endl << endl;
			}
			else if (trump[saveIdx] > 39 && trump[saveIdx] < 53)
			{
				bettingPoint = trump[saveIdx] - 39;
				if (bettingPoint == 1) cout << "  ♣A" << endl << endl;
				else if (bettingPoint == 11) cout << "  ♣J" << endl << endl;
				else if (bettingPoint == 12) cout << "  ♣Q" << endl << endl;
				else if (bettingPoint == 13) cout << "  ♣K" << endl << endl;
				else cout << "  ♣" << bettingPoint << endl << endl;
			}
			cout << "남은 소지금 : " << myMoney << endl << endl;
			break;
		}
	}
}


Gambling::~Gambling()
{
}

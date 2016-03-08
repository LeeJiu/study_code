#include "Player.h"



Player::Player() : _money(100000)
{
}


Player::~Player()
{
}

//선택한 아이템을 받아서 벡터에 푸쉬
void Player::BuyItem(Item * item)
{
	if (_money < item->getSellPrice())
		cout << "소지금이 부족합니다." << endl;
	else
	{
		_item.push_back(item);
		_money -= item->getSellPrice();
		cout << "아이템을 구매했습니다." << endl;
	}
}

//아이템의 번호를 받아서 해당 인덱스의 아이템을 삭제
void Player::SellItem(int nNum)
{
	nNum--;
	/*int i = 0;
	for (_iter = _item.begin(); _iter != _item.end(); ++_iter)
	{
		if (i == nNum)
		{
			_money += (*_iter)->getBuyPrice();
			_iter = _item.erase(_iter);
			break;
		}
		i++;
		if (_item.empty())
			break;
	}*/
	if (_item.empty())
		return;
	else
	{
		_iter = std::find(_item.begin(), _item.end(), _item[nNum]);
		_iter = _item.erase(_iter);
	}
}

void Player::ShowItemList()
{
	cout << "=====================인벤======================" << endl;

	if (_item.empty())
		cout << "소지 아이템이 존재하지 않습니다." << endl;
	else
	{
		int i = 1;
		for (_iter = _item.begin(); _iter != _item.end(); ++_iter)
		{
			cout << i++ << ". " << (*_iter)->getName() << endl;
		}
	}

	cout << "===============================================" << endl << endl;
}

void Player::ShowItemInfo(int nNum)
{
	cout << "=================아이템 정보===================" << endl;
	
	//아이템을 모두 판매하고 아이템 정보에 접근
	//접근할 수 없게 막아줘야함
	if (_item.empty())
	{
		cout << "소지 아이템이 존재하지 않습니다." << endl;
		cout << "===============================================" << endl << endl;
	}
	else
	{
		//인덱스는 0부터 시작하고 아이템 번호는 1부터 시작이기 때문에 -1 해줘야함
		cout << "이름 : " << _item[nNum - 1]->getName() << endl;
		cout << "설명 : " << _item[nNum - 1]->getInfo() << endl;
		cout << "공격력 : " << _item[nNum - 1]->getDamage() << endl;
		cout << "판매 가격 : " << _item[nNum - 1]->getBuyPrice() << endl;
		cout << "===============================================" << endl << endl;
	}
}

void Player::ShowMoney() const
{
	cout << "[현재 플레이어 소지금 : " << _money << "]" << endl << endl;
}

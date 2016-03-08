#include "Player.h"



Player::Player() : _money(100000)
{
}


Player::~Player()
{
}

//������ �������� �޾Ƽ� ���Ϳ� Ǫ��
void Player::BuyItem(Item * item)
{
	if (_money < item->getSellPrice())
		cout << "�������� �����մϴ�." << endl;
	else
	{
		_item.push_back(item);
		_money -= item->getSellPrice();
		cout << "�������� �����߽��ϴ�." << endl;
	}
}

//�������� ��ȣ�� �޾Ƽ� �ش� �ε����� �������� ����
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
	cout << "=====================�κ�======================" << endl;

	if (_item.empty())
		cout << "���� �������� �������� �ʽ��ϴ�." << endl;
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
	cout << "=================������ ����===================" << endl;
	
	//�������� ��� �Ǹ��ϰ� ������ ������ ����
	//������ �� ���� ���������
	if (_item.empty())
	{
		cout << "���� �������� �������� �ʽ��ϴ�." << endl;
		cout << "===============================================" << endl << endl;
	}
	else
	{
		//�ε����� 0���� �����ϰ� ������ ��ȣ�� 1���� �����̱� ������ -1 �������
		cout << "�̸� : " << _item[nNum - 1]->getName() << endl;
		cout << "���� : " << _item[nNum - 1]->getInfo() << endl;
		cout << "���ݷ� : " << _item[nNum - 1]->getDamage() << endl;
		cout << "�Ǹ� ���� : " << _item[nNum - 1]->getBuyPrice() << endl;
		cout << "===============================================" << endl << endl;
	}
}

void Player::ShowMoney() const
{
	cout << "[���� �÷��̾� ������ : " << _money << "]" << endl << endl;
}

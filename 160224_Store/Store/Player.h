#pragma once
#include <vector>
#include <algorithm>
#include "Item.h"

class Player
{
private:
	std::vector<Item*> _item;
	std::vector<Item*>::iterator _iter;
	int _money;

public:
	Player();
	~Player();

	void BuyItem(Item* item);
	void SellItem(int nNum);
	void ShowItemList();
	void ShowItemInfo(int nNum);
	void ShowMoney() const;
};


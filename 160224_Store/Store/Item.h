#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Item
{
private:
	char * _name;
	char * _info;
	int _damage;
	int _sellPrice;
	int _buyPrice;

public:
	Item();
	Item(char * pName, char * pInfo, int nDamage, int nSell, int nBuy);
	~Item();

	char* getName() const;
	char* getInfo() const;
	int getDamage() const;
	int getSellPrice() const;
	int getBuyPrice() const;
};


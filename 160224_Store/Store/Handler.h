#pragma once
#include "Owner.h"
#include "Player.h"
#include <Windows.h>

class Handler
{
private:
	Owner owner;
	Player player;

public:
	Handler();
	~Handler();

	void ShowMenu() const;
	void EnterItemInfo();
	void EnterStore();
	void EnterStoreItemInfo();
	void EnterInventory();
	void Buy();

};


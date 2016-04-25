#include "stdafx.h"
#include "battle.h"


battle::battle()
{
}


battle::~battle()
{
}

HRESULT battle::init(const char * imageName, int x, int y)
{
	ship::init(imageName, x, y);

	return S_OK;
}

void battle::release()
{
	ship::release();
}

void battle::update()
{
	ship::update();
}

void battle::render()
{
	ship::render();
}

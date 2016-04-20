#include "stdafx.h"
#include "block.h"


block::block()
{
}


block::~block()
{
}

HRESULT block::init()
{
	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			tagBlock block;
			ZeroMemory(&block, sizeof(tagBlock));
			block.rc = RectMakeCenter(100 + (j * 80), 20 + (i * 40), 80, 40);
			block.broken = false;
			_vBlock.push_back(block);
		}
	}

	return S_OK;
}

void block::release()
{
}

void block::update()
{
}

void block::render()
{
	for (_viBlock = _vBlock.begin(); _viBlock != _vBlock.end(); ++_viBlock)
	{
		if (_viBlock->broken) continue;

		Rectangle(getMemDC(), _viBlock->rc.left, _viBlock->rc.top, _viBlock->rc.right, _viBlock->rc.bottom);
	}
}

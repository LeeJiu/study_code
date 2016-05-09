#include "stdafx.h"
#include "mapTool.h"

int mapTool::_tileIndex = 0;

mapTool::mapTool()
{
}


mapTool::~mapTool()
{
}

HRESULT mapTool::init()
{
	_tileImage = IMAGEMANAGER->addFrameImage("tile", "image/mapTile.bmp", 208, 156, 4, 3, false, false);

	IMAGEMANAGER->addFrameImage("button", "image/button.bmp", 64, 32, 2, 1, true, 0xff00ff);

	int index;
	for (int y = 0; y < TILENUM; ++y)
	{
		for (int x = 0; x < TILENUM; ++x)
		{
			index = y * TILENUM + x;
			rc[index] = RectMake((index % TILENUM) * _tileImage->getFrameWidth(), y * _tileImage->getFrameHeight(),
				_tileImage->getFrameWidth(), _tileImage->getFrameHeight());
		}
	}

	for (int i = 0; i < TILEMAX; ++i)
	{
		tagTile tile;
		memset(&tile, 0, sizeof(tagTile));
		tile.tile = new image;
		tile.tile->init("image/mapTile.bmp", 208, 156, 4, 3, false, false);
		tile.index = i;
		tile.tileIdx = 100;
		tile.screenPos.x = rc[i].left;
		tile.screenPos.y = rc[i].top;
		_vTile.push_back(tile);
	}

	_btLeft = new button;
	_btLeft->init("button", WINSIZEX - 200, 100, PointMake(0, 0), PointMake(0, 0), onLeftButton);
	_btRight = new button;
	_btRight->init("button", WINSIZEX - 100, 100, PointMake(1, 0), PointMake(1, 0), onRightButton);

	return S_OK;
}

void mapTool::release()
{
	SAFE_DELETE(_btLeft);
	SAFE_DELETE(_btRight);
}

void mapTool::update()
{
	_btLeft->update();
	_btRight->update();

	changeTile();
	keyControl();
}

void mapTool::render()
{
	_btLeft->render();
	_btRight->render();

	_tileImage->frameRender(getMemDC(), WINSIZEX - 150 - _tileImage->getFrameWidth() / 2, 
		100 - _tileImage->getFrameHeight() / 2, _tileFrameX, _tileFrameY);

	for (int i = 0; i < TILEMAX; ++i)
	{
		Rectangle(getMemDC(), rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
	}

	for (int i = 0; i < _vTile.size(); ++i)
	{
		if (!_vTile[i].draw) continue;

		_vTile[i].tile->frameRender(getMemDC(), _vTile[i].screenPos.x, _vTile[i].screenPos.y, 
			_vTile[i].imagePos.x, _vTile[i].imagePos.y);
	}

	char str[128];
	int j = 0;
	for (int i = 100; j < 10; i += 20)
	{
		sprintf_s(str, "%d", _vTile[j].tileIdx);
		TextOut(getMemDC(), WINSIZEX - 150, i, str, strlen(str));
		j++;
	}
}

void mapTool::keyControl()
{
	int index;
	for (int y = 0; y < TILENUM; ++y)
	{
		for (int x = 0; x < TILENUM; ++x)
		{
			index = y * TILENUM + x;
			if (PtInRect(&rc[index], _ptMouse))
			{
				if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
				{
					inputTile(index);
				}
			}
		}
	}

	//맵 데이터를 세이브
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		saveMapData();
	}
	//맵 데이터를 로드
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		loadMapData();
	}
}

void mapTool::changeTile()
{
	_tileFrameX = mapTool::_tileIndex % 4;
	_tileFrameY = mapTool::_tileIndex / 4;
}

void mapTool::inputTile(int idx)
{
	_vTile[idx].draw = true;
	_vTile[idx].imagePos = PointMake(_tileFrameX, _tileFrameY);
	_vTile[idx].screenPos = PointMake(rc[idx].left, rc[idx].top);
	_vTile[idx].tileIdx = _tileFrameY * 4 + _tileFrameX;
}

void mapTool::saveMapData()
{
	char temp[128];

	vector<string> vStr;
	for (_viTile = _vTile.begin(); _viTile != _vTile.end(); ++_viTile)
	{
		vStr.push_back("|");							//구분자
		vStr.push_back(itoa(_viTile->index, temp, 10));
		vStr.push_back(itoa(_viTile->tileIdx, temp, 10));
		vStr.push_back(itoa(_viTile->draw, temp, 10));
	}
	TXTDATA->txtSave("database.txt", vStr);
}

void mapTool::loadMapData()
{
	DATABASE->loadDatabase("database.txt");
	for (int i = 0; i < _vTile.size(); ++i)
	{
		char temp[128];
		_vTile[i].index = DATABASE->getElementData(itoa(_vTile[i].index, temp, 10))->index;
		_vTile[_vTile[i].index].imagePos.x = DATABASE->getElementData(itoa(_vTile[i].index, temp, 10))->state % 4;
		_vTile[_vTile[i].index].imagePos.y = DATABASE->getElementData(itoa(_vTile[i].index, temp, 10))->state / 4;
		_vTile[_vTile[i].index].draw = DATABASE->getElementData(itoa(_vTile[i].index, temp, 10))->draw;
	}
}

void mapTool::onLeftButton()
{
	_tileIndex--;
	if (_tileIndex < 0)
	{
		_tileIndex = 11;
	}
}

void mapTool::onRightButton()
{
	_tileIndex++;
	if (_tileIndex > 11)
	{
		_tileIndex = 0;
	}
}

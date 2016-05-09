#include "stdafx.h"
#include "tile.h"


tile::tile()
{
}


tile::~tile()
{
}

HRESULT tile::init()
{
	for (int col = 0; col < TILECOL; ++col)
	{
		for (int row = 0; row < TILEROW; ++row)
		{
			_tile[row][col].type = NONE;
			_tile[row][col].f = 60000;
			_tile[row][col].g = 0;
			_tile[row][col].h = 0;
			_tile[row][col].parent = &_tile[row][col];
			_tile[row][col].pos.x = row;
			_tile[row][col].pos.y = col;
			_tile[row][col].rc = RectMake(row * 50, col * 50, 50, 50);
		}
	}

	return S_OK;
}

void tile::release()
{
}

void tile::update()
{
	keyControl();
}

void tile::render()
{
	HBRUSH MyBrush, OldBrush;
	MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	OldBrush = (HBRUSH)SelectObject(getMemDC(), MyBrush);

	char str[128];

	for (int col = 0; col < TILECOL; ++col)
	{
		for (int row = 0; row < TILEROW; ++row)
		{
			SetDCBrushColor(getMemDC(), RGB(255, 255, 255));
			Rectangle(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top,
				_tile[row][col].rc.right, _tile[row][col].rc.bottom);
			
			switch (_tile[row][col].type)
			{
			case START:
				SetDCBrushColor(getMemDC(), RGB(255, 0, 0));
				Rectangle(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top,
					_tile[row][col].rc.right, _tile[row][col].rc.bottom);
				break;
			case END:
				SetDCBrushColor(getMemDC(), RGB(0, 0, 255));
				Rectangle(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top,
					_tile[row][col].rc.right, _tile[row][col].rc.bottom);
				break;
			case BLOCK:
				SetDCBrushColor(getMemDC(), RGB(0, 255, 0));
				Rectangle(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top,
					_tile[row][col].rc.right, _tile[row][col].rc.bottom);
				break;
			case CHECK:
				SetDCBrushColor(getMemDC(), RGB(64, 64, 255));
				Rectangle(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top,
					_tile[row][col].rc.right, _tile[row][col].rc.bottom);
				break;
			case OPEN:
				SetDCBrushColor(getMemDC(), RGB(128, 128, 128));
				Rectangle(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top,
					_tile[row][col].rc.right, _tile[row][col].rc.bottom);
				break;
			case NONE:
				break;
			}

			sprintf_s(str, "%d", _tile[row][col].f);
			TextOut(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.top, str, strlen(str));
			
			sprintf_s(str, "%d", _tile[row][col].g);
			TextOut(getMemDC(), _tile[row][col].rc.left, _tile[row][col].rc.bottom - 15, str, strlen(str));
			
			sprintf_s(str, "%d", _tile[row][col].h);
			TextOut(getMemDC(), _tile[row][col].rc.right - 25, _tile[row][col].rc.bottom - 15, str, strlen(str));
		}
	}

	SelectObject(getMemDC(), OldBrush);
	DeleteObject(MyBrush);

	if (_end)
	{
		drawRoad(_vCloseList.back());
	}

	sprintf_s(str, "_startX : %d, _startY : %d", _startX, _startY);
	TextOut(getMemDC(),WINSIZEX - 150, 70, str, strlen(str));

	sprintf_s(str, "_endX : %d, _endY : %d", _endX, _endY);
	TextOut(getMemDC(), WINSIZEX - 150, 90, str, strlen(str));

	if (!_vCloseList.empty())
	{
		sprintf_s(str, "c_sX : %d, c_sY : %d", _vCloseList.front()->pos.x, _vCloseList.front()->pos.y);
		TextOut(getMemDC(), WINSIZEX - 150, 110, str, strlen(str));
		sprintf_s(str, "c_endX : %d, c_endY : %d", _vCloseList.back()->pos.x, _vCloseList.back()->pos.y);
		TextOut(getMemDC(), WINSIZEX - 150, 130, str, strlen(str));

		sprintf_s(str, "closeSize : %d", _vCloseList.size());
		TextOut(getMemDC(), WINSIZEX - 150, 150, str, strlen(str));
	}
	if (!_vOpenList.empty())
	{
		sprintf_s(str, "openSize : %d", _vOpenList.size());
		TextOut(getMemDC(), WINSIZEX - 150, 170, str, strlen(str));
	}
}

void tile::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) _remove = !_remove;
	if (KEYMANAGER->isStayKeyDown(VK_RETURN))
	{
		if (!_end)
		{
			_start = true;
			searchVicinity();
		}
	}

	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		reset();
	}

	for (int col = 0; col < TILECOL; ++col)
	{
		for (int row = 0; row < TILEROW; ++row)
		{
			if (PtInRect(&_tile[row][col].rc, _ptMouse) && !_start)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					if (_tile[row][col].type != END && _tile[row][col].type != BLOCK)
					{
						_tile[_startX][_startY].type = NONE;
						_startX = row;
						_startY = col;
						_tile[row][col].type = START;
						_tile[row][col].parent = &_tile[row][col];	//자기 자신을 부모로

						if (_vCloseList.empty())
						{
							_vCloseList.push_back(&_tile[row][col]);
						}
						else
						{
							_vCloseList.clear();
							_vCloseList.push_back(&_tile[row][col]);
						}
					}
				}
				if (KEYMANAGER->isOnceKeyDown(VK_MBUTTON))
				{
					if (_tile[row][col].type != START && _tile[row][col].type != BLOCK)
					{
						_tile[_endX][_endY].type = NONE;
						_endX = row;
						_endY = col;
						_tile[row][col].type = END;
					}
				}
				if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
				{
					if (_tile[row][col].type != START && _tile[row][col].type != END && !_remove)
						_tile[row][col].type = BLOCK;
					else if(_tile[row][col].type != START && _tile[row][col].type != END && _remove)
						_tile[row][col].type = NONE;
				}
			}
		}
	}
}

void tile::inputCloseList()
{
	sort(_vOpenList.begin(), _vOpenList.end(), Compare);

	_viOpenList = _vOpenList.begin();

	if (checkCloseList((*_viOpenList)->pos.x, (*_viOpenList)->pos.y))
	{
		_vCloseList.push_back(*_viOpenList);
	}
	else
	{
		_viOpenList++;
		_vCloseList.push_back(*_viOpenList);
	}
	
	_vCloseList.back()->type = CHECK;

	if (_vCloseList.back()->h == 0)
	{
		_end = true;
		return;
	}

	_vOpenList.erase(_viOpenList);
}

void tile::checkOpenList(int x, int y)
{
	if (_vOpenList.empty()) return;

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if ((*_viOpenList)->pos.x == x && (*_viOpenList)->pos.y == y)
		{
			_vOpenList.erase(_viOpenList);
			break;
		}
	}
}

bool tile::checkCloseList(int x, int y)
{
	if (_vCloseList.empty()) return true;

	for (_viCloseList = _vCloseList.begin(); _viCloseList != _vCloseList.end(); ++_viCloseList)
	{
		if ((*_viCloseList)->pos.x == x && (*_viCloseList)->pos.y == y)
		{
			return false;
		}
	}
	return true;
}

void tile::searchVicinity()
{
	if (!_vOpenList.empty())
	{
		inputCloseList();
	}

	int distX, distY, sourX, sourY, f, g, h;

	for (int x = _vCloseList.back()->pos.x - 1; x < _vCloseList.back()->pos.x + 2; ++x)
	{
		for (int y = _vCloseList.back()->pos.y - 1; y < _vCloseList.back()->pos.y + 2; ++y)
		{
			if (x < 0 || y < 0 || x >= TILEROW || y >= TILECOL) continue;
			if (_tile[x][y].type == BLOCK || _tile[x][y].type == CHECK) continue;

			distX = abs(_endX - x);
			distY = abs(_endY - y);
			sourX = (_vCloseList.back()->pos.x - x);
			sourY = (_vCloseList.back()->pos.y - y);

			if (sourX == -1 && sourY == 1)
			{
				if (_tile[x - 1][y].type == BLOCK || _tile[x][y + 1].type == BLOCK) continue;
			}
			else if (sourX == 1 && sourY == 1)
			{
				if (_tile[x + 1][y].type == BLOCK || _tile[x][y + 1].type == BLOCK) continue;
			}
			else if (sourX == 1 && sourY == -1)
			{
				if (_tile[x][y - 1].type == BLOCK || _tile[x + 1][y].type == BLOCK) continue;
			}
			else if (sourX == -1 && sourY == -1)
			{
				if (_tile[x - 1][y].type == BLOCK || _tile[x][y - 1].type == BLOCK) continue;
			}


			if ((sourX < 0 && sourY < 0) || (sourX > 0 && sourY > 0)
				|| (sourX < 0 && sourY > 0) || (sourX > 0 && sourY < 0))
			{
				g = _vCloseList.back()->g + _tile[x][y].parent->g + 14;
				if (x == _startX && y == _startY) g = 0;
			}
			else
			{
				g = _vCloseList.back()->g + _tile[x][y].parent->g + 10;
				if (x == _startX && y == _startY) g = 0;
			}

			h = (distX + distY) * 10;
			f = h + g;

			if (f < _tile[x][y].f)
			{
				_tile[x][y].f = f;
				_tile[x][y].g = g;
				_tile[x][y].h = h;
				_tile[x][y].parent = &_tile[_vCloseList.back()->pos.x][_vCloseList.back()->pos.y];
			}

			checkOpenList(x, y);
			if (_tile[x][y].type != START)
			{
				_vOpenList.push_back(&_tile[x][y]);
				_vOpenList.back()->type = OPEN;
			}
		}
	}
}

void tile::reset()
{
	_start = false;
	_end = false;

	for (_viCloseList = _vCloseList.begin(); _viCloseList != _vCloseList.end(); )
	{
		_viCloseList = _vCloseList.erase(_viCloseList);
	}

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); )
	{
		_viOpenList = _vOpenList.erase(_viOpenList);
	}

	for (int col = 0; col < TILECOL; ++col)
	{
		for (int row = 0; row < TILEROW; ++row)
		{
			_tile[row][col].type = NONE;
			_tile[row][col].f = 60000;
			_tile[row][col].g = 0;
			_tile[row][col].h = 0;
			_tile[row][col].parent = &_tile[row][col];
			_tile[row][col].pos.x = row;
			_tile[row][col].pos.y = col;
			_tile[row][col].rc = RectMake(row * 50, col * 50, 50, 50);
		}
	}
}

void tile::drawRoad(tagTile * tile)
{
	if (tile->type == START) return;

	int x1, y1, x2, y2;

	x1 = tile->rc.left + (tile->rc.right - tile->rc.left) / 2;
	y1 = tile->rc.top + (tile->rc.bottom - tile->rc.top) / 2;

	x2 = tile->parent->rc.left + (tile->parent->rc.right - tile->parent->rc.left) / 2;
	y2 = tile->parent->rc.top + (tile->parent->rc.bottom - tile->parent->rc.top) / 2;

	LineMake(getMemDC(), x1, y1, x2, y2);

	drawRoad(tile->parent);
}

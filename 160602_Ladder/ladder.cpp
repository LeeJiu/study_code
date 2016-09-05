#include "stdafx.h"
#include "ladder.h"


ladder::ladder()
{
}


ladder::~ladder()
{
}

HRESULT ladder::init()
{
	for (int y = 0; y < ROW; ++y)
	{
		for (int x = 0; x < COLUMN; ++x)
		{
			if (y == 0)
			{
				_node[y][x].state = START;
				_node[y][x].x = 100 + (x * 100);
				_node[y][x].y = 50;
				_node[y][x].next = NULL;
				_node[y][x].down = NULL;
			}
			else if (y == ROW - 1)
			{
				_node[y][x].state = END;
				_node[y][x].x = 100 + (x * 100);
				_node[y][x].y = 50 + (y * 50);
				_node[y][x].next = NULL;
				_node[y][x].down = NULL;
			}
			else
			{
				_node[y][x].state = NORMAL;
				_node[y][x].x = 100 + (x * 100);
				_node[y][x].y = 50 + (y * 50);
				_node[y][x].next = NULL;
				_node[y][x].down = NULL;
			}
		}
	}

	for (int y = 0; y < ROW; ++y)
	{
		for (int x = 0; x < COLUMN; ++x)
		{
			if (_node[y][x].state == START || _node[y][x].state == END) continue;
			if (_node[y][x].next != NULL) continue;
			if (x + 1 == COLUMN) continue;

			int rnd = RND->getFromIntTo(1, ROW - 2);
			if (_node[rnd][x].next != NULL || _node[rnd][x + 1].next != NULL) continue;

			_node[rnd][x].next = &_node[rnd][x + 1];
			_node[rnd][x + 1].next = &_node[rnd][x];
			_node[rnd][x].down = &_node[rnd + 1][x];
			_node[rnd][x + 1].down = &_node[rnd + 1][x + 1];
		}
	}

	for (int y = 0; y < ROW; ++y)
	{
		for (int x = 0; x < COLUMN; ++x)
		{
			if (_node[y][x].state == START || _node[y][x].state == END) continue;
			if (_node[y][x].next != NULL) continue;

			_node[y][x].next = &_node[y + 1][x];
		}
	}

	for (int i = 0; i < COLUMN; ++i)
	{
		_player[i].num = i + 1;
		_player[i].x = _node[0][i].x;
		_player[i].y = _node[0][i].y;
		_player[i].player = RectMakeCenter(_player[i].x, _player[i].y, 30, 30);
		_player[i].next = &_node[1][i];
		_player[i].isNext = false;
	}

	return S_OK;
}

void ladder::release()
{
}

void ladder::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isMove = true;
	}

	if (_isMove)
	{
		move();
	}
}

void ladder::render()
{
	for (int y = 0; y < ROW; ++y)
	{
		for (int x = 0; x < COLUMN; ++x)
		{
			if (_node[y][x].state == END) continue;
			LineMake(getMemDC(), _node[y][x].x, _node[y][x].y, _node[y + 1][x].x, _node[y + 1][x].y);
		}
	}

	for (int y = 0; y < ROW; ++y)
	{
		for (int x = 0; x < COLUMN; ++x)
		{
			SetPixel(getMemDC(), _node[y][x].x, _node[y][x].y, 0x000000);
			SetPixel(getMemDC(), _node[y][x].x, _node[y][x].y+1, 0x000000);
			SetPixel(getMemDC(), _node[y][x].x+1, _node[y][x].y, 0x000000);
			SetPixel(getMemDC(), _node[y][x].x+1, _node[y][x].y+1, 0x000000);

			if (_node[y][x].state == START || _node[y][x].state == END) continue;
			if (x - 1 == COLUMN) continue;

			//if (_node[y][x].down == NULL)
			//{
			//	char str[128];
			//	sprintf_s(str, "%d", 0);
			//	TextOut(getMemDC(), _node[y][x].x, _node[y][x].y, str, strlen(str));
			//}

			LineMake(getMemDC(), _node[y][x].x, _node[y][x].y, _node[y][x].next->x, _node[y][x].next->y);
		}
	}

	char str[128];

	for (int i = 0; i < COLUMN; ++i)
	{
		Rectangle(getMemDC(), _player[i].player.left, _player[i].player.top, 
			_player[i].player.right, _player[i].player.bottom);
		sprintf_s(str, "%d", _player[i].num);
		TextOut(getMemDC(), _player[i].player.left, _player[i].player.top, str, strlen(str));
	}
}

void ladder::move()
{
	_moveCnt = 0;

	for (int i = 0; i < COLUMN; ++i)
	{
		if (_player[i].isEnd) continue;

		if (_player[i].next->x < _player[i].x)
		{
			_player[i].isNext = true;
			_player[i].x -= 1;
		}
		else if (_player[i].next->x > _player[i].x)
		{
			_player[i].isNext = true;
			_player[i].x += 1;
		}

		if(_player[i].next->y > _player[i].y)
			_player[i].y += 1;

		if (_player[i].x == _player[i].next->x && _player[i].y == _player[i].next->y)
		{
			if (_player[i].next->state == END)
			{
				_player[i].isEnd = true;
				_moveCnt++;
				if (_moveCnt == COLUMN)
				{
					_isMove = false;
					return;
				}
			}

			if (_player[i].next->down == NULL && !_player[i].isNext)
			{
				_player[i].next = _player[i].next->next;
			}
			else if (_player[i].next->down != NULL && !_player[i].isNext)
			{
				_player[i].next = _player[i].next->next;
				_player[i].isNext = true;
			}
			else if (_player[i].next->down != NULL && _player[i].isNext)
			{
				_player[i].next = _player[i].next->down;
				_player[i].isNext = false;
			}
		}

		_player[i].player = RectMakeCenter(_player[i].x, _player[i].y, 30, 30);
	}
}

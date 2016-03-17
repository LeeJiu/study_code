#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init();

	_background = new image;
	_background->init("puzzle.bmp", WINSIZEX, WINSIZEY);	//윈도우 사이즈와 이미지를 맞춤
	//투명화 시킬 경우, true: 투명화한다, RGB(): 특정 색을 투명화한다
	//_background->setTransColor(true, RGB(255, 0, 255));
	
	clearCnt = 0;

	//순서대로 인덱스 번호를 주자
	for (int i = 0; i < PUZZLENUM; ++i)
	{
		_puzzle[i].idx = i;
	}
	
	//무질서도를 반환받자
	int entropy = shuffle(_puzzle);
	//무질서도가 홀수이면 무질서도가 짝수일 때까지 다시 셔플해라
	while (entropy % 2 == 1)
	{
		entropy = shuffle(_puzzle);
	}

	//렉트의 좌표 초기화
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_puzzle[num++].puzzle = RectMake(WINSIZEX / 3 * j, WINSIZEY / 3 * i,
				WINSIZEX / 3, WINSIZEY / 3);
		}
	}
	
	return S_OK;
}

void gameStudy::release()
{
	_background->release();
	SAFE_DELETE(_background);

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < PUZZLENUM; ++i)
		{
			if (PtInRect(&_puzzle[i].puzzle, _ptMouse))
			{
				for (int j = 0; j < PUZZLENUM; ++j)
				{
					//위 / 퍼즐의 인덱스가 8이라면 빈칸 -> 인덱스를 swap해주자
					if (_puzzle[i].puzzle.top == _puzzle[j].puzzle.bottom 
						&& _puzzle[i].puzzle.left == _puzzle[j].puzzle.left
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
					//아래
					else if (_puzzle[i].puzzle.bottom == _puzzle[j].puzzle.top 
						&& _puzzle[i].puzzle.left == _puzzle[j].puzzle.left
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
					//좌
					else if (_puzzle[i].puzzle.left == _puzzle[j].puzzle.right 
						&& _puzzle[i].puzzle.top == _puzzle[j].puzzle.top
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
					//우
					else if (_puzzle[i].puzzle.right == _puzzle[j].puzzle.left 
						&& _puzzle[i].puzzle.top == _puzzle[j].puzzle.top
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
				}
			}
		}
	}

	for (int i = 0; i < PUZZLENUM; i++)
	{
		//퍼즐의 인덱스가 순차적이라면 카운트하자
		if (_puzzle[i].idx == i) clearCnt++;
		else
		{
			clearCnt = 0;
			break;
		}
	}

	//전부 맞추면 다시 초기화시켜 주자
	if (clearCnt == PUZZLENUM)
	{
		release();
		init();
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();

	//배경을 채운다(WHITENESS / 하얀색)
	//PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	for (int i = 0; i < PUZZLENUM; ++i)
	{
		_background->render2(backDC, &_puzzle[i].puzzle, _puzzle[i].idx);
		if (_puzzle[i].idx == 8)		//인덱스가 8이면 빈칸 그려주자
			Rectangle(backDC, _puzzle[i].puzzle.left, _puzzle[i].puzzle.top, _puzzle[i].puzzle.right, _puzzle[i].puzzle.bottom);
	}

	this->getBackBuffer()->render(hdc, 0, 0);
}

int gameStudy::shuffle(tagPuzzle * pz)
{
	int entropy = 0;

	for (int i = 0; i < 20; ++i)
	{
		//우하단의 빈칸만 남기고 셔플해주자
		int dst = RND->getInt(PUZZLENUM - 1);
		int src = RND->getInt(PUZZLENUM - 1);

		tagPuzzle tmp = pz[dst];
		pz[dst] = pz[src];
		pz[src] = tmp;
	}
	
	//인덱스가 증가함에 따른 엔트로피 증가값
	for (int i = 0; i < PUZZLENUM; ++i)
	{
		for (int j = i + 1; j < PUZZLENUM; ++j)
		{
			if (pz[i].idx > pz[j].idx)
			{
				entropy++;
			}
		}
	}

	return entropy;
}

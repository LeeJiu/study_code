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
	_background->init("puzzle.bmp", WINSIZEX, WINSIZEY);	//������ ������� �̹����� ����
	//����ȭ ��ų ���, true: ����ȭ�Ѵ�, RGB(): Ư�� ���� ����ȭ�Ѵ�
	//_background->setTransColor(true, RGB(255, 0, 255));
	
	clearCnt = 0;

	//������� �ε��� ��ȣ�� ����
	for (int i = 0; i < PUZZLENUM; ++i)
	{
		_puzzle[i].idx = i;
	}
	
	//���������� ��ȯ����
	int entropy = shuffle(_puzzle);
	//���������� Ȧ���̸� ���������� ¦���� ������ �ٽ� �����ض�
	while (entropy % 2 == 1)
	{
		entropy = shuffle(_puzzle);
	}

	//��Ʈ�� ��ǥ �ʱ�ȭ
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
					//�� / ������ �ε����� 8�̶�� ��ĭ -> �ε����� swap������
					if (_puzzle[i].puzzle.top == _puzzle[j].puzzle.bottom 
						&& _puzzle[i].puzzle.left == _puzzle[j].puzzle.left
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
					//�Ʒ�
					else if (_puzzle[i].puzzle.bottom == _puzzle[j].puzzle.top 
						&& _puzzle[i].puzzle.left == _puzzle[j].puzzle.left
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
					//��
					else if (_puzzle[i].puzzle.left == _puzzle[j].puzzle.right 
						&& _puzzle[i].puzzle.top == _puzzle[j].puzzle.top
						&& _puzzle[j].idx == 8)
					{
						int tmp = _puzzle[i].idx;
						_puzzle[i].idx = _puzzle[j].idx;
						_puzzle[j].idx = tmp;
					}
					//��
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
		//������ �ε����� �������̶�� ī��Ʈ����
		if (_puzzle[i].idx == i) clearCnt++;
		else
		{
			clearCnt = 0;
			break;
		}
	}

	//���� ���߸� �ٽ� �ʱ�ȭ���� ����
	if (clearCnt == PUZZLENUM)
	{
		release();
		init();
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//����ۿ��� �ѷ��ش�
	HDC backDC = this->getBackBuffer()->getMemDC();

	//����� ä���(WHITENESS / �Ͼ��)
	//PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	for (int i = 0; i < PUZZLENUM; ++i)
	{
		_background->render2(backDC, &_puzzle[i].puzzle, _puzzle[i].idx);
		if (_puzzle[i].idx == 8)		//�ε����� 8�̸� ��ĭ �׷�����
			Rectangle(backDC, _puzzle[i].puzzle.left, _puzzle[i].puzzle.top, _puzzle[i].puzzle.right, _puzzle[i].puzzle.bottom);
	}

	this->getBackBuffer()->render(hdc, 0, 0);
}

int gameStudy::shuffle(tagPuzzle * pz)
{
	int entropy = 0;

	for (int i = 0; i < 20; ++i)
	{
		//���ϴ��� ��ĭ�� ����� ����������
		int dst = RND->getInt(PUZZLENUM - 1);
		int src = RND->getInt(PUZZLENUM - 1);

		tagPuzzle tmp = pz[dst];
		pz[dst] = pz[src];
		pz[src] = tmp;
	}
	
	//�ε����� �����Կ� ���� ��Ʈ���� ������
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

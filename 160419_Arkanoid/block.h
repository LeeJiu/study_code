#pragma once
#include "gameNode.h"
#include <vector>

struct tagBlock
{
	image* block;
	RECT rc;
	bool broken;
};

class block : public gameNode
{
private:
	vector<tagBlock> _vBlock;
	vector<tagBlock>::iterator _viBlock;

public:
	block();
	~block();

	HRESULT init();
	void release();
	void update();
	void render();

	vector<tagBlock>& getVBlock() { return _vBlock; }
	vector<tagBlock>::iterator getVIBlock() { return _viBlock; }
};


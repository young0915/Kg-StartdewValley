#pragma once
#include "gameNode.h"
#include "tileManager.h"

struct treetwo
{
	image* _img;
	RECT rc;
	RECT midrc;
	float x, y;
	bool _isnear;
};

class town2:public gameNode
{
private:
	tileManager* _tilem;
	treetwo _tree[2];
	treetwo _twtree[2];
public :
	town2();
	~town2();
	
	HRESULT init();
	void release();
	void update();
	void render();
};


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

	RECT myhome;						//집으로 가는랙트 
	RECT myhomerect;
	image* _twinkle;
	bool istwinkle;
	int i;
public :
	town2();
	~town2();
	
	HRESULT init();
	void release();
	void update();
	void render();
};


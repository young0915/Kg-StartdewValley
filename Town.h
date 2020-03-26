#pragma once
#include "gameNode.h"
#include "tileManager.h"

struct treeone
{
	image* _img;
	RECT rc;
	RECT midrc;
	float x, y;
	bool _isnear;
};


class Town :public gameNode
{
private:
	tileManager* _tilem;
	treeone _tree[2];
	treeone _twtree[2];
public :
	Town();
	~Town();

	HRESULT init();
	void release();
	void update();
	void render();
};


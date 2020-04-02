#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "NPCMANAGER.h"


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
	RECT martgo;
	RECT martgotwinkle;
	image* _bkimg;
	bool istwinkle;
	int i = 0;
	NPCMANAGER* _npcmanager;
public :
	Town();
	~Town();

	HRESULT init();
	void release();
	void update();
	void render();
};


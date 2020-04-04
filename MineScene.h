#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "aStarScene.h"
#include "othermanager.h"
#include "Monstermanager.h"
#include "item.h"
class MineScene :public gameNode
{
private:
	tileManager* _tilm;
	aStarScene* _astar;
	othermanager* _other;
	Monstermanager* _monster;
	RECT myland;
	RECT mylandrmidle;
	vector<item> _dropitem;
	vector<item> _item;

	bool istwinkle;
	int   i = 0;

	RECT rockdrop[4];
	image* _night; 

	effect* drop1;
	effect* drop2;
	effect* drop3;
	effect* drop4;
	int count;

public:
	MineScene();
	~MineScene();

	HRESULT init();
	void release();
	void update();
	void render();
	void mashrock();

};


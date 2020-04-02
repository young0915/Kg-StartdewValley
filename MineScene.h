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
	int   i = -0;

	image* _night; 
public:
	MineScene();
	~MineScene();

	HRESULT init();
	void release();
	void update();
	void render();

};


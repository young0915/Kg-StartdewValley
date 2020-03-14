#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "aStarScene.h"
class MineScene :public gameNode
{
private:
	tileManager* _tilm;
	aStarScene* _astar;
public:
	MineScene();
	~MineScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


#pragma once
#include "gameNode.h"
class MineScene :public gameNode
{
private:
	tagTile _tile[TILEX* TILEY];
	tagTile _temp[TILEX* TILEY];
public:
	MineScene();
	~MineScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void mapinit();
	void maprender();
};


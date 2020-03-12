#pragma once
#include "gameNode.h"
#include "tileManager.h"
class MineScene :public gameNode
{
private:
	tileManager* _tilm;

public:
	MineScene();
	~MineScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


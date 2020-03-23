#pragma once
#include "gameNode.h"
#include "tileManager.h"
class town2:public gameNode
{
private:
	tileManager* _tilem;
public :
	town2();
	~town2();
	
	HRESULT init();
	void release();
	void update();
	void render();
};


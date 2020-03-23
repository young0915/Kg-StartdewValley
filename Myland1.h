#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Myland1:public gameNode
{
private:
	tileManager* _tilem;
	

public :
	Myland1();
	~Myland1();

	HRESULT init();
	void release();
	void update();
	void render();
};


#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Myland2 : public gameNode
{
private :
	tileManager* _tilem;

public :
	Myland2();
	~Myland2();

	HRESULT init();
	void release();
	void update();
	void render();
};


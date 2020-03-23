#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Myland3 :public gameNode
{
private :
	tileManager* _tilem;
public :
	Myland3();
	~Myland3();

	HRESULT init();
	void release();
	void update();
	void render();
};


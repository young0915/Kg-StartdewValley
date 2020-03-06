#pragma once
#include "gameNode.h"
#include "maptool.h"
class Myland : public gameNode
{
public :
	Myland();
	~Myland();

	HRESULT init();
	void release();
	void update();
	void render();

};


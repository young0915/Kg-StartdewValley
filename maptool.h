#pragma once
#include "gameNode.h"
class maptool : public gameNode 
{
private:


public :
	maptool();
	~maptool();

	HRESULT init();
	void release();
	void update();
	void render();


};


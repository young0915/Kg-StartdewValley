#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Myhouse : public gameNode
{
private:
	tileManager* _tilem;
public :
	Myhouse();
	~Myhouse();

	HRESULT init();
	void release();
	void update();
	void render();
};


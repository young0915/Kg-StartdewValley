#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Myland : public gameNode
{
private:
	tileManager* _tilem;
public:
	Myland();
	~Myland();

	HRESULT init();
	void release();
	void update();
	void render();
};


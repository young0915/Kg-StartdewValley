#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Myland : public gameNode
{
private:
	tileManager* _tilem;
	RECT _minego;
	RECT _myhouse;
public:
	Myland();
	~Myland();

	HRESULT init();
	void release();
	void update();
	void render();
};


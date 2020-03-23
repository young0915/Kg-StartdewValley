#pragma once
#include "gameNode.h"
#include "tileManager.h"
class Town :public gameNode
{
private:
	tileManager* _tilem;
public :
	Town();
	~Town();

	HRESULT init();
	void release();
	void update();
	void render();
};


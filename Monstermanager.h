#pragma once
#include "gameNode.h" 
class Monstermanager :public gameNode
{
private :

public :
	Monstermanager();
	~Monstermanager();

	HRESULT init();
	void release();
	void update();
	void render();
};


#pragma once
#include "gameNode.h"
class astar : public gameNode
{
private :

public :
	astar();
	~astar();

	HRESULT init();
	void release();
	void update();
	void   render();
};


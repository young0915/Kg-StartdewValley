#pragma once
#include "gameNode.h"

enum RATSTATE
{
	R_IDLE,
	R_MOVE,
	R_DIE
};

enum RATMOVE
{
	R_LEFT,
	R_RIGHT,
	R_UP,
	R_DOWN
};

struct tagrat
{
	RATSTATE _rat;
	RATMOVE _rmove;
	image* img;
	RECT  rc;
	RECT collison1;
	RECT collison2;
	RECT collison3;
	float x, y;
};

class rat:public gameNode
{
private:

public :
	rat();
	~rat();

	HRESULT init();
	void release();
	void update();
	void render();

	tagrat _rat;

	RECT getrat() { return _rat.rc; }
	void	setrat(RECT _rc) { _rat.rc = _rc; }



	tagrat getratInfo() { return _rat; }
};


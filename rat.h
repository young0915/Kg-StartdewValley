#pragma once
#include "gameNode.h"
#include "item.h"
enum RATSTATE
{
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
	animation* _ani;
	RECT  rc;
	RECT collison1;
	RECT collison2;
	RECT collison3;
	float x, y;
	int count;
	int index;
	bool _isdie;
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
	RATMOVE getMove() { return _rat._rmove; }
	void setMove(RATMOVE _ratmove) { _rat._rmove = _ratmove; }

	void ratmove();

	tagrat getratInfo() { return _rat; }

	void remove(int num);
};






#pragma once
#include "gameNode.h"

struct  tagssebastian
{
	image* _img;
	animation* _ani;
	RECT rc;
	bool _ischeck;
};

class Sebastian :public gameNode
{
private:
	tagssebastian _sebi;
public :
	Sebastian();
	~Sebastian();

	HRESULT init();
	void update(); 
	void release();
	void render();

	void dialogrender();

	RECT getdsebi() {return _sebi.rc;	}
};




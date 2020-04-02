#pragma once
#include "gameNode.h"

struct tagAlex
{
	image* _img;
	animation* _ani;
	RECT rc;
	bool ischeck;
};
class Alex :public gameNode
{
private:
	tagAlex _alex;
public :
	Alex();
	~Alex();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void dialogrender();

	RECT getalex() { return _alex.rc; }
};


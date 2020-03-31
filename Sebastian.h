#pragma once
#include "NPCMANAGER.h"

struct  tagssebastian
{
	image* _img;
	animation* _ani;
	RECT rc;
};

class Sebastian :public NPCMANAGER
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
};




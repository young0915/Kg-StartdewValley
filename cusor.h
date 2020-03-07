#pragma once
#include "gameNode.h"

//커서 구조체
struct  tagcursor
{
	image* img;
	float x, y;
	RECT rc;
};

class cusor :public gameNode
{
private:
	tagcursor _cursor;
public :
	cusor();
	~cusor();

	HRESULT init();
	void release();
	void update();
	void render();
};


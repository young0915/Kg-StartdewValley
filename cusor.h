#pragma once
#include "gameNode.h"

//Ŀ�� ����ü
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


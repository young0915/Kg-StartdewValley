#pragma once
//#include "gameNode.h"
//Ŀ�� ����ü
#include "singletonBase.h"

struct  tagcursor
{
	image* img;
	float x, y;
	RECT rc;
	POINT cursor;
};

class cusor :public singletonBase<cusor>
{
private:
	tagcursor _cursor;

public :
	cusor();
	~cusor();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	POINT getPoint() { return _cursor.cursor; }
};


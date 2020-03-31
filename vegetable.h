#pragma once
#include "gameNode.h"

enum VEGETABLESTATE
{
	NOT_GROW,
	GROWING,
	PICK
};

class vegetable :public gameNode
{
private:
	VEGETABLESTATE _isgrow;									//야채 상태를 알기 위한 값 
	RECT rc;																	//야채 rect
	int count;																//카운트
	int index;
	bool _isgrowup;													//다 자랐나? 상태를 바꾸라
	item _item;
	image* _vegetableimg;										//야채 이미지

public :
	vegetable();
	~vegetable();

	HRESULT init(const char* imagename, POINT postion, VEGETABLESTATE vegstate, bool isgrowup);

	void release();
	void update();
	void render();

	void vegatablegrow();

	VEGETABLESTATE getstateveg() { return _isgrow; }
	void setstateveg(VEGETABLESTATE _state) { _isgrow = _state; }


	RECT getrect() { return rc; }
	item getitem() { return _item; }
};


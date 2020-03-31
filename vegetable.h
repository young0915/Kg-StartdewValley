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
	VEGETABLESTATE _isgrow;									//��ä ���¸� �˱� ���� �� 
	RECT rc;																	//��ä rect
	int count;																//ī��Ʈ
	int index;
	bool _isgrowup;													//�� �ڶ���? ���¸� �ٲٶ�
	item _item;
	image* _vegetableimg;										//��ä �̹���

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


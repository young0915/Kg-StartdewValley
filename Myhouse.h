#pragma once
#include "gameNode.h"
#include "tileManager.h"

struct  tagsleep
{
	RECT bedrect;
	float x, y;
};

class Myhouse : public gameNode
{
private:
	tileManager* _tilem;
	RECT askrect[2];											//����� â
	tagsleep _sleep;
	RECT bedrect;
	bool ischeck;													//�߰��� ����� UI
	bool isblank;													//
	int time;
	image* _bk;
	int i;
public :
	Myhouse();
	~Myhouse();

	HRESULT init();
	void release();
	void update();
	void render();

	void uirender();
	

};


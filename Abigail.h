#pragma once
#include "gameNode.h"

struct  taghumanone
{
	image* img;
	animation* animation;
	RECT rc;
	bool ischeck;
};

class Abigail :public gameNode
{
private:
	taghumanone _abigail;
public:
	Abigail();
	~Abigail();

	HRESULT init();
	void release();
	void update();
	void render();
	void dialogrender();
	

	RECT getabigail() { return _abigail.rc; }
};


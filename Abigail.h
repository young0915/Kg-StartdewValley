#pragma once
#include "NPCMANAGER.h"

struct  taghumanone
{
	image* img;
	animation* animation;
	RECT rc;
};

class Abigail :public NPCMANAGER
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
};


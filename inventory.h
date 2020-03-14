#pragma once
#include "gameNode.h"

struct taginventroy
{
	image* _img;
	RECT rc;
	float x, y;
};
class inventory :public gameNode
{
private:
	vector<taginventroy>_vinven;
	vector<taginventroy>::iterator _vIinven;

	taginventroy _invenback;
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();
	void render();
};


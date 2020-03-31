#pragma once
#include "NPCMANAGER.h"

struct tagAlex
{
	image* _img;
	animation* _ani;
	RECT rc;
};
class Alex :public NPCMANAGER
{
private:
	tagAlex _alex;
public :
	Alex();
	~Alex();

	HRESULT init();
	void release();
	void update();
	void render();
};


#pragma once
#include "gameNode.h"

struct taginventroy
{
	image* _img;
	RECT rc;
	float x, y;
};
struct taginvenimg 
{
	image* img;
	float x, y;
	RECT invenrc;
};
struct tagbutton
{
	RECT _btnrc;
	float x, y;
};
class inventory :public gameNode
{
private:
	image* _bk;																										//뒷배경 
	taginvenimg _invenmain;																				//인벤

	vector<taginventroy>_vinven;
	vector<taginventroy>::iterator _vIinven;

	taginventroy _invenback;
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();
	void render();																		//화면상 보이는 그냥 랜더
	void invenrender();																//E번을 눌렀을 때 보이는 랜더
	void itemrender();																//아이템 랜더
	
};


#pragma once
#include "item.h"
#include "gameNode.h"
//인벤토리 요소 들어갈 것 
struct taginventroy
{
	item _item;
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
	taginventroy _invenelement;																			//인벤토리 칸

	bool isuse;																											//E번을 눌렀냐 안눌렸냐
	vector<taginventroy>_vinven;
	vector<taginventroy>::iterator _vIinven;

	taginventroy _invenback;
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();



	void render(HDC hdc);																			//화면상 보이는 그냥 랜더
	void invenrender(HDC hdc);																//E번을 눌렀을 때 보이는 랜더
	void itemrender(HDC hdc);																//아이템 랜더
	void secitemrender(HDC hdc);															//두번째 아이템 랜더
	void feelrender(HDC hdc);																	//호감
	void maprender(HDC hdc);																	//지도
	
	bool getOpen() { return isuse; }
	void setOpen(bool _iseuse) { isuse = _iseuse; }
};


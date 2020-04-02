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


	RECT _temp;
	vector<taginventroy> _vTemp;																	//담을 벡터와 아이템보여주기(임시 벡터)
	
	taginventroy _invenback;


	bool istouch;
	
	POINT invenmouse;

	POINT start;
	POINT end;

	bool iseat;																//먹었는 지 판단할 수 있는 bool 값
	bool iseatwindow;												//마지막 창
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();
	void inventoryItem();																				//인벤토리 요소 안에 상태를 알리기 위한 함수
	void itemmove();																						//아이템 잡기
	void additem(item _item);														//아이템 추가 
	void emptyitem();
	void createseed();																				//씨앗 사용하는 함수
	void askeatwindow(HDC hdc);
	void render(HDC hdc);																			//화면상 보이는 그냥 랜더
	void invenrender(HDC hdc);																//E번을 눌렀을 때 보이는 랜더
	void itemrender(HDC hdc);																//아이템 랜더
	void secitemrender(HDC hdc);															//두번째 아이템 랜더
	bool getOpen() { return isuse; }
	void setOpen(bool _iseuse) { isuse = _iseuse; }

	void setTest(bool test) { istouch = test; }

	bool geteat() { return iseat; }
	void seteat(bool _iseat) { iseat = _iseat; }

	bool geteatopen() { return iseatwindow; }
	void seteatopen(bool _iseatwindow) { iseatwindow = _iseatwindow; }
	
};


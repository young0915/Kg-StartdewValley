#pragma once
#include "item.h"
#include "singletonBase.h"

class itemManager :public item , public singletonBase<itemManager>
{
private:
	item _item;																			//아이템을 초기화할 변수
	
	vector<item> _vItem;															//아이템을 담을 벡터
	vector<item>::iterator _viItem;

public :
	itemManager();
	~itemManager();
	
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void inrender(HDC hdc, int destX, int destY);

	//void test(const char * name, itemType type, int price, int shareprice, int hp, int energy, int maxCnt);
	//void pushitem(const char* name, )
	item additem(string itemName);																					//이름으로 아이템을 찾아서 보내주는 함수
	item additem(string itemName, int CntNum);															//이름으로 아이템을 찾아서  보낸주는 함수, 숫자로 수도 세팅 가능
	vector<item> getItemList() { return _vItem; }																//아이템 벡터 자체를 보내주는 함수

};


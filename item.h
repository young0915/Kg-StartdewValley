#pragma once

enum  itemType
{
	ITEM_EMPTY,
	ITEM_SWORD,				
	ITEM_ETC									//기타
};

struct itemInfo
{
	image* _img;							//이미지
	string itemName;						//이름
	itemType _type;							//아이템의 종류
	RECT rc;										//랙트

	bool move;							//바닥에 떨어진 아이템인지 아닌지
	int _x, _y;

	int _Price;									//원가
	int _sharePrice;						//플레이어가 정한 가격 
	int _energy;								//에너지
	int _hp;										//체력
	
	int _cnt;									//갯수
	int _maxCnt;							//인벤토리 1칸 당 쵣재소지 갯수
};
class item 
{
private:
	itemInfo _item;

public:
	item();
	~item();

	HRESULT init(const char* name, itemType type, int price, int shareprice, int hp,int energy, int maxCnt);							//아이템 초기화
	void release();
	void update();
	void render();
	void render(HDC hdc);
	void inrender(HDC hdc, int x, int y);

	void magenet(POINT _playerPoint);																			//아이템 이 플레이어에게 끌어당기도록 하기
	bool maxitem();


	itemInfo getItemInfo() { return _item; }																		//아이템 정보를 가져옴
	RECT getRect() { return  _item.rc; }																				//아이템 랙트 가져옴

	void setItem() { _item._cnt++; }																						//갯수를 num만큼 증가
	void setItemCnt(int num) { _item._cnt += num; }														//갯수를 num으로 만듬
	void setItemCnt_equal(int num) { _item._cnt = num; }

	//랙트의 위치 설정
	void setRect(int x, int y) { _item.rc = RectMakeCenter(_item._x, _item._y, _item._img->getWidth(), _item._img->getHeight()); }
	void setRect(RECT _rc) { _item.rc = _rc; }

	//아이템 상태를 바꾸줌인벤에 있을 때 false, 바닥에 떨어져 있을 때 true
	void setMove(bool _move) { _item.move = _move; }


	//플레이어가 아이템 가격을 정할 때 쓰는 함수 
	void setPlayerPrice(int price) { _item._Price = price; }





};

/*
아이템 매니저
흑요소(검)
물뿌리개
잡초
돌
나무
다이아몬드
박쥐 아이템
감자

상점
파스닙 씨앗
콩종자
콜리플라워 씨앗
감자 씨앗

*/
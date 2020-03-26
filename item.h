#pragma once

enum  itemType
{
	ITEM_EMPTY,
	ITEM_SWORD,				
	ITEM_ETC									//��Ÿ
};

struct itemInfo
{
	image* _img;							//�̹���
	string itemName;						//�̸�
	itemType _type;							//�������� ����
	RECT rc;										//��Ʈ

	bool move;							//�ٴڿ� ������ ���������� �ƴ���
	int _x, _y;

	int _Price;									//����
	int _sharePrice;						//�÷��̾ ���� ���� 
	int _energy;								//������
	int _hp;										//ü��
	
	int _cnt;									//����
	int _maxCnt;							//�κ��丮 1ĭ �� �C����� ����
};
class item 
{
private:
	itemInfo _item;

public:
	item();
	~item();

	HRESULT init(const char* name, itemType type, int price, int shareprice, int hp,int energy, int maxCnt);							//������ �ʱ�ȭ
	void release();
	void update();
	void render();
	void render(HDC hdc);
	void inrender(HDC hdc, int x, int y);

	void magenet(POINT _playerPoint);																			//������ �� �÷��̾�� �����⵵�� �ϱ�
	bool maxitem();


	itemInfo getItemInfo() { return _item; }																		//������ ������ ������
	RECT getRect() { return  _item.rc; }																				//������ ��Ʈ ������

	void setItem() { _item._cnt++; }																						//������ num��ŭ ����
	void setItemCnt(int num) { _item._cnt += num; }														//������ num���� ����
	void setItemCnt_equal(int num) { _item._cnt = num; }

	//��Ʈ�� ��ġ ����
	void setRect(int x, int y) { _item.rc = RectMakeCenter(_item._x, _item._y, _item._img->getWidth(), _item._img->getHeight()); }
	void setRect(RECT _rc) { _item.rc = _rc; }

	//������ ���¸� �ٲ����κ��� ���� �� false, �ٴڿ� ������ ���� �� true
	void setMove(bool _move) { _item.move = _move; }


	//�÷��̾ ������ ������ ���� �� ���� �Լ� 
	void setPlayerPrice(int price) { _item._Price = price; }





};

/*
������ �Ŵ���
����(��)
���Ѹ���
����
��
����
���̾Ƹ��
���� ������
����

����
�Ľ��� ����
������
�ݸ��ö�� ����
���� ����

*/
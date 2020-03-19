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
	itemType type;							//�������� ����
	RECT rc;										//��Ʈ

	bool move;							//�ٴڿ� ������ ���������� �ƴ���
	int x, y;

	int Price;									//����
	int sharePrice;						//�÷��̾ ���� ���� 
	int energy;								//������
	int hp;										//ü��
	
	int cnt;									//����
	int maxCnt;							//�κ��丮 1ĭ �� �C����� ����
};
class item
{
private:
	itemInfo _item;

public :
	item();
	~item();

	HRESULT init(const char* name, itemType type, int price, int sharePrice, int energy, int hp, int cnt,int maxCnt);
	void release();
	void update();
	void render(HDC hdc);

	void magenet(POINT playerPoint);
	bool maxitem();

	itemInfo getItemInfo() { return _item; }									//������ ������ ������
	RECT getRect() { return _item.rc;  }											//������ ��Ʈ�� ������
				
	void setItemCnt() { _item.cnt++;}												//���� 1���� 
	void setItemCnt(int num) { _item.cnt += num; }						//������ num��ŭ ����
	void setItemCnt_equal(int num) { _item.cnt = num;  }			//������ num���� ����

	//��Ʈ�� ��ġ�� ���� 
	void setRect(int x, int y) { _item.rc = RectMakeCenter(x, y, _item._img->getWidth(), _item._img->getHeight()); }
	void setRect(RECT rc) { _item.rc = rc; }

	//�������� ���¸� �ٲ���(�κ��� ������ false, �ٴڿ� ������������ true)
	void setMove(bool move) { _item.move = move; }

	//�÷��̾ ������ ������ ���� �� ���� �Լ� 
	void setPlayerPrice(int price) { _item.sharePrice = price; }
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
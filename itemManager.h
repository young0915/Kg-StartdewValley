#pragma once
#include "item.h"
#include "singletonBase.h"

class itemManager :public item , public singletonBase<itemManager>
{
private:
	item _item;																			//�������� �ʱ�ȭ�� ����
	
	vector<item> _vItem;															//�������� ���� ����
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
	item additem(string itemName);																					//�̸����� �������� ã�Ƽ� �����ִ� �Լ�
	item additem(string itemName, int CntNum);															//�̸����� �������� ã�Ƽ�  �����ִ� �Լ�, ���ڷ� ���� ���� ����
	vector<item> getItemList() { return _vItem; }																//������ ���� ��ü�� �����ִ� �Լ�

};


#pragma once
#include "item.h"
#include "gameNode.h"
//�κ��丮 ��� �� �� 
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
	image* _bk;																										//�޹�� 
	taginvenimg _invenmain;																				//�κ�
	taginventroy _invenelement;																			//�κ��丮 ĭ

	bool isuse;																											//E���� ������ �ȴ��ȳ�
	vector<taginventroy>_vinven;
	vector<taginventroy>::iterator _vIinven;


	RECT _temp;
	vector<taginventroy> _vTemp;																	//���� ���Ϳ� �����ۺ����ֱ�(�ӽ� ����)
	
	taginventroy _invenback;


	bool istouch;
	
	POINT invenmouse;

	POINT start;
	POINT end;

	bool iseat;																//�Ծ��� �� �Ǵ��� �� �ִ� bool ��
	bool iseatwindow;												//������ â
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();
	void inventoryItem();																				//�κ��丮 ��� �ȿ� ���¸� �˸��� ���� �Լ�
	void itemmove();																						//������ ���
	void additem(item _item);														//������ �߰� 
	void emptyitem();
	void createseed();																				//���� ����ϴ� �Լ�
	void askeatwindow(HDC hdc);
	void render(HDC hdc);																			//ȭ��� ���̴� �׳� ����
	void invenrender(HDC hdc);																//E���� ������ �� ���̴� ����
	void itemrender(HDC hdc);																//������ ����
	void secitemrender(HDC hdc);															//�ι�° ������ ����
	bool getOpen() { return isuse; }
	void setOpen(bool _iseuse) { isuse = _iseuse; }

	void setTest(bool test) { istouch = test; }

	bool geteat() { return iseat; }
	void seteat(bool _iseat) { iseat = _iseat; }

	bool geteatopen() { return iseatwindow; }
	void seteatopen(bool _iseatwindow) { iseatwindow = _iseatwindow; }
	
};


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

	taginventroy _invenback;
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();



	void render(HDC hdc);																			//ȭ��� ���̴� �׳� ����
	void invenrender(HDC hdc);																//E���� ������ �� ���̴� ����
	void itemrender(HDC hdc);																//������ ����
	void secitemrender(HDC hdc);															//�ι�° ������ ����
	void feelrender(HDC hdc);																	//ȣ��
	void maprender(HDC hdc);																	//����
	
	bool getOpen() { return isuse; }
	void setOpen(bool _iseuse) { isuse = _iseuse; }
};


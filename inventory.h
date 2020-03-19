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
	image* _bk;																										//�޹�� 
	taginvenimg _invenmain;																				//�κ�

	vector<taginventroy>_vinven;
	vector<taginventroy>::iterator _vIinven;

	taginventroy _invenback;
public :
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();
	void render();																		//ȭ��� ���̴� �׳� ����
	void invenrender();																//E���� ������ �� ���̴� ����
	void itemrender();																//������ ����
	
};


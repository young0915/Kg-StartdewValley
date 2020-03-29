#pragma once
#include "gameNode.h"
#include "justground.h" 
#include "hoeground.h"
#include "watercanground.h"
#include "item.h"
class groundManager :public gameNode
{
private :
	typedef vector<ground*> vground;
	typedef vector<ground*>::iterator viteground;
	
private :
	vground _vground;
	viteground _viterground;
	item _item;
	image* _img;										//������ �� 
	int atkcount = 0;									//���� ��Ʈ
public :
	groundManager();
	~groundManager();

	HRESULT init();										//MYLAND2�� ���� �� 
	void update(vector<item> &itme);
	void release();
	void render();
	void removetile(int num);					//Ÿ���� �����ִ� �Լ�


	void setjustground();
	void sethoeground();
	void setwetground();

	void collision();
};


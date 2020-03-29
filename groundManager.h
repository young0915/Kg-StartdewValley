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
	image* _img;										//아이템 용 
	int atkcount = 0;									//공격 힛트
public :
	groundManager();
	~groundManager();

	HRESULT init();										//MYLAND2에 넣을 것 
	void update(vector<item> &itme);
	void release();
	void render();
	void removetile(int num);					//타일을 지워주는 함수


	void setjustground();
	void sethoeground();
	void setwetground();

	void collision();
};


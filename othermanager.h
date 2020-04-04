#pragma once
#include "gameNode.h"
#include "stone.h"
#include "itemstone.h"
#include "ruby.h"
#include "grass.h"
#include "tree.h"
#include "item.h"
#include "effect.h"

class othermanager :public gameNode 
{
private:
	typedef vector<stone*> vstone;
	typedef vector<stone*>::iterator viterstone;
	
private:
	vstone _vstone;
	viterstone _viterstone;
	image* itemimg;									//떨어진 아이템 이미지
	item _dropitem;									//떨어진 아이템 
	int atkcount=0;											//맞은 카운트
	int test =0;										//잠시 테스트용
	int time;

	effect* grassdrop;
	effect* rockdrop;

public :
	othermanager();
	~othermanager();

	HRESULT init();
	HRESULT init1();
	void release();
	void update(vector<item>& item);
	void render();

	void removestone(int num);						//제거
	void setStone();											//돌
	void setruby();												//루비
	void collisionstone();									//충돌 


	vstone getvstone() { return _vstone; }
};

/*
돌, 돌(동굴), 나무, 잔디가 있는 곳
*/
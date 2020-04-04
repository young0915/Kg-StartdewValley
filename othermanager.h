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
	image* itemimg;									//������ ������ �̹���
	item _dropitem;									//������ ������ 
	int atkcount=0;											//���� ī��Ʈ
	int test =0;										//��� �׽�Ʈ��
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

	void removestone(int num);						//����
	void setStone();											//��
	void setruby();												//���
	void collisionstone();									//�浹 


	vstone getvstone() { return _vstone; }
};

/*
��, ��(����), ����, �ܵ� �ִ� ��
*/
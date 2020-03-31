#pragma once
#include "gameNode.h" 
#include "crab.h"
class Monstermanager :public gameNode
{
private :
	typedef vector<monster*> _monster;
	typedef vector<monster*>::iterator _itermonster;

private:
	_monster _vmonster;
	_itermonster _vitermonser;
	item _dropitem;
	image* _itemimg;
	int  atkcount=0;
	int test;
public :
	Monstermanager();
	~Monstermanager();

	HRESULT init();
	void release();
	void update(vector<item> _item);
	void render();
	void acessmonster();										//접근 몬스터
	void attackmonster();

	void monsterremove(int num);
	void monstercollisionwall();
	void setcrab();

	_monster getvMonser() { return _vmonster; }

};


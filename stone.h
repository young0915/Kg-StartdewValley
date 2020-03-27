#pragma once
#include "gameNode.h"

enum STONE_TYPE
{
	ETC_STONE,
	RUBY_STONE,
	GRASS_TYPE,
	TREE_TYPE
};

enum STONE_STATE
{
	STONE_IDLE,															//가만히 있는	상태
	STONE_MASH														//으깬 상태
};

class stone :public gameNode
{
private:
	STONE_STATE _sstate;
	STONE_TYPE _tone;
	image* _img;
	RECT _rc;
	item _item;
	int _atk;
	int _currentX, _currentY;
	int hitcount;

public :
	stone();
	~stone();

	HRESULT init();
						//이미지 								위치 x, y     플레이어 힘을 닳게 하는 공격력
	HRESULT init(const char* imagename, STONE_TYPE tone, STONE_STATE sstate, POINT position, int atk);
	void release();
	void update();
	void render();


	STONE_STATE getstate() { return _sstate; }
	STONE_TYPE gettype() {return _tone;}

	void setstate(STONE_STATE state) { _sstate = state; }			// 죽은 상태


	int getCurrentX() { return _currentX; }
	int getCurrentY() { return _currentY; }


	RECT getstonerc() { return _rc; }
	item getitem() { return _item; }
}; 


//돌이랑 루비 곤리한는 곳 

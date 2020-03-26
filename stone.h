#pragma once
#include "gameNode.h"
class stone :public gameNode
{
private:
	image* _img;
	RECT _rc;

	int _atk;

public :
	stone();
	~stone();
						//이미지 								위치 x, y     플레이어 힘을 닳게 하는 공격력
	HRESULT init(const char* imagename, POINT position, int atk);
	void release();
	void update();
	void render();

	RECT getstonerc() { return _rc; }
};


//돌이랑 루비 곤리한는 곳 

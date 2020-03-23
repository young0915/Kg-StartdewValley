#pragma once
#include "gameNode.h"
struct timerbar
{
	image* _img;
	float _angle;
	int test;									//예시로 한 것 
};

class clock :public gameNode
{
private:
	timerbar _timebar;

public :
	clock();
	~clock();

	HRESULT init();
	void release();
	void update();
	void render();
	void clockmove();
};


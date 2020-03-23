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
	int hour;												//시계
	int hourtest;										//시간을 움직이기 위한 TIMEMANAGER 값
	int min;
	int mintest;									//분을 움직이기 위한 TIMEMABAGER값
public:
	clock();
	~clock();

	HRESULT init();
	void release();
	void update();
	void render();
	void timemove();
	void clockmove();


	//야외에 있을 경우 색이 바꾸도록 할 것 
	int gethour() { return hour; }
	void sethour(int _hour) { _hour = hour; }
};


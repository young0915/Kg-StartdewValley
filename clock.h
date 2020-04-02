#pragma once
#include "gameNode.h"


struct timerbar
{

	image* _img;
	float _angle;
	int test;									//예시로 한 것 
};

enum NIGHTCHANGE
{
	NIGHRT_ONE,
	NIGHRT_TWO,
	NIGHRT_THREE,
	NIGHRT_FOUR,
	NIGHT_NO
};

enum ONEDAY
{
	MONDAY,
	TUESDAY,
	WENSDAY
};

class clock :public gameNode
{
private:
	image* _night;
	timerbar _timebar;
	NIGHTCHANGE _nightchange;
	ONEDAY _oneday;
	int hour;												//시계
	int hourtest;										//시간을 움직이기 위한 TIMEMANAGER 값
	int min;
	int mintest;									//분을 움직이기 위한 TIMEMABAGER값

	bool isturnon;							//실내인지 야외인지

public:
	clock();
	~clock();

	HRESULT init();
	void release();
	void update();
	void render();
	void timemove();
	void clockmove();

	void textrenderone();


	void moningnightchange();


	//야외에 있을 경우 색이 바꾸도록 할 것 
	int gethour() { return hour; }
	void sethour(int _hour) { _hour = hour; }

	bool getisturn() { return isturnon; }
	void setisturn(bool _isturn) { isturnon = _isturn; }

	ONEDAY getDay() { return _oneday; }
	void setDay(ONEDAY oneday) { _oneday = oneday; }
};


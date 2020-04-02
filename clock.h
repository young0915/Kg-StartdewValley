#pragma once
#include "gameNode.h"


struct timerbar
{

	image* _img;
	float _angle;
	int test;									//���÷� �� �� 
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
	int hour;												//�ð�
	int hourtest;										//�ð��� �����̱� ���� TIMEMANAGER ��
	int min;
	int mintest;									//���� �����̱� ���� TIMEMABAGER��

	bool isturnon;							//�ǳ����� �߿�����

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


	//�߿ܿ� ���� ��� ���� �ٲٵ��� �� �� 
	int gethour() { return hour; }
	void sethour(int _hour) { _hour = hour; }

	bool getisturn() { return isturnon; }
	void setisturn(bool _isturn) { isturnon = _isturn; }

	ONEDAY getDay() { return _oneday; }
	void setDay(ONEDAY oneday) { _oneday = oneday; }
};


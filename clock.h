#pragma once
#include "gameNode.h"
struct timerbar
{
	image* _img;
	float _angle;
	int test;									//���÷� �� �� 
};

class clock :public gameNode
{
private:
	timerbar _timebar;
	int hour;												//�ð�
	int hourtest;										//�ð��� �����̱� ���� TIMEMANAGER ��
	int min;
	int mintest;									//���� �����̱� ���� TIMEMABAGER��
public:
	clock();
	~clock();

	HRESULT init();
	void release();
	void update();
	void render();
	void timemove();
	void clockmove();


	//�߿ܿ� ���� ��� ���� �ٲٵ��� �� �� 
	int gethour() { return hour; }
	void sethour(int _hour) { _hour = hour; }
};


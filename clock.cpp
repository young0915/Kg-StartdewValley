#include "stdafx.h"
#include "clock.h"

clock::clock()
{
}

clock::~clock()
{
}

HRESULT clock::init()
{
	IMAGEMANAGER->findImage("�ð�");
	_timebar._img = new image;
	_timebar._img->rotateinit("images/UI/Ui_timebar.bmp", 7*2, 19*1.5, true, RGB(255, 0, 255));
	_timebar.test = 0;						//�׽�Ʈ��
	hour =11;
	hourtest = TIMEMANAGER->getWorldTime();

	min = 10;
	mintest = TIMEMANAGER->getWorldTime();


	return S_OK;
}

void clock::release()
{
}

void clock::update()
{
	clockmove();
	timemove();
}

void clock::render()
{
	IMAGEMANAGER->render("�ð�", CAMERA->getCameraDC(), WINSIZEX-210 , 20);
	_timebar._img->rotateRender(CAMERA->getCameraDC(), WINSIZEX - 142, 78, _timebar._angle);
	_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 20, 0);

	char str[128];
	sprintf_s(str, "%d", min);
	TextOut(CAMERA->getCameraDC(), 800,105, str, strlen(str));

	char middlestr[128];
	sprintf_s(middlestr, ":", middlestr);
	TextOut(CAMERA->getCameraDC(), 830, 105, middlestr, strlen(middlestr));

	char hourstr[128];
	sprintf_s(hourstr, "%d", hour);
	TextOut(CAMERA->getCameraDC(), 850, 105, hourstr, strlen(hourstr));

}

void clock::timemove()
{
	mintest += 1;
	if (mintest == 300)
	{
		min += 10;
		if (min == 60)
		{
			min = 10;
			hour += 1;
			if (hour == 13)
			{
				hour = 1;
			}
		}
		mintest = 0;
	}
	clockmove();
}

void clock::clockmove()
{
	if (hour ==11)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 150, 0);
	}
	if (hour==1)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY/2, 300, 0);
	}
	if (hour ==3)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 450, 0);
	}
	if (hour ==5)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 600, 0);
	}

	if (hour ==7)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 750, 0);
	}
	if (hour ==9)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 900, 0);
	}
	if (hour ==10)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 1050, 0);
	}
	
}

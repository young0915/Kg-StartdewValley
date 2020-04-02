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
	IMAGEMANAGER->findImage("시계");
	_timebar._img = new image;
	_timebar._img->rotateinit("images/UI/Ui_timebar.bmp", 7*2, 19*1.5, true, RGB(255, 0, 255));
	_timebar.test = 0;						//테스트용
	hour =11;
	hourtest = TIMEMANAGER->getWorldTime();

	min = 10;
	mintest = TIMEMANAGER->getWorldTime();
	isturnon = false;
	
		_night = new image;
		_night->init("images/UI/낮과밤.bmp", 2000, 1700, true, RGB(255, 0, 255));
		_oneday = MONDAY;
		return S_OK;
}

void clock::release()
{
	SAFE_DELETE(_night);
}

void clock::update()
{
	clockmove();
	timemove();
}

void clock::render()
{
	IMAGEMANAGER->render("시계", CAMERA->getCameraDC(), WINSIZEX-210 , 20);
	_timebar._img->rotateRender(CAMERA->getCameraDC(), WINSIZEX - 142, 78, _timebar._angle);
	_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 20, 0);

	char str[128];
	sprintf_s(str, "%d", min);
	FontTextOut(CAMERA->getCameraDC(), 850, 105, str, 20, "경기천년제목L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 830, 105, ":", 20, "경기천년제목L Light", RGB(41, 41, 41));

	char hourstr[128];
	sprintf_s(hourstr, "%d", hour);
	FontTextOut(CAMERA->getCameraDC(), 800, 105, hourstr, 20, "경기천년제목L Light", RGB(41, 41, 41));
	
	char money[128];
	sprintf_s(money, "%d", PLAYER->getplayermoney());
	FontTextOut(CAMERA->getCameraDC(), 831, 160, money, 20, "경기천년제목L Light", RGB(41, 41, 41));

	if(isturnon)moningnightchange();
	//임시로 넣음
	textrenderone();
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
		_nightchange = NIGHRT_ONE;
	}
	if (hour ==5)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 600, 0);
	}

	if (hour ==7)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 750, 0);
	_nightchange = NIGHRT_ONE;
	}
	if (hour ==9)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 900, 0);
		_nightchange = NIGHRT_THREE;
	}
	if (hour ==10)
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 1050, 0);
	_nightchange = NIGHRT_FOUR;
	}
}

void clock::textrenderone()
{
	//FontTextOut(CAMERA->getCameraDC(), 805, 35, "월요일", 20, "경기천년제목L Light", RGB(41, 41, 41));

	switch (_oneday)
	{
	case MONDAY:
		FontTextOut(CAMERA->getCameraDC(), 805, 35, "월요일", 20, "경기천년제목L Light", RGB(41, 41, 41));
		break;
	case TUESDAY:
		FontTextOut(CAMERA->getCameraDC(), 805, 35, "화요일", 20, "경기천년제목L Light", RGB(41, 41, 41));
		break;
	case WENSDAY:
		FontTextOut(CAMERA->getCameraDC(), 805, 35, "수요일", 20, "경기천년제목L Light", RGB(41, 41, 41));
		break;
	}
}

void clock::moningnightchange()
{
		switch (_nightchange)
		{
		case NIGHRT_ONE:
			_night->alphaRender(getMemDC(), 0, 0, 50);
				break;
		case NIGHRT_TWO:
			_night->alphaRender(getMemDC(), 0, 0, 70);
			break;
		case NIGHRT_THREE:
			_night->alphaRender(getMemDC(), 0, 0, 90);
			break;
		case NIGHRT_FOUR:
			_night->alphaRender(getMemDC(), 0, 0,110 );
			break;
		}
}

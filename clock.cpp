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


	return S_OK;
}

void clock::release()
{
}

void clock::update()
{
	clockmove();
}

void clock::render()
{
	IMAGEMANAGER->render("시계", CAMERA->getCameraDC(), WINSIZEX-210 , 20);
	_timebar._img->rotateRender(CAMERA->getCameraDC(), WINSIZEX - 142, 78, _timebar._angle);
	_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 20, 0);
}

void clock::clockmove()
{
	if (KEYMANAGER->isStayKeyDown('1'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY/2, 300, 0);
	}
	if (KEYMANAGER->isStayKeyDown('2'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 450, 0);
	}
	if (KEYMANAGER->isStayKeyDown('3'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 600, 0);
	}

	if (KEYMANAGER->isStayKeyDown('4'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 750, 0);
	}
	if (KEYMANAGER->isStayKeyDown('5'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 900, 0);
	}
	if (KEYMANAGER->isStayKeyDown('6'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 1050, 0);
	}
	if (KEYMANAGER->isStayKeyDown('7'))
	{
		_timebar._angle = getAngle(WINSIZEX / 2, WINSIZEY / 2, 1200, 0);
	}

}

#include "stdafx.h"
#include "Sebastian.h"

Sebastian::Sebastian()
{
}

Sebastian::~Sebastian()
{
}

HRESULT Sebastian::init()
{
	_sebi._img = IMAGEMANAGER->findImage("세바스찬");
	ANIMATIONMANAGER->addAnimation("담배", "세바스찬", 0, 7, 10, false, true);
	//시작 애니메이션 설정
	_sebi._ani = ANIMATIONMANAGER->findAnimation("담배");
	ANIMATIONMANAGER->resume("담배");
	return S_OK;
}

void Sebastian::update()
{
}

void Sebastian::release()
{
}

void Sebastian::render()
{
	_sebi._img->aniRender(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, _sebi._ani);
}

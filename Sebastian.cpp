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

	_sebi.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _sebi._img->getFrameWidth(), _sebi._img->getFrameHeight());
	_sebi._ischeck = false;
	IMAGEMANAGER->findImage("세바스찬대화창");
	return S_OK;
}
void Sebastian::release(){}
void Sebastian::update()
{
	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&_sebi.rc, CURSOR->getPoint()))
	//	{
			//_sebi._ischeck = true;
			if (_sebi._ischeck)
			{
				_sebi._ischeck = false;
			}
			else
			{
				_sebi._ischeck = true;
			}
	//	}
	//}

}

void Sebastian::render()
{
	_sebi._img->aniRender(getMemDC(), _sebi.rc.left, _sebi.rc.top, _sebi._ani);
	if (_sebi._ischeck)dialogrender();
}


void Sebastian::dialogrender()
{
	IMAGEMANAGER->render("세바스찬대화창", CAMERA->getCameraDC(), 50, WINSIZEY/2+50);
	FontTextOut(CAMERA->getCameraDC(), 650, WINSIZEY / 2 + 280, "세바스찬", 20, "경기천년제목L Light", RGB(41, 41, 41));

	FontTextOut(CAMERA->getCameraDC(), 100, WINSIZEY / 2 + 100, "이 마을에 내 친구는 너랑 쌤뿐이야", 20, "경기천년제목L Light", RGB(41, 41, 41));

}

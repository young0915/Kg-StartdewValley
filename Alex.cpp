#include "stdafx.h"
#include "Alex.h"

Alex::Alex()
{
}

Alex::~Alex()
{
}

HRESULT Alex::init()
{
	IMAGEMANAGER->findImage("알렉스대화창");
	_alex._img = IMAGEMANAGER->findImage("알렉스");
	ANIMATIONMANAGER->addAnimation("몸짱", "알렉스", 0, 3, 10, false, true);
	//시작 애니메이션 설정
	_alex._ani = ANIMATIONMANAGER->findAnimation("몸짱");
	ANIMATIONMANAGER->resume("몸짱");
	_alex.rc = RectMakeCenter(1200, 1200, _alex._img->getFrameWidth(), _alex._img->getFrameHeight());
	_alex.ischeck = false;
	return S_OK;
}

void Alex::release()
{
}

void Alex::update()
{

			if (_alex.ischeck)
			{
				_alex.ischeck = false;
			}
			else
			{
				_alex.ischeck = true;
			}

}

void Alex::render()
{
	_alex._img->aniRender(getMemDC(), 1200, 1200, _alex._ani);
	if (_alex.ischeck) dialogrender();
}

void Alex::dialogrender()
{
	IMAGEMANAGER->render("알렉스대화창", CAMERA->getCameraDC(), 50, WINSIZEY / 2 + 50);
	FontTextOut(CAMERA->getCameraDC(), 650, WINSIZEY / 2 + 280, "알렉스", 20, "경기천년제목L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 100, WINSIZEY / 2 + 100, "공 좀 던지기 좋은 날인 거 같은데, 안 그래", 20, "경기천년제목L Light", RGB(41, 41, 41));

}

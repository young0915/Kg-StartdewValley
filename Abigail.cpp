#include "stdafx.h"
#include "Abigail.h"

Abigail::Abigail()
{
}

Abigail::~Abigail()
{
}

HRESULT Abigail::init()
{
	_abigail.img = IMAGEMANAGER->findImage("아비게일");
	ANIMATIONMANAGER->addAnimation("피리", "아비게일", 0, 3, 10, false, true);
	//시작 애니메이션 설정
	_abigail.animation = ANIMATIONMANAGER->findAnimation("피리");
	ANIMATIONMANAGER->resume("피리");
	_abigail.rc = RectMakeCenter(600, 1000, _abigail.img->getFrameWidth(), _abigail.img->getFrameHeight());
	_abigail.ischeck = false;
	return S_OK;
}

void Abigail::release()
{
}

void Abigail::update()   
{

			if(_abigail.ischeck)_abigail.ischeck = false;
			else _abigail.ischeck = true;
}

void Abigail::render()
{
	_abigail.img->aniRender(getMemDC(), 600, 1000, _abigail.animation);
	if (_abigail.ischeck)dialogrender();
}

void Abigail::dialogrender()
{
	IMAGEMANAGER->render("아비게일대화창", CAMERA->getCameraDC(), 50, WINSIZEY / 2 + 50);
	FontTextOut(CAMERA->getCameraDC(), 650, WINSIZEY / 2 + 280, "아비게일", 20, "경기천년제목L Light", RGB(41, 41, 41));

	FontTextOut(CAMERA->getCameraDC(), 100, WINSIZEY / 2+100, "오, 안녕. 일 좀 쉬고 있는 거야?", 20, "경기천년제목L Light", RGB(41, 41, 41));
}

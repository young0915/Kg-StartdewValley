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

	return S_OK;
}

void Abigail::release()
{
}

void Abigail::update()
{
}

void Abigail::render()
{
	_abigail.img->aniRender(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, _abigail.animation);
}

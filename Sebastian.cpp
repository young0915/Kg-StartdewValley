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
	_sebi._img = IMAGEMANAGER->findImage("���ٽ���");
	ANIMATIONMANAGER->addAnimation("���", "���ٽ���", 0, 7, 10, false, true);
	//���� �ִϸ��̼� ����
	_sebi._ani = ANIMATIONMANAGER->findAnimation("���");
	ANIMATIONMANAGER->resume("���");
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

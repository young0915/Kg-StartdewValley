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
	_alex._img = IMAGEMANAGER->findImage("�˷���");
	ANIMATIONMANAGER->addAnimation("��¯", "�˷���", 0, 3, 10, false, true);
	//���� �ִϸ��̼� ����
	_alex._ani = ANIMATIONMANAGER->findAnimation("��¯");
	ANIMATIONMANAGER->resume("��¯");
	return S_OK;
}

void Alex::release()
{
}

void Alex::update()
{
}

void Alex::render()
{
	_alex._img->aniRender(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, _alex._ani);
}

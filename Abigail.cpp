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
	_abigail.img = IMAGEMANAGER->findImage("�ƺ����");
	ANIMATIONMANAGER->addAnimation("�Ǹ�", "�ƺ����", 0, 3, 10, false, true);
	//���� �ִϸ��̼� ����
	_abigail.animation = ANIMATIONMANAGER->findAnimation("�Ǹ�");
	ANIMATIONMANAGER->resume("�Ǹ�");

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

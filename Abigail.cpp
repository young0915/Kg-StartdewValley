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
	IMAGEMANAGER->render("�ƺ���ϴ�ȭâ", CAMERA->getCameraDC(), 50, WINSIZEY / 2 + 50);
	FontTextOut(CAMERA->getCameraDC(), 650, WINSIZEY / 2 + 280, "�ƺ����", 20, "���õ������L Light", RGB(41, 41, 41));

	FontTextOut(CAMERA->getCameraDC(), 100, WINSIZEY / 2+100, "��, �ȳ�. �� �� ���� �ִ� �ž�?", 20, "���õ������L Light", RGB(41, 41, 41));
}

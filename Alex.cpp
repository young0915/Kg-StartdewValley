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
	IMAGEMANAGER->findImage("�˷�����ȭâ");
	_alex._img = IMAGEMANAGER->findImage("�˷���");
	ANIMATIONMANAGER->addAnimation("��¯", "�˷���", 0, 3, 10, false, true);
	//���� �ִϸ��̼� ����
	_alex._ani = ANIMATIONMANAGER->findAnimation("��¯");
	ANIMATIONMANAGER->resume("��¯");
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
	IMAGEMANAGER->render("�˷�����ȭâ", CAMERA->getCameraDC(), 50, WINSIZEY / 2 + 50);
	FontTextOut(CAMERA->getCameraDC(), 650, WINSIZEY / 2 + 280, "�˷���", 20, "���õ������L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 100, WINSIZEY / 2 + 100, "�� �� ������ ���� ���� �� ������, �� �׷�", 20, "���õ������L Light", RGB(41, 41, 41));

}

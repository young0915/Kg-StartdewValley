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

	_sebi.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _sebi._img->getFrameWidth(), _sebi._img->getFrameHeight());
	_sebi._ischeck = false;
	IMAGEMANAGER->findImage("���ٽ�����ȭâ");
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
	IMAGEMANAGER->render("���ٽ�����ȭâ", CAMERA->getCameraDC(), 50, WINSIZEY/2+50);
	FontTextOut(CAMERA->getCameraDC(), 650, WINSIZEY / 2 + 280, "���ٽ���", 20, "���õ������L Light", RGB(41, 41, 41));

	FontTextOut(CAMERA->getCameraDC(), 100, WINSIZEY / 2 + 100, "�� ������ �� ģ���� �ʶ� �ܻ��̾�", 20, "���õ������L Light", RGB(41, 41, 41));

}

#include "stdafx.h"
#include "inventory.h"

inventory::inventory()
{
}

inventory::~inventory()
{
}

HRESULT inventory::init()
{
	//===========================================E��ư�� ������ �� ==================================================
	_bk = new image;
	_bk->init("images/�κ��丮/�κ��丮��.bmp", WINSIZEX / 2, WINSIZEY / 2, true, RGB(255, 0, 255));

	//=============================================================================================================
	//==============================================================================================================
	_invenback._img = IMAGEMANAGER->findImage("�κ��丮");
	_invenback.x = 100;
	_invenback.y = 650;
	_invenback.rc = RectMakeCenter(_invenback.x, _invenback.y, _invenback._img->getFrameWidth(), _invenback._img->getFrameHeight());
	//==============================================================================================================

	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
}
//ȭ��� ���̴� �׳� ����


void inventory::render()
{
	_invenback._img->render(CAMERA->getCameraDC(), _invenback.x, _invenback.y);
}
//E���� ������ �� ���̴� ����
void inventory::invenrender()
{
	_bk->alphaRender(CAMERA->getCameraDC(), 1000);
}
//������ ����
void inventory::itemrender()
{
}

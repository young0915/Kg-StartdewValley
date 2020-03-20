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
	ITEMMANAGER->init();
	//===========================================E��ư�� ������ �� ==================================================
	_bk = new image;
	_bk->init("images/�κ��丮/�κ��丮���ȭ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_invenmain.img = IMAGEMANAGER->findImage("E���丮");
	_invenmain.invenrc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _invenmain.img->getWidth(), _invenmain.img->getHeight());

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			_invenelement._img = IMAGEMANAGER->findImage("�κ�ĭ");
			if (i == 0)
			{
				_invenelement.x = 151 + j * 49;
				_invenelement.y = 693;
			}
			else
			{
				_invenelement.x = 151 + j * 49;
				_invenelement.y = 220 + i * 75;
			}
			_invenelement.rc = RectMakeCenter(_invenelement.x, _invenelement.y, _invenelement._img->getWidth(), _invenelement._img->getHeight());
			_invenelement._item = ITEMMANAGER->additem("�������");
			_invenelement._item.setRect(_invenelement.rc);
			_vinven.push_back(_invenelement);
		}
	}
	_vinven[0]._item = ITEMMANAGER->additem("����");


	//=============================================================================================================
	//==============================================================================================================
	_invenback._img = IMAGEMANAGER->findImage("�κ��丮");
	_invenback.x = 120;
	_invenback.y = 650;
	_invenback.rc = RectMakeCenter(_invenback.x, _invenback.y, _invenback._img->getFrameWidth(), _invenback._img->getFrameHeight());
	//==============================================================================================================


//	isuse = false;
	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	
}
//ȭ��� ���̴� �׳� ����
void inventory::render(HDC hdc)
{
	_invenback._img->render(CAMERA->getCameraDC(), _invenback.x, _invenback.y);
	if (!isuse)itemrender(hdc);
}
//E���� ������ �� ���̴� ����
void inventory::invenrender(HDC hdc)
{
	_bk->alphaRender(CAMERA->getCameraDC(), 1000);
	_invenmain.img->render(CAMERA->getCameraDC(), _invenmain.invenrc.left, _invenmain.invenrc.top);
	secitemrender(hdc);
	if(isuse) itemrender(hdc);
}
//������ ����
void inventory::itemrender(HDC hdc)
{
	for (int i = 0; i < 13; i++)
	{
		if (!isuse)
		{
				_vinven[i]._item.render(CAMERA->getCameraDC());
				_vinven[i]._img->render(CAMERA->getCameraDC(), _vinven[i].rc.left, _vinven[i].rc.top);
		}
		else
		{
			_vinven[i]._item.render(CAMERA->getCameraDC());
			_vinven[i]._img->render(CAMERA->getCameraDC(), 128+i*49, 190);
		}
	}
}

void inventory::secitemrender(HDC hdc)
{
	for (int i = 0; i < _vinven.size(); i++)
	{
	if (i >= 13)
		{
			_vinven[i]._item.render(CAMERA->getCameraDC());
			_vinven[i]._img->render(CAMERA->getCameraDC(), _vinven[i].rc.left, _vinven[i].rc.top);
		}
	}
}


void inventory::feelrender(HDC hdc)
{
}

void inventory::maprender(HDC hdc)
{
}

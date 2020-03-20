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
	//===========================================E버튼을 눌렀을 때 ==================================================
	_bk = new image;
	_bk->init("images/인벤토리/인벤토리배경화면.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_invenmain.img = IMAGEMANAGER->findImage("E벤토리");
	_invenmain.invenrc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _invenmain.img->getWidth(), _invenmain.img->getHeight());

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			_invenelement._img = IMAGEMANAGER->findImage("인벤칸");
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
			_invenelement._item = ITEMMANAGER->additem("비어있음");
			_invenelement._item.setRect(_invenelement.rc);
			_vinven.push_back(_invenelement);
		}
	}
	_vinven[0]._item = ITEMMANAGER->additem("나무");


	//=============================================================================================================
	//==============================================================================================================
	_invenback._img = IMAGEMANAGER->findImage("인벤토리");
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
//화면상 보이는 그냥 랜더
void inventory::render(HDC hdc)
{
	_invenback._img->render(CAMERA->getCameraDC(), _invenback.x, _invenback.y);
	if (!isuse)itemrender(hdc);
}
//E번을 눌렀을 때 보이는 랜더
void inventory::invenrender(HDC hdc)
{
	_bk->alphaRender(CAMERA->getCameraDC(), 1000);
	_invenmain.img->render(CAMERA->getCameraDC(), _invenmain.invenrc.left, _invenmain.invenrc.top);
	secitemrender(hdc);
	if(isuse) itemrender(hdc);
}
//아이템 랜더
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

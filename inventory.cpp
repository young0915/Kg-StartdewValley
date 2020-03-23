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
	_vinven[0]._item = ITEMMANAGER->additem("���Ѹ���(������)");
	_vinven[1]._item = ITEMMANAGER->additem("����");

	_invenelement._img = IMAGEMANAGER->findImage("��������");
	_invenelement.rc = RectMakeCenter(850, WINSIZEY / 2, _invenelement._img->getWidth(), _invenelement._img->getHeight());
	_invenelement._item = ITEMMANAGER->additem("�������");
	_invenelement._item.setRect(_invenelement.rc);
	_vinven.push_back(_invenelement);

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
	inventoryItem();
	//itemremove();
	itemmove();
}
void inventory::inventoryItem()
{
	for (int i = 0; i < 36; i++)
	{
		if (i < _vinven.size())
		{
			_vinven[i]._item.setRect(_vinven[i].rc);
		}
	}

}

void inventory::itemmove()
{
	for (int i = 0; i < _vinven.size(); i++)
	{
		if (_vinven[i]._item.getItemInfo().itemName != "�������")
		{
			if ((KEYMANAGER->isOnceKeyDown(VK_LBUTTON)))
			{
				if (PtInRect(&_vinven[i].rc, m_ptMouse))
				{
					if (_vTemp.empty())
					{
						_vTemp.push_back(_vinven[i]);
						_vTemp[0]._item.setItemCnt_equal(1);
						_vinven[i]._item.setItemCnt(-1);
					}
					if (_vTemp[0]._item.getItemInfo().itemName == _vinven[i]._item.getItemInfo().itemName &&
						(_vinven[i]._item.getItemInfo()._cnt + _vTemp[0]._item.getItemInfo()._cnt) <= _vTemp[0]._item.getItemInfo()._maxCnt)
					{
						_vTemp[0]._item.setItemCnt(1);
						_vTemp[0]._item.setItemCnt(-1);
					}
				}
			}
		}
		if (_vTemp.empty())
		{
			if (i != 36)
			{
				if (_vinven[i]._item.getItemInfo().itemName == "�������")
				{
					if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
					{
						if (PtInRect(&_vinven[i].rc, m_ptMouse))
						{
							_vinven[i]._item = _vTemp[0]._item;
							_vTemp.pop_back();
							break;
						}
					}
				}
			}
			//��������
			else
			{
				if (_vinven[i]._item.getItemInfo().itemName == "�������")
				{
					if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						if (PtInRect(&_vinven[i].rc, m_ptMouse))
						{
							_vinven[20]._item = ITEMMANAGER->additem("�������");
							_vinven.pop_back();
							break;
						}
					}
				}
			}
		}
	}
}
void inventory::itemremove()
{
	for (int i = 0; i < _vinven.size(); i++)
	{
		_vinven[i]._item.setItemCnt_equal(-1);
		_vinven[i]._item = ITEMMANAGER->additem("�������");
	}

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
	if (isuse) itemrender(hdc);
}
//������ ����
void inventory::itemrender(HDC hdc)
{
	for (int i = 0; i < 13; i++)
	{
		if (!isuse)
		{
			_vinven[i]._img->render(CAMERA->getCameraDC(), _vinven[i].rc.left, _vinven[i].rc.top);
			_vinven[i]._item.render(CAMERA->getCameraDC());
		}
		else
		{
			_vinven[i]._img->render(CAMERA->getCameraDC(), 128 + i * 49, 190);
			_vinven[i]._item.inrender(CAMERA->getCameraDC(), 128 + i * 49, 190);
		}
	}
}

void inventory::secitemrender(HDC hdc)
{
	for (int i = 0; i < _vinven.size(); i++)
	{
		if (i >= 13)
		{
			_vinven[i]._img->render(CAMERA->getCameraDC(), _vinven[i].rc.left, _vinven[i].rc.top);
			_vinven[i]._item.render(CAMERA->getCameraDC());
		}
		_vinven[36]._img->render(CAMERA->getCameraDC(), _vinven[36].rc.left, _vinven[36].rc.top);
	}

}


void inventory::feelrender(HDC hdc)
{
}

void inventory::maprender(HDC hdc)
{
}

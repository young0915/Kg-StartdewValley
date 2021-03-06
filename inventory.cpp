#include "stdafx.h"
#include "inventory.h"

inventory::inventory(){}

inventory::~inventory(){}

HRESULT inventory::init()
{
	ITEMMANAGER->init();
	isuse = false;
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
				//화면에 있는 아이템 일 경우
				if (!isuse)
				{
					_invenelement.x = 151 + j * 49;
					_invenelement.y = 693;

				}
				//E번을 눌렀을 때 
				else
				{
					_invenelement.x = 150 + i * 49;
					_invenelement.y = 220;
				}
			}
			//13번째 인벤토리 칸 부터
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
	_vinven[0]._item = ITEMMANAGER->additem("물뿌리개(아이템)");
	_vinven[1]._item = ITEMMANAGER->additem("흑요소");
	_vinven[2]._item = ITEMMANAGER->additem("도끼(아이템)");
	_vinven[3]._item = ITEMMANAGER->additem("곡괭이(아이템)");
	_vinven[4]._item = ITEMMANAGER->additem("호미(아이템)");
	//_vinven[5]._item = ITEMMANAGER->additem("게");


	_invenelement._img = IMAGEMANAGER->findImage("쓰레기통");
	_invenelement.rc = RectMakeCenter(850, WINSIZEY / 2, _invenelement._img->getWidth(), _invenelement._img->getHeight());
	_invenelement._item = ITEMMANAGER->additem("비어있음");
	_invenelement._item.setRect(_invenelement.rc);
	_vinven.push_back(_invenelement);
	IMAGEMANAGER->findImage("물어보는창");


	//==============================================================================================================
	_invenback._img = IMAGEMANAGER->findImage("인벤토리");
	_invenback.x = 120;
	_invenback.y = 650;

	_invenback.rc = RectMakeCenter(_invenback.x, _invenback.y, _invenback._img->getFrameWidth(), _invenback._img->getFrameHeight());
	//==============================================================================================================
	iseat = false;
	iseatwindow = false;
	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	gameNode::update();
	for (int i = 0; i < 13; i++)
	{
		_vinven[i].rc = RectMakeCenter(CAMERA->getCameraXY().x +  150 + i * 49, CAMERA->getCameraXY().y + 693, _vinven[i]._img->getWidth(), _vinven[i]._img->getHeight());
	}
	//인벤토리 아이템 셋팅
	inventoryItem();
	//E 번을눌렀을 때 사용하는 함수 
	if (isuse)	itemmove();

	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		if (iseatwindow)
		{
			iseat = true;
			iseatwindow = false;
		}
		else 
			iseatwindow = true;
	}
}
//인벤토리 아이템 셋팅
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
//E 번을눌렀을 때 사용하는 함수 
void inventory::itemmove()
{
	//if (!isuse)	return;
	if (isuse)
	{
		for (int i = 0; i < _vinven.size(); i++)
		{
			if (i < 13)
			{
				_vinven[i].rc = RectMakeCenter(CAMERA->getCameraXY().x + 150 + i * 49, CAMERA->getCameraXY().y + 220, _vinven[i]._img->getWidth(), _vinven[i]._img->getHeight());
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_vTemp.empty())
			{
			for (int i = 0; i < _vinven.size(); i++)
			{
				if (PtInRect(&_vinven[i].rc, CURSOR->getPoint()))
				{
					if (_vinven[i]._item.getItemInfo().itemName != "비어있음")
					{
							_vTemp.push_back(_vinven[i]);
							_vinven[i]._item = ITEMMANAGER->additem("비어있음");
							break;
						}
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			if (!_vinven.empty())
			{
				for (int i = 0; i < _vinven.size(); i++)
				{
					if (i != 39)
					{
						if (PtInRect(&_vinven[i].rc, CURSOR->getPoint()))
						{
							_vinven[i]._item = _vTemp[0]._item;
							_vTemp[0]._item = ITEMMANAGER->additem("비어있음");
						}
					}
					else
					{
						if (_vinven[i]._item.getItemInfo().itemName == "비어있음")
						{
							_vinven[39]._item = ITEMMANAGER->additem("비어있음");
							_vTemp[0]._item = ITEMMANAGER->additem("비어있음");
							break;
						}

					}
				}
			}
		}
	}
	
}

void inventory::additem(item _item)
{
	for (int i = 0; i < _vinven.size(); i++)
	{
		if (_vinven[i]._item.getItemInfo().itemName == "비어있음")
		{
			_vinven[i]._item = _item;
			break;
		}
	}

}

void inventory::emptyitem()
{
		_invenelement._item = ITEMMANAGER->additem("비어있음");
		_invenelement._item.setRect(_invenelement.rc);
		_vinven.push_back(_invenelement);
	
}
//씨앗 사용
void inventory::createseed()
{
	//화면상 보이는 거
	for (int i = 5; i < 13; i++)
	{
		//수량 체크 
		if (!iseat)
		{
			if (_vinven[i]._item.getItemInfo().itemName == "감자씨앗")
			{
				if (0 < _vinven[i]._item.getItemInfo()._cnt)
				{
					_vinven[i]._item.setItemCnt(-1);
					if (_vinven[i]._item.getItemInfo()._cnt == 0)
					{
						_vinven[i]._item = ITEMMANAGER->additem("비어있음");
					}
				}
			}
		}
		if (iseat)
		{
			if (_vinven[i]._item.getItemInfo().itemName == "감자")
			{
				if (0 < _vinven[i]._item.getItemInfo()._cnt)
				{
					PLAYER->setEnergy(PLAYER->getHp() - 50);
					PLAYER->setHp(PLAYER->getEnergy() - 50);
					_vinven[i]._item.setItemCnt(-1);
					if (_vinven[i]._item.getItemInfo()._cnt == 0)
					{
						_vinven[i]._item = ITEMMANAGER->additem("비어있음");
					}
				}
			}
			if (_vinven[i]._item.getItemInfo().itemName == "게")
			{
				if (0 < _vinven[i]._item.getItemInfo()._cnt)
				{
					PLAYER->setEnergy(PLAYER->getHp() - 30);
					PLAYER->setHp(PLAYER->getEnergy() - 30);

					_vinven[i]._item.setItemCnt(-1);
					if (_vinven[i]._item.getItemInfo()._cnt == 0)
					{
						_vinven[i]._item = ITEMMANAGER->additem("비어있음");
					}
				}
		}
		}
	}
}

void inventory::askeatwindow(HDC hdc)
{
	IMAGEMANAGER->render("물어보는창", CAMERA->getCameraDC(), 10, WINSIZEY / 2 + 100);
	FontTextOut(CAMERA->getCameraDC(), 40, WINSIZEY / 2 + 150, "아이템을 먹을까요?", 30, "경기천년제목L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 40, WINSIZEY / 2 + 200, "네", 30, "경기천년제목L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 40, WINSIZEY / 2 + 250, "아니오", 30, "경기천년제목L Light", RGB(41, 41, 41));
}

//화면상 보이는 그냥 랜더
void inventory::render(HDC hdc)
{
	_invenback._img->render(getMemDC(),CAMERA->getCameraXY().x +  _invenback.x, CAMERA->getCameraXY().y + _invenback.y);
	if (!isuse)itemrender(getMemDC());
	if (iseatwindow)askeatwindow(hdc);
}
//E번을 눌렀을 때 보이는 랜더
void inventory::invenrender(HDC hdc)
{
	_bk->alphaRender(getMemDC(), CAMERA->getCameraXY().x, CAMERA->getCameraXY().y, 500);
	_invenmain.img->render(getMemDC(),CAMERA->getCameraXY().x +  _invenmain.invenrc.left, CAMERA->getCameraXY().y +_invenmain.invenrc.top);
	secitemrender(getMemDC());
	if (isuse) itemrender(getMemDC());
	FontTextOut(CAMERA->getCameraDC(), 450, WINSIZEY / 2 + 70, "경일게임아카데미농장", 50, "나눔손글씨 펜", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), WINSIZEX / 2 +80, WINSIZEY / 2 + 130, "고복희", 40, "나눔손글씨 펜", RGB(41, 41, 41));
	char str[128];
	sprintf_s(str, "%d", PLAYER->getplayermoney());
	FontTextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 80, WINSIZEY / 2 + 180, str, 40, "나눔손글씨 펜", RGB(41, 41, 41));
}
//아이템 랜더
void inventory::itemrender(HDC hdc)
{
	for (int i = 0; i < 13; i++)
	{

		if (isuse)
		{
			_vinven[i]._img->render(getMemDC(), CAMERA->getCameraXY().x	 + 128 + i * 49, CAMERA->getCameraXY().y +  190);
			_vinven[i]._item.inrender(getMemDC(), CAMERA->getCameraXY().x +  128 + i * 49, CAMERA->getCameraXY().y + 190);
		
		}
		else
		{
			_vinven[i]._img->render(getMemDC(), _vinven[i].rc.left, _vinven[i].rc.top);
			_vinven[i]._item.render(getMemDC());
		
		}
	}
	
}

void inventory::secitemrender(HDC hdc)
{
	for (int i = 0; i < _vinven.size(); i++)
	{
		if (i >= 13)
		{
			_vinven[i]._img->render(getMemDC(), CAMERA->getCameraXY().x + _vinven[i].rc.left, CAMERA->getCameraXY().y +_vinven[i].rc.top);
			_vinven[i]._item.render(getMemDC());
		}
		_vinven[36]._img->render(getMemDC(), CAMERA->getCameraXY().x + _vinven[36].rc.left, CAMERA->getCameraXY().y +_vinven[36].rc.top);
	}
	
}



#include "stdafx.h"
#include "shopscene.h"

shopscene::shopscene()
{
}

shopscene::~shopscene()
{
}

HRESULT shopscene::init()
{
	_tilem = new tileManager;
	_tilem->shop();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//Ä«¸Þ¶ó À§Ä¡
	IMAGEMANAGER->findImage("¼¥1");
	IMAGEMANAGER->findImage("¼¥2");
	IMAGEMANAGER->findImage("¼¥3");
	IMAGEMANAGER->findImage("¼¥4");
	IMAGEMANAGER->findImage("¾ÆÀú¾¾");
	shopsell = RectMakeCenter(225, 215, 300, 300);
	//===========================================»óÁ¡================================================
	_shopmain._img = IMAGEMANAGER->findImage("»óÁ¡¾ÆÀú¾¾");
	_shopmain.x = 100;
	_shopmain.y = 200;
	_shopmain._isopen = false;
	_shopmain.rc = RectMakeCenter(_shopmain.x, _shopmain.y, _shopmain._img->getWidth(), _shopmain._img->getHeight());

	for (int i = 0; i < 4; i++)
	{
		_shop._img = IMAGEMANAGER->findImage("»óÁ¡Ä­");
		_shop.x = 500;
		_shop.y = 250 + i * 80;
		_shop._rc = RectMakeCenter(_shop.x, _shop.y, _shop._img->getWidth(), _shop._img->getHeight());
		_shop._item = ITEMMANAGER->additem("ºñ¾îÀÖÀ½");
		_shop._item.setRect(_shop._rc);
		_vshop.push_back(_shop);
	}
	_vshop[0]._item = ITEMMANAGER->additem("°¨ÀÚ¾¾¾Ñ");
	_vshop[1]._item = ITEMMANAGER->additem("ÄÝ¸®ÇÃ¶ó¿ö ¾¾¾Ñ");
	_vshop[2]._item = ITEMMANAGER->additem("ÄáÁ¾ÀÚ");
	_vshop[3]._item = ITEMMANAGER->additem("ÇÇ´Õ½º ¾¾¾Ñ");


	for (int i = 0; i < _vshop.size(); i++)
	{
		if (i < _vshop.size())
		{
			_vshop[i]._item.setRect(_vshop[i]._rc);
		}
	}
	//===============================================================================================
	_gotown = RectMakeCenter(450, 620, 100, 50);
	_gotowntwinkle = RectMakeCenter(450, 590, 200, 50);
	i = 20;
	istwinkel = false;
	_twinkle = new image;
	_twinkle->init("images/UI/³·°ú¹ã.bmp", 2000, 1700, true, RGB(255, 0, 255));
	_carpet._img = IMAGEMANAGER->findImage("Ä«ÆêÆ®");
	_carpet.x = 450;
	_carpet.y = 572;
	_carpet._rc = RectMakeCenter(_carpet.x, _carpet.y, _carpet._img->getWidth(), _carpet._img->getHeight());
	return S_OK;
}

void shopscene::rlease()
{
	SAFE_DELETE(_tilem);
}
void shopscene::update()
{
	gameNode::update();
	PLAYER->update();
	PLAYER->getclock()->setisturn(false);
	//»óÁ¡ ´­·¶À» ¶§
	RECT temp;
	if (IntersectRect(&temp, &shopsell, &PLAYER->getPlayerrect()))
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			if (!_shopmain._isopen)
			{
				_shopmain._isopen = true;
		
			}
			else
			{
				_shopmain._isopen = false;
				itemSetup();
			}
		}
	}
	RECT gotwon;
	if (IntersectRect(&gotwon, &_gotown, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("¸¶À»2");
		PLAYER->setplayerXY(1450, 520);
	}

	RECT temptwinkle;
	if (IntersectRect(&temptwinkle, &_gotowntwinkle, &PLAYER->getPlayerrect()))
	{
		istwinkel = true;
	}
	sellitem();
}

void shopscene::itemSetup()
{
	for (int i = 0; i < _vshop.size(); i++)
	{
		if (i < _vshop.size())
		{
			_vshop[i]._item.setRect(_vshop[i]._rc);
		}
	}
}

void shopscene::sellitem()
{
	if (!_shopmain._isopen) return;


	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vshop.size(); i++)
		{
			//Å¬¸¯
			if (PtInRect(&_vshop[i]._rc, CURSOR->getPoint()))
			{
				//µ· Ã¼Å©
				if (PLAYER->getplayermoney() >= _vshop[i]._item.getItemInfo()._Price)
				{
					PLAYER->setplayermoney(PLAYER ->getplayermoney() -_vshop[i]._item.getItemInfo()._Price);
					PLAYER->getinventory()->additem(_vshop[i]._item);
				}
			}
		}
	}
}


void shopscene::shoprender()
{
	//¼¥ ¸ÞÀÎ
	_shopmain._img->render(getMemDC(), _shopmain.x, _shopmain.y);

	char str[128];
	char starname[500];
	char itemstr[256];

	for (int i = 0; i < _vshop.size(); i++)
	{
		_vshop[i]._img->render(getMemDC(), _vshop[i]._rc.left, _vshop[i]._rc.top);
		_vshop[i]._item.inrender(getMemDC(),  + _vshop[i]._rc.left + 5, _vshop[i]._rc.top + 15);
	
		TCHAR str123[1024];

		sprintf_s(str123, "%s", _vshop[i]._item.getItemInfo().itemName.c_str());
		FontTextOut(getMemDC(), _vshop[i]._rc.left + 100, _vshop[i]._rc.top + 30, str123, 20, "°æ±âÃµ³âÁ¦¸ñL Light", RGB(41, 41, 41));

		sprintf_s(str, "%d", _vshop[i]._item.getItemInfo()._Price);
		FontTextOut(getMemDC(), _vshop[i]._rc.left + 300, _vshop[i]._rc.top + 30, str, 20, "°æ±âÃµ³âÁ¦¸ñL Light", RGB(41, 41, 41));

		if (KEYMANAGER->isToggleKey('5'))
		{
			Rectangle(getMemDC(), _vshop[i]._rc.left, _vshop[i]._rc.top, _vshop[i]._rc.right, _vshop[i]._rc.bottom);
			SetBkMode(getMemDC(), TRANSPARENT);
			//»ö»ó
			SetTextColor(getMemDC(), RGB(255, 0, 0));

			char str[128];
			sprintf_s(str, "%d", i);
			TextOut(getMemDC(), _vshop[i]._rc.left, _vshop[i]._rc.top, str, strlen(str));
		}
	}


}

void shopscene::render()
{
	_tilem->render();
	IMAGEMANAGER->render("¼¥1", getMemDC(), 100, 200);
	IMAGEMANAGER->render("¼¥2", getMemDC(), 450, 300);
	IMAGEMANAGER->render("¼¥4", getMemDC(), 200, 250);
	IMAGEMANAGER->render("¼¥3", getMemDC(), 100, 525);
	IMAGEMANAGER->render("¾ÆÀú¾¾", getMemDC(), 225, 215);

	_carpet._img->render(getMemDC(), _carpet.x, _carpet.y);
	PLAYER->render(getMemDC());
	PLAYER->invenrender(getMemDC());
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _gotowntwinkle.left, _gotowntwinkle.top, _gotowntwinkle.right, _gotowntwinkle.bottom);
		Rectangle(getMemDC(), shopsell.left, shopsell.top, shopsell.right, shopsell.bottom);
		Rectangle(getMemDC(), _gotown.left, _gotown.top, _gotown.right, _gotown.bottom);
	}
	if (_shopmain._isopen)shoprender();
	CURSOR->render(getMemDC());
	if (istwinkel) _twinkle->alphaRender(getMemDC(), i++);
}





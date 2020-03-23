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
	PLAYER->init();
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
	_shopmain.x = 70;
	_shopmain.y = 100;
	_shopmain._isopen = false;
	_shopmain.rc = RectMakeCenter(_shopmain.x, _shopmain.y, _shopmain._img->getWidth(), _shopmain._img->getHeight());
	//===============================================================================================
	return S_OK;
}

void shopscene::rlease()
{
	SAFE_DELETE(_tilem);
}
void shopscene::update()
{
	PLAYER->update();

	//»óÁ¡ ´­·¶À» ¶§
	RECT temp;
	if (IntersectRect(&temp, &shopsell, &PLAYER->getPlayerrect()))
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			if (!_shopmain._isopen) _shopmain._isopen = true;
			else
			{
				_shopmain._isopen = false;
				itemsell();																//¾ÆÀÌÅÛ ±¸¸ÅÇÒ °Í 
			}
		}
	}

}

void shopscene::itemsell()
{

}


void shopscene::shoprender()
{
	_shopmain._img->render(getMemDC(), _shopmain.x, _shopmain.y);
}

void shopscene::render()
{
	_tilem->render();
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("¼¥1", getMemDC(), 100, 200);
	IMAGEMANAGER->render("¼¥2", getMemDC(), 450, 300);
	IMAGEMANAGER->render("¼¥4", getMemDC(), 200, 250);
	IMAGEMANAGER->render("¼¥3", getMemDC(), 100, 525);
	IMAGEMANAGER->render("¾ÆÀú¾¾", getMemDC(), 225, 215);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), shopsell.left, shopsell.top, shopsell.right, shopsell.bottom);
	}
	if (_shopmain._isopen)shoprender();
}





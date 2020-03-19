#include "stdafx.h"
#include "item.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init(const char* name, itemType type, int price, int sharePrice, int energy, int hp, int cnt, int maxCnt)
{
	_item.itemName = name;
	_item._img = IMAGEMANAGER->findImage(name);
	_item.move = false;
	_item.Price = price;
	_item.sharePrice = sharePrice;
	_item.rc = RectMakeCenter(-50, -50, _item._img->getWidth(), _item._img->getHeight());
	_item.energy = energy;
	_item.hp = hp;
	_item.cnt = 1;
	_item.maxCnt = maxCnt;
	return S_OK;
}

void item::release()
{
}

void item::update()
{
	magenet(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));
}

void item::render(HDC hdc)
{
	if (KEYMANAGER->isOnceKeyDown('T')) Rectangle(CAMERA->getCameraDC(), _item.rc.left, _item.rc.top, _item.rc.right, _item.rc.bottom);
	_item._img->render(hdc, _item.rc.left, _item.rc.top);
}

void item::magenet(POINT playerPoint)
{
	_item.x = _item.rc.left + (_item.rc.right - _item.rc.left) / 2;
	_item.y = _item.rc.top + (_item.rc.bottom - _item.rc.top);
	if (_item.move && getDistance(_item.x, _item.y, playerPoint.x, playerPoint.y) < 50)
	{
		if (_item.x < playerPoint.x) _item.x += 2;
		if (_item.x > playerPoint.x) _item.x -= 2;
		if (_item.y < playerPoint.y)_item.y += 2;
		if (_item.y > playerPoint.y)_item.y -= 2;
	}
	_item.rc = RectMakeCenter(_item.x, _item.y, _item._img->getWidth(), _item._img->getHeight());
}

bool item::maxitem()
{
	if (_item.maxCnt <= _item.cnt)
	{
		_item.cnt = _item.maxCnt;
		return true;
	}
	else return false;

}

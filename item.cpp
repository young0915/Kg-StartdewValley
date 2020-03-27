#include "stdafx.h"
#include "item.h"


item::item()
{
}

item::~item()
{
}

HRESULT item::init(const char * name, itemType type, int price, int shareprice, int hp, int energy, int maxCnt)
{
	_item.itemName = name;
	_item._img = IMAGEMANAGER->findImage(name);
	_item._type = type;
	_item.rc = RectMakeCenter(-50, -50, _item._img->getWidth(), _item._img->getHeight());
	_item.move = false;
	_item._Price = price;
	_item._sharePrice = shareprice;
	_item._hp = hp;
	_item._energy = energy;
	_item._cnt = 1;
	_item._maxCnt = maxCnt;
	return S_OK;
}

void item::release()
{
}

void item::update()
{
	magenet(PointMake(PLAYER->getintplayerX(), PLAYER->getintplayerY()));
}

void item::render()
{
	//_item._img->render(, _item.rc.left, _item.rc.top);
}

void item::render(HDC hdc)
{
	_item._img->render(hdc, _item.rc.left, _item.rc.top);
}

void item::inrender(HDC hdc, int x, int y)
{
	_item._img->render(hdc,x, y);
}


void item::magenet(POINT _playerPoint)
{
	_item._x = _item.rc.left + (_item.rc.right - _item.rc.left) / 2;
	_item._y = _item.rc.top + (_item.rc.bottom - _item.rc.top) / 2;

	if (_item.move && getDistance(_item._x, _item._y, _playerPoint.x, _playerPoint.y) < 50)
	{
		if (_item._x < _playerPoint.x) _item._x += 2;
		if (_item._x > _playerPoint.x)_item._x -= 2;
		if (_item._y < _playerPoint.y)_item._y += 2;
		if (_item._y < _playerPoint.y) _item._y -= 2;
	}
	_item.rc = RectMakeCenter(_item._x, _item._y, _item._img->getWidth(), _item._img->getHeight());
}

bool item::maxitem()
{
	return false;
}


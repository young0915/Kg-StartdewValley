#include "stdafx.h"
#include "rat.h"
rat::rat()
{
}

rat::~rat()
{
}

HRESULT rat::init()
{
	_rat.x = WINSIZEX/2;
	_rat.y = WINSIZEY/2;
	_rat.rc = RectMakeCenter(_rat.x, _rat.y, 50/*_rat.img->getFrameWidth()*/, 50/*_rat.img->getFrameHeight()*/);
	//Ãæµ¹
	_rat.collison1 = RectMakeCenter(704, 885, 1000, 580);

	return S_OK;
}

void rat::release()
{
}

void rat::update()
{
}

void rat::render()
{

	//colorRectangle(getMemDC(), _rat.x, _rat.y+560, 50, 50, 255, 0, 0);
	//if(KEYMANAGER->isToggleKey(VK_TAB)
	AlphaRectangle(getMemDC(), _rat.collison1.left, _rat.collison1.top, _rat.collison1.right, _rat.collison1.bottom);
}

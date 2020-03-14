#include "stdafx.h"
#include "rat.h"

rat::rat()
{
}

rat::~rat()
{
}

HRESULT rat::init(int x, int y)
{
	_rat.x = x;
	_rat.y = y;
	_rat.rc = RectMakeCenter(_rat.x, _rat.y, 50/*_rat.img->getFrameWidth()*/, 50/*_rat.img->getFrameHeight()*/);
	//Ãæµ¹
	_rat.collison1 = RectMakeCenter(704, 885,1050, 650);
	
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
	//Rectangle(getMemDC(), _rat.x, _rat.y, _rat.rc.right, _rat.rc.bottom);
	//if(KEYMANAGER->isToggleKey(VK_TAB)
	AlphaRectangle(getMemDC(), _rat.collison1.left, _rat.collison1.top, _rat.collison1.right, _rat.collison1.bottom);
}

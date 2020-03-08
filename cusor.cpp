#include "stdafx.h"
#include "cusor.h"

cusor::cusor()
{
}

cusor::~cusor()
{
}

HRESULT cusor::init()
{
	_cursor.img = new image;
	_cursor.img->init("images/cursor/Ui_cursor.bmp", 128 * 2, 16 * 2, 8, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void cusor::release()
{
	SAFE_DELETE(_cursor.img);
}

void cusor::update()
{
	_cursor.rc = RectMake(m_ptMouse.x, m_ptMouse.y, 50,50);
}

void cusor::render()
{
	_cursor.img->frameRender(getMemDC(), _cursor.rc.left, _cursor.rc.top, 0,0);
}


/*
렉트와 충돌이 되었을 때
사용하기

*/
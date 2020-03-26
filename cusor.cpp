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


	_cursor.cursor.x = CAMERA->getCameraXY().x +m_ptMouse.x;
	_cursor.cursor.y = CAMERA->getCameraXY().y + m_ptMouse.y;

	return S_OK;
}

void cusor::release()
{
	//SAFE_DELETE(_cursor.img);
}

void cusor::update()
{
	_cursor.cursor.x = CAMERA->getCameraXY().x + m_ptMouse.x;
	_cursor.cursor.y = CAMERA->getCameraXY().y + m_ptMouse.y;

	_cursor.rc = RectMake(_cursor.cursor.x, _cursor.cursor.y, _cursor.img->getWidth(), _cursor.img->getHeight());
}

void cusor::render(HDC hdc)
{
	_cursor.img->frameRender(hdc, _cursor.rc.left, _cursor.rc.top, 0,0);
}


/*
렉트와 충돌이 되었을 때
사용하기

*/
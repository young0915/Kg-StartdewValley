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
	//==============================================================================================================
	_invenback._img = IMAGEMANAGER->findImage("인벤토리");
	_invenback.x = 100;
	_invenback.y = 650;
	_invenback.rc = RectMakeCenter(_invenback.x, _invenback.y, _invenback._img->getFrameWidth(), _invenback._img->getFrameHeight());
	//==============================================================================================================

	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
}

void inventory::render()
{
	_invenback._img->render(CAMERA->getCameraDC(), _invenback.x, _invenback.y);
}

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
	//===========================================E버튼을 눌렀을 때 ==================================================
	_bk = new image;
	_bk->init("images/인벤토리/인벤토리뒷.bmp", WINSIZEX / 2, WINSIZEY / 2, true, RGB(255, 0, 255));

	//=============================================================================================================
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
//화면상 보이는 그냥 랜더


void inventory::render()
{
	_invenback._img->render(CAMERA->getCameraDC(), _invenback.x, _invenback.y);
}
//E번을 눌렀을 때 보이는 랜더
void inventory::invenrender()
{
	_bk->alphaRender(CAMERA->getCameraDC(), 1000);
}
//아이템 랜더
void inventory::itemrender()
{
}

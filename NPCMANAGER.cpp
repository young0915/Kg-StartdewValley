#include "stdafx.h"
#include "NPCMANAGER.h"

NPCMANAGER::NPCMANAGER()
{
}

NPCMANAGER::~NPCMANAGER()
{
}

HRESULT NPCMANAGER::init()
{
	_abigail = new Abigail;
	_abigail->init();

	rc = RectMakeCenter(600, 1000, 200, 200);

	
	_alex = new Alex;
	_alex->init();

	_sebastian = new Sebastian;
	_sebastian->init();

	return S_OK;
}

void NPCMANAGER::update()
{


	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (PtInRect(&_alex->getalex(), CURSOR->getPoint()))
		{
			_alex->update();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_sebastian->getdsebi(), CURSOR->getPoint()))
		{
			_sebastian->update();
		}
	}

	RECT temp;
	if (IntersectRect(&temp, &rc, &PLAYER->getPlayerrect()))
	{
		if (KEYMANAGER->isOnceKeyDown('U'))
		{
			
			 _abigail->update();
		}
	}
}



void NPCMANAGER::release()
{
}

void NPCMANAGER::render()
{
	_abigail->render();
	_alex->render();
	_sebastian->render();

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
}

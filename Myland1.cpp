#include "stdafx.h"
#include "Myland1.h"

Myland1::Myland1()
{
}

Myland1::~Myland1()
{
}

HRESULT Myland1::init()
{
	////맵
	_tilem = new tileManager;
	_tilem->Mylandone();

	//플레이어
	//PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//카메라 위치

	IMAGEMANAGER->findImage("내집");
	IMAGEMANAGER->findImage("지붕");
	IMAGEMANAGER->findImage("우편");
	townrect = RectMakeCenter(1400, 400, 50, 200);
	return S_OK;
}

void Myland1::release()
{
}

void Myland1::update()
{
	PLAYER->update();

	RECT temp;
	if (IntersectRect(&temp, &townrect, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("마을1");
		PLAYER->setplayerXY(500, 300);
	}
	

}

void Myland1::render()
{
	_tilem->render();
	IMAGEMANAGER->render("우편", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("내집", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("지붕", getMemDC(), 912, 150);
	IMAGEMANAGER->render("우편", getMemDC(), 1302, 400);
	PLAYER->invenrender(getMemDC());
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), townrect.left, townrect.top, townrect.right, townrect.bottom);
	}
}

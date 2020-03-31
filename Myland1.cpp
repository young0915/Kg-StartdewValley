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
	////��
	_tilem = new tileManager;
	_tilem->Mylandone();

	//�÷��̾�
	//PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
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
		SCENEMANAGER->changeScene("����1");
		PLAYER->setplayerXY(500, 300);
	}
	

}

void Myland1::render()
{
	_tilem->render();
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("����", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("����", getMemDC(), 912, 150);
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	PLAYER->invenrender(getMemDC());
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), townrect.left, townrect.top, townrect.right, townrect.bottom);
	}
}

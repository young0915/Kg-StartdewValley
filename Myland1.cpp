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
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	//_minego = RectMakeCenter(430, 300, 80, 80);
	//_myhouse = RectMakeCenter(500, 450, 250, 250);
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	townrect = RectMakeCenter(1500, 500, 80, 80);
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
	if (KEYMANAGER->isToggleKey('Q'))
	{
		Rectangle(getMemDC(), townrect.left, townrect.top, townrect.right, townrect.bottom);
	}
}

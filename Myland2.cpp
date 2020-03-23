#include "stdafx.h"
#include "Myland2.h"

Myland2::Myland2()
{
}

Myland2::~Myland2()
{
}

HRESULT Myland2::init()
{
	//��
	_tilem = new tileManager;
	_tilem->Mylandtwo();

	//�÷��̾�
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	
	//_myhouse = RectMakeCenter(500, 450, 250, 250);
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	return S_OK;
}

void Myland2::release()
{
}

void Myland2::update()
{
	PLAYER->update();
}

void Myland2::render()
{
	_tilem->render();
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("����", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("����", getMemDC(), 912, 150);
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
}

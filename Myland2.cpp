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
	
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");

	_ground = new groundManager;
	_ground->init();

	return S_OK;
}

void Myland2::release()
{
	_ground->release();
}

void Myland2::update()
{
	PLAYER->update();
	_ground->update(_item);
}

void Myland2::render()
{
	_tilem->render();
	_ground->render();
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("����", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("����", getMemDC(), 912, 150);
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
}

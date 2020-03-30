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
	//맵
	_tilem = new tileManager;
	_tilem->Mylandtwo();

	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//카메라 위치
	
	IMAGEMANAGER->findImage("내집");
	IMAGEMANAGER->findImage("지붕");
	IMAGEMANAGER->findImage("우편");

	_ground = new groundManager;
	_ground->init();

	_vegetable = new vegetablemanager;
	_vegetable->init();

	return S_OK;
}

void Myland2::release()
{
	_ground->release();
}

void Myland2::update()
{
	PLAYER->update();
	_ground->update();
	_vegetable->update(_item);
}

void Myland2::render()
{
	_tilem->render();
	_ground->render();
	_vegetable->render();
	IMAGEMANAGER->render("우편", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("내집", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("지붕", getMemDC(), 912, 150);
	IMAGEMANAGER->render("우편", getMemDC(), 1302, 400);
}

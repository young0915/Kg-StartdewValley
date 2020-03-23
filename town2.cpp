#include "stdafx.h"
#include "town2.h"

town2::town2()
{
}

town2::~town2()
{
}

HRESULT town2::init()
{
	_tilem = new tileManager;
	_tilem->TownTwo();

	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//카메라 위치

	return S_OK;
}

void town2::release()
{
}

void town2::update()
{
	PLAYER->update();
}

void town2::render()
{
	_tilem->render();
	PLAYER->render(getMemDC());
}

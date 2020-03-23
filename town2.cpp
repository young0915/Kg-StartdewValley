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

	//�÷��̾�
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

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

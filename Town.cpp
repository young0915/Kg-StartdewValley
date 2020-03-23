#include "stdafx.h"
#include "Town.h"

Town::Town()
{
}

Town::~Town()
{
}

HRESULT Town::init()
{
	_tilem = new tileManager;
	_tilem->Town();

	//�÷��̾�
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	return S_OK;
}

void Town::release()
{
}

void Town::update()
{
	PLAYER->update();
}

void Town::render()
{
	_tilem->render();
	PLAYER->render(getMemDC());

}

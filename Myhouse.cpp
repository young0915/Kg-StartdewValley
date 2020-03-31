#include "stdafx.h"
#include "Myhouse.h"

Myhouse::Myhouse()
{
}

Myhouse::~Myhouse()
{
}

HRESULT Myhouse::init()
{
	_tilem = new tileManager;
	_tilem->Myhouse();
	//플레이어
//	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));
	return S_OK;
}

void Myhouse::release()
{
	PLAYER->release();
}

void Myhouse::update()
{
	PLAYER->update();
}

void Myhouse::render()
{
	_tilem->render();
	PLAYER->render(getMemDC());
}

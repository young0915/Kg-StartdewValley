#include "stdafx.h"
#include "Myland.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{
	//¸Ê
	_tilem = new tileManager;
	_tilem->Mylandload(100, 100);
	//ÇÃ·¹ÀÌ¾î
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);

	return S_OK;
}

void Myland::release()
{
	SAFE_DELETE(_tilem);
	PLAYER->release();
}

void Myland::update()
{
	PLAYER->update();
	_tilem->update();

}



void Myland::render()
{
	_tilem->render();
	PLAYER->render(CAMERA->getCameraDC());
}


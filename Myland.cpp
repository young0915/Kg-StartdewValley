#include "stdafx.h"
#include "Myland.h"

Myland::Myland()
{
}

Myland::~Myland()
{
}

HRESULT Myland::init()
{
	PLAYER->init();
	return S_OK;
}

void Myland::release()
{
	PLAYER->release();
}

void Myland::update()
{
	PLAYER->update();
}

void Myland::render()
{
	PLAYER->render(CAMERA->getCameraDC());
}

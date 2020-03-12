#include "stdafx.h"
#include "Myland.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{
	//맵
	_tilem = new tileManager;
	_tilem->Mylandload(100, 100);
	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));							//카메라 위치
	
	_minego = RectMakeCenter(225, 200, 50, 50);
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
	RECT rc;
	if (IntersectRect(&rc, &_minego, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("동굴");
	}
}



void Myland::render()
{
	_tilem->render();
	PLAYER->render(CAMERA->getCameraDC());
	Rectangle(getMemDC(), _minego.left, _minego.top, _minego.right, _minego.bottom);
}


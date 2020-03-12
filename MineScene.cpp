#include "stdafx.h"
#include "MineScene.h"

MineScene::MineScene()
{
}

MineScene::~MineScene()
{
}

HRESULT MineScene::init()
{
	_tilm = new tileManager;
	_tilm->Mineload();
	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilm);
	PLAYER->setPlayerPosition(_tilm->getMap()[_tilm->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));
	return S_OK;
}

void MineScene::release()
{
	SAFE_DELETE(_tilm);
	PLAYER->release();
}

void MineScene::update()
{
	PLAYER->update();
	_tilm->update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && CAMERA->getCameraCenter().x - WINSIZEX / 2 > 0)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x - 50, CAMERA->getCameraCenter().y));
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && CAMERA->getCameraCenter().x + WINSIZEX / 2 < TILESIZEX)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x + 50, CAMERA->getCameraCenter().y));
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && CAMERA->getCameraCenter().y - WINSIZEY / 2 > 0)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y - 50));
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && CAMERA->getCameraCenter().y + WINSIZEY / 2 < TILESIZEY)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y + 50));
	}


}


void MineScene::render()
{
	_tilm->render();
	PLAYER->render(/*CAMERA->getCameraDC()*/getMemDC());
}

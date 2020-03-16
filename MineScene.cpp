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
	_astar = new aStarScene;
	_astar->init(_tilm->getMap());

	//myland = RectMakeCenter()

	return S_OK;
}

void MineScene::release()
{
	SAFE_DELETE(_tilm);
	PLAYER->release();
	_astar->release();
}

void MineScene::update()
{
	PLAYER->update();
	_tilm->update();
	_astar->update(_tilm->getMap(), PLAYER->getPlayerrect());
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
	//	if(PtInRect())
	}

}


void MineScene::render()
{
	_tilm->render();
	_astar->render();
	PLAYER->render(/*CAMERA->getCameraDC()*/getMemDC());
}

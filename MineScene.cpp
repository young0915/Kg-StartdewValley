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

	myland = RectMakeCenter(925, 350 , 100, 450);

	return S_OK;
}

void MineScene::release()
{
	_astar->release();
}

void MineScene::update()
{
	PLAYER->update();
	_tilm->update();
	_astar->update(_tilm->getMap(), PLAYER->getPlayerrect());

	if (PtInRect(&myland, m_ptMouse))
		{
			SCENEMANAGER->changeScene("내땅1");
			PLAYER->setplayerXY(450, 450);
		}
}


void MineScene::render()
{
	_tilm->render();
	_astar->render();
	PLAYER->render(/*CAMERA->getCameraDC()*/getMemDC());
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), myland.left, myland.top, myland.right, myland.bottom);
	}
}

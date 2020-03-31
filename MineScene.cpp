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
	//�÷��̾�
	//PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilm);
	PLAYER->setPlayerPosition(_tilm->getMap()[_tilm->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));
	myland = RectMakeCenter(925, 350, 100, 450);


	_astar = new aStarScene;
	_astar->init(_tilm->getMap());

	_other = new othermanager;
	_other->init1();

	_monster = new Monstermanager;
	_monster->init();

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

	_other->update(_dropitem);
	_monster->update(_item);

	RECT itemtemp;
	for (int i = 0; i < _dropitem.size(); i++)
	{
		_dropitem[i].update();
		if (IntersectRect(&itemtemp, &_dropitem[i].getRect(), &PLAYER->getPlayerrect()))
		{
			PLAYER->getinventory()->additem(_dropitem[i]);
			_dropitem.erase(_dropitem.begin() + i);
			break;
		}
	}

	RECT itetemp;
	for (int i = 0; i < _item.size(); i++)
	{
		_item[i].update();
		if (IntersectRect(&itetemp, &_item[i].getRect(), &PLAYER->getPlayerrect()))
		{
			PLAYER->getinventory()->additem(_item[i]);
			_item.erase(_item.begin() + i);
			break;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&myland, CURSOR->getPoint()))
		{
			SCENEMANAGER->changeScene("����1");
			PLAYER->setplayerXY(450, 450);
		}
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
	_other->render();
	_monster->render();
	PLAYER->invenrender(getMemDC());

	if (!_dropitem.empty())
	{
		for (int i = 0; i < _dropitem.size(); i++)
		{
			_dropitem[i].render(getMemDC());
		}
	}
	if (!_item.empty())
	{
		for (int i = 0; i < _item.size(); i++)
		{
			_item[i].render(getMemDC());
		}
	}


}

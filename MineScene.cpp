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
	SOUNDMANAGER->stop("¸¶À»");
	SOUNDMANAGER->play("µ¿±¼");
	_tilm = new tileManager;
	_tilm->Mineload();
	//ÇÃ·¹ÀÌ¾î
	//PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilm);
	PLAYER->setPlayerPosition(_tilm->getMap()[_tilm->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));
	myland = RectMakeCenter(925, 350, 100, 450);
	mylandrmidle = RectMakeCenter(925, 350, 400, 300);
	istwinkle = false;
	i = 10;

	_night = new image;
	_night->init("images/UI/³·°ú¹ã.bmp", 2000, 1700, true, RGB(255, 0, 255));

	_astar = new aStarScene;
	_astar->init(_tilm->getMap());

	_other = new othermanager;
	_other->init1();

	_monster = new Monstermanager;
	_monster->init();


	count = 0;
	rockdrop[0] = RectMakeCenter(600, 600, 50, 50);
	rockdrop[1] = RectMakeCenter(1000, 600, 50, 50);
	rockdrop[2] = RectMakeCenter(600, 1000, 50, 50);
	rockdrop[3] = RectMakeCenter(1000, 1000, 50, 50);

	drop1 = new effect;
	drop1->init(IMAGEMANAGER->findImage("µ¹±úÁü"), 48, 48, 1, 1.0f);
	drop2 = new effect;
	drop2->init(IMAGEMANAGER->findImage("µ¹±úÁü"), 48, 48, 1, 1.0f);
	drop3 = new effect;
	drop3->init(IMAGEMANAGER->findImage("µ¹±úÁü"), 48, 48, 1, 1.0f);
	drop4 = new effect;
	drop4->init(IMAGEMANAGER->findImage("µ¹±úÁü"), 48, 48, 1, 1.0f);

	return S_OK;
}

void MineScene::release()
{
	_astar->release();

}

void MineScene::update()
{
	PLAYER->update();
	PLAYER->getclock()->setisturn(false);
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
	//if (PtInRect(&mylandrmidle, CURSOR->getPoint()))
	//{
	//	istwinkle = true;
	//}
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&myland, CURSOR->getPoint()))
		{
			SCENEMANAGER->changeScene("³»¶¥1");
			PLAYER->setplayerXY(450, 450);
		}
	}

	mashrock();
}



void MineScene::render()
{
	_tilm->render();
	_astar->render();
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < 4; i++)
		{
			Rectangle(getMemDC(), rockdrop[i].left, rockdrop[i].top, rockdrop[i].right, rockdrop[i].bottom);
		}
		Rectangle(getMemDC(), mylandrmidle.left, mylandrmidle.top, mylandrmidle.right, mylandrmidle.bottom);
		Rectangle(getMemDC(), myland.left, myland.top, myland.right, myland.bottom);
	}
	PLAYER->render(/*CAMERA->getCameraDC()*/getMemDC());

	

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
	if (istwinkle)_night->alphaRender(getMemDC(), i++);
	drop1->render();
	drop2->render();
	drop3->render();
	drop4->render();
}

void MineScene::mashrock()
{
	RECT temp1;
	if (IntersectRect(&temp1, &rockdrop[0], &PLAYER->getTool()->getpickaxe()))
	{
		count++;
		if (count == 50)
		{
			drop1->startEffect(600, 600);
			count = 0;
		}
	}
	RECT temp2;
	if (IntersectRect(&temp1, &rockdrop[1], &PLAYER->getTool()->getpickaxe()))
	{
		count++;
		if (count == 50)
		{
			drop2->startEffect(1000, 600);
			count = 0;
		}
	}
	RECT temp3;
	if (IntersectRect(&temp1, &rockdrop[2], &PLAYER->getTool()->getpickaxe()))
	{
		count++;
		if (count == 50)
		{
			drop3->startEffect(600, 1000);
			count = 0;
		}
	}
	RECT temp4;
	if (IntersectRect(&temp1, &rockdrop[3], &PLAYER->getTool()->getpickaxe()))
	{
		count++;
		if (count == 50)
		{
			drop4->startEffect(1000, 1000);
			count = 0;
		}
	}


	drop1->update();
	drop2->update();
	drop3->update();
	drop4->update();
}

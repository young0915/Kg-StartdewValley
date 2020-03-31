#include "stdafx.h"
#include "town2.h"

town2::town2()
{
}

town2::~town2()
{
}

HRESULT town2::init()
{
	_tilem = new tileManager;
	_tilem->TownTwo();

	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//카메라 위치

	IMAGEMANAGER->findImage("상점");
	IMAGEMANAGER->findImage("상점1");
	IMAGEMANAGER->findImage("집1");
	IMAGEMANAGER->findImage("집11");
	IMAGEMANAGER->findImage("집2");
	IMAGEMANAGER->findImage("집22");

	//나무들
	for (int i = 0; i < 2; i++)
	{
		_tree[i]._img = new image;
		_tree[i]._img->init("images/etc/나무1.bmp", 48 * 4, 100 * 4, true, RGB(255, 0, 255));
		_tree[0].x = 200;
		_tree[0].y = 400;
		_tree[1].x = 950;
		_tree[1].y = 400;
		_tree[i].rc = RectMakeCenter(_tree[i].x, _tree[i].y, _tree[i]._img->getWidth(), _tree[i]._img->getHeight());
		_tree[i].midrc = RectMakeCenter((_tree[i].rc.right - (_tree[i].rc.right - _tree[i].rc.left) / 2),
			(_tree[i].rc.bottom - (_tree[i].rc.bottom - _tree[i].rc.top) / 2), _tree[i]._img->getWidth(), _tree[i]._img->getHeight());
		_tree[i]._isnear = false;

		_twtree[i]._img = new image;
		_twtree[i]._img->init("images/etc/나무2.bmp", 50 * 4, 100 * 4, true, RGB(255, 0, 255));
		_twtree[0].x = 1800;
		_twtree[0].y = 150;
		_twtree[1].x = 1300;
		_twtree[1].y = 1100;
		_twtree[i].rc = RectMakeCenter(_twtree[i].x, _twtree[i].y, _twtree[i]._img->getWidth(), _twtree[i]._img->getHeight());
		_twtree[i].midrc = RectMakeCenter((_twtree[i].rc.right - (_twtree[i].rc.left - _twtree[i].rc.left) / 2), (_twtree[i].rc.bottom - (_twtree[i].rc.bottom - _twtree[i].rc.top) / 2),
			_twtree[i]._img->getWidth(), _twtree[i]._img->getHeight());
		_twtree[i]._isnear = false;
	}
	
	myhome = RectMakeCenter(100, 500, 50, 500);
	return S_OK;
}

void town2::release()
{
}

void town2::update()
{
	PLAYER->update();

	//나무 1 과 닿으면
	for (int i = 0; i < 2; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_tree[i].rc, &PLAYER->getPlayerrect()))
		{
			_tree[i]._isnear = true;
		}
		else
		{
			_tree[i]._isnear = false;

		}
		//나무 2와 닿으면 
		RECT othertemp;
		if (IntersectRect(&othertemp, &_twtree[i].rc, &PLAYER->getPlayerrect()))
		{
			_twtree[i]._isnear = true;
		}
		else
		{
			_twtree[i]._isnear = false;
		}
	}
	RECT temp;
	if (IntersectRect(&temp, &myhome, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("내땅2");
		PLAYER->setplayerXY(1500, 400);
	}
}



void town2::render()
{
	_tilem->render();
	IMAGEMANAGER->render("상점", getMemDC(), 900, 50);
	IMAGEMANAGER->render("집1", getMemDC(), 100, 750);
	IMAGEMANAGER->render("집11", getMemDC(), 100, 750);
	IMAGEMANAGER->render("집2", getMemDC(), 1000, 750);


	PLAYER->render(getMemDC());


	//집 지붕
	IMAGEMANAGER->render("집22", getMemDC(), 1000, 750);
	IMAGEMANAGER->render("상점1", getMemDC(), 900, 50);

	for (int i = 0; i < 2; i++)
	{
		if (_tree[i]._isnear)	_tree[i]._img->alphaRender(getMemDC(), _tree[i].midrc.left, _tree[i].midrc.top, 100);
		else _tree[i]._img->render(getMemDC(), _tree[i].midrc.left, _tree[i].midrc.top);


		if (_twtree[i]._isnear) _twtree[i]._img->alphaRender(getMemDC(), _twtree[i].midrc.left, _twtree[i].midrc.top, 100);
		else _twtree[i]._img->render(getMemDC(), _twtree[i].midrc.left, _twtree[i].midrc.top);


		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), _tree[i].midrc.left, _tree[i].midrc.top, _tree[i].midrc.right, _tree[i].midrc.bottom);
			Rectangle(getMemDC(), _twtree[i].midrc.left, _twtree[i].midrc.top, _twtree[i].midrc.right, _twtree[i].midrc.bottom);
		}
	}

}

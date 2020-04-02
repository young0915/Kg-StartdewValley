#include "stdafx.h"
#include "Myland2.h"

Myland2::Myland2()
{
}

Myland2::~Myland2()
{
}

HRESULT Myland2::init()
{
	//��
	_tilem = new tileManager;
	_tilem->Mylandtwo();

	//�÷��̾�
//	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");

	_twinkle = new image;
	_twinkle->init("images/UI/������.bmp", 2000, 1700, true, RGB(255, 0, 255));
	myhomerect = RectMakeCenter(1200, 500, 100, 100);
	i = 20;
	istwinkel = false;
	myhome = RectMakeCenter(1200, 450, 80, 80);
	_ground = new groundManager;
	_ground->init();

	_vegetable = new vegetablemanager;
	_vegetable->init();

	return S_OK;
}

void Myland2::release()
{
	_ground->release();
}

void Myland2::update()
{
	PLAYER->update();
	if (PLAYER->getclock()->gethour() == 5)
	{
		PLAYER->getclock()->setisturn(true);
	}
	else
	{
		PLAYER->getclock()->setisturn(false);

	}
	_ground->update();
	_vegetable->update(_item);
	RECT temp;
	for (int i = 0; i < _item.size(); i++)
	{
		_item[i].update();
		if (IntersectRect(&temp, &_item[i].getRect(), &PLAYER->getPlayerrect()))
		{
			PLAYER->getinventory()->additem(_item[i]);
			_item.erase(_item.begin() + i);
			break;
		}
	}

	RECT hometemp;
	if (IntersectRect(&hometemp, &myhome, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("����");
		PLAYER->setplayerXY(300, 500);
	}

	RECT temptwinkle;
	if (IntersectRect(&temptwinkle, &myhomerect, &PLAYER->getPlayerrect()))
	{
		istwinkel = true;
	}
}

void Myland2::render()
{
	_tilem->render();
	_ground->render();
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("����", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	_vegetable->render();
	IMAGEMANAGER->render("����", getMemDC(), 912, 150);
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	PLAYER->invenrender(getMemDC());


	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), myhomerect.left, myhomerect.top, myhomerect.right, myhomerect.bottom);
		Rectangle(getMemDC(), myhome.left, myhome.top, myhome.right, myhome.bottom);
	}

	if (!_item.empty())
	{
		for (int i = 0; i < _item.size(); i++)
		{
			_item[i].render(getMemDC());
		}
	}
	if (istwinkel)_twinkle->alphaRender(getMemDC(), i++);

}

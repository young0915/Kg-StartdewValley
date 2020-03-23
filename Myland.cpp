#include "stdafx.h"
#include "Myland.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{

	//��
	_tilem = new tileManager;
	_tilem->Mylandload();

	//�÷��̾�
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	_minego = RectMakeCenter(430, 300, 80, 80);
	//_myhouse = RectMakeCenter(500, 450, 250, 250);
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");

	return S_OK;
}

void Myland::release()
{
}

void Myland::update()
{
	
	PLAYER->update();
	//�̵� �Ϸ�

	RECT temp;
	if (IntersectRect(&temp, &_minego, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("����");
		PLAYER->setplayerXY(700, 650);
	}
	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		SCENEMANAGER->changeScene("����");
	}

}
void Myland::render()
{
	

	_tilem->render();
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("����", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("����", getMemDC(), 912, 150);
	IMAGEMANAGER->render("����", getMemDC(), 1302, 400);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _minego.left, _minego.top, _minego.right, _minego.bottom);
	//	Rectangle(getMemDC(), _myhouse.left, _myhouse.top, _myhouse.right, _myhouse.bottom);
	}

}


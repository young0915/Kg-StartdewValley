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
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");

	townrect = RectMakeCenter(1400,400, 50, 200);

	_other = new othermanager;
	_other->init();

	return S_OK;
}

void Myland::release()
{
	SAFE_DELETE(_tilem);
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
	RECT twongo;
	if (IntersectRect(&twongo, &townrect, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("����1");
		PLAYER->setplayerXY(100, 300);
	}

	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		SCENEMANAGER->changeScene("����");
	}

	_other->update(_dropitem);

}
void Myland::render()
{
	_tilem->render();
	
	IMAGEMANAGER->render("����", getMemDC(), 1202, 400);
	IMAGEMANAGER->render("����", getMemDC(), 812, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("����", getMemDC(), 812, 150);
	IMAGEMANAGER->render("����", getMemDC(), 1202, 400);
	_other->render();
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _minego.left, _minego.top, _minego.right, _minego.bottom);
		Rectangle(getMemDC(), townrect.left, townrect.top, townrect.right, townrect.bottom);
		//	Rectangle(getMemDC(), _myhouse.left, _myhouse.top, _myhouse.right, _myhouse.bottom);
	}

	if (!_dropitem.empty())
	{
		for (int i = 0; i < _dropitem.size(); i++)
		{
			_dropitem[i].render(getMemDC());
		}
	}



}


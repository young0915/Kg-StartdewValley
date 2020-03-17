#include "stdafx.h"
#include "Myland.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{
	//��
	_tilem = new tileManager;
	_tilem->Mylandload(100, 100);
	//�÷��̾�
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//ī�޶� ��ġ

	_minego = RectMakeCenter(185, 100, 250, 250);
	_myhouse = RectMakeCenter(500, 450, 250, 250);
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");

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
	//�̵� �Ϸ�

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_minego, m_ptMouse))
		{

			SCENEMANAGER->changeScene("����");
		}
	}
	
		if (PtInRect(&_myhouse, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			SCENEMANAGER->changeScene("����");
		}


	if (KEYMANAGER->isOnceKeyDown('8'))
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
		Rectangle(getMemDC(), _myhouse.left, _myhouse.top, _myhouse.right, _myhouse.bottom);
	}

}


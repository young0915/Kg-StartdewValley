#include "stdafx.h"
#include "Myland.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{
	//맵
	_tilem = new tileManager;
	_tilem->Mylandload(100, 100);
	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//카메라 위치

	_minego = RectMakeCenter(185, 100, 250, 250);
	_myhouse = RectMakeCenter(500, 450, 250, 250);
	IMAGEMANAGER->findImage("내집");
	IMAGEMANAGER->findImage("지붕");
	IMAGEMANAGER->findImage("우편");

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
	//이동 완료

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_minego, m_ptMouse))
		{

			SCENEMANAGER->changeScene("동굴");
		}
	}
	
		if (PtInRect(&_myhouse, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			SCENEMANAGER->changeScene("내집");
		}


	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		SCENEMANAGER->changeScene("내집");
	}
}
void Myland::render()
{
	_tilem->render();
	IMAGEMANAGER->render("우편", getMemDC(), 1302, 400);
	IMAGEMANAGER->render("내집", getMemDC(), 912, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("지붕", getMemDC(), 912, 150);
	IMAGEMANAGER->render("우편", getMemDC(), 1302, 400);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _minego.left, _minego.top, _minego.right, _minego.bottom);
		Rectangle(getMemDC(), _myhouse.left, _myhouse.top, _myhouse.right, _myhouse.bottom);
	}

}


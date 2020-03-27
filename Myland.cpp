#include "stdafx.h"
#include "Myland.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{

	//맵
	_tilem = new tileManager;
	_tilem->Mylandload();

	//플레이어
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//카메라 위치

	_minego = RectMakeCenter(430, 300, 80, 80);
	IMAGEMANAGER->findImage("내집");
	IMAGEMANAGER->findImage("지붕");
	IMAGEMANAGER->findImage("우편");

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
	//이동 완료

	RECT temp;
	if (IntersectRect(&temp, &_minego, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("동굴");
		PLAYER->setplayerXY(700, 650);
	}
	RECT twongo;
	if (IntersectRect(&twongo, &townrect, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("마을1");
		PLAYER->setplayerXY(100, 300);
	}

	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		SCENEMANAGER->changeScene("상점");
	}

	_other->update(_dropitem);

}
void Myland::render()
{
	_tilem->render();
	
	IMAGEMANAGER->render("우편", getMemDC(), 1202, 400);
	IMAGEMANAGER->render("내집", getMemDC(), 812, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("지붕", getMemDC(), 812, 150);
	IMAGEMANAGER->render("우편", getMemDC(), 1202, 400);
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


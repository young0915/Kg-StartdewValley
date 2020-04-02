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
	_minegotwinkle = RectMakeCenter(430, 320, 120, 160);
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	IMAGEMANAGER->findImage("����");
	_twinkle = new image;
	_twinkle->init("images/UI/������.bmp", 2000, 1700, true, RGB(255, 0, 255));
	townrect = RectMakeCenter(1400,400, 50, 200);

	isturnon = false;
	i = 100;

	_other = new othermanager;
	_other->init();
	return S_OK;
}

void Myland::release()
{
	SAFE_DELETE(_tilem);
	SAFE_DELETE(_twinkle);
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
	RECT twinkeltemp;
	if (IntersectRect(&twinkeltemp, &_minegotwinkle, &PLAYER->getPlayerrect()))
	{
		isturnon = true;
	}

	RECT twongo;
	if (IntersectRect(&twongo, &townrect, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("����1");
		PLAYER->setplayerXY(500, 300);
	}
	
	_other->update(_dropitem);
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
	PLAYER->invenrender(getMemDC());
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _minegotwinkle.left, _minegotwinkle.top, _minegotwinkle.right, _minegotwinkle.bottom);
		Rectangle(getMemDC(), _minego.left, _minego.top, _minego.right, _minego.bottom);
		Rectangle(getMemDC(), townrect.left, townrect.top, townrect.right, townrect.bottom);
	}

	if (!_dropitem.empty())
	{
		for (int i = 0; i < _dropitem.size(); i++)
		{
			_dropitem[i].render(getMemDC());
		}
	}
	if (isturnon) _twinkle->alphaRender(getMemDC(), i++);

}


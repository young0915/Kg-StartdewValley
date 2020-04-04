#include "stdafx.h"
#include "Myhouse.h"

Myhouse::Myhouse()
{
}

Myhouse::~Myhouse()
{
}

HRESULT Myhouse::init()
{
	SOUNDMANAGER->stop("마을1");
	SOUNDMANAGER->play("마을1");
	time = 0;
	_tilem = new tileManager;
	_tilem->Myhouse();
	//플레이어
//	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));
	IMAGEMANAGER->findImage("침대");
	IMAGEMANAGER->findImage("침대2");

	_sleep.x = 690;
	_sleep.y = 520;
	_sleep.bedrect = RectMakeCenter(_sleep.x, _sleep.y, 50, 200);


	askrect[0] = RectMakeCenter(40, WINSIZEY / 2 + 200, 500, 50);
	askrect[1] = RectMakeCenter(40, WINSIZEY / 2 + 260, 500, 50);

	ischeck = false;
	IMAGEMANAGER->findImage("물어보는창");

	_bk = new image;
	_bk->init("images/인벤토리/인벤토리배경화면.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	isblank = false;
	i = 0;
	return S_OK;
}

void Myhouse::release()
{
	PLAYER->release();
}

void Myhouse::update()
{
	PLAYER->update();
	PLAYER->getclock()->setisturn(false);
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		time = TIMEMANAGER->getWorldTime();
		for (int i = 0; i < 2; i++)
		{
			if (PtInRect(&askrect[i], m_ptMouse))
				if (i == 0)
				{
					isblank = true;
					PLAYER->init();
					if (TIMEMANAGER->getWorldTime() - time <= 1.5)
					{
						if (PLAYER->getclock()->getDay() == MONDAY)
						{
							PLAYER->getclock()->setDay(TUESDAY);
						}
					}
				}
				else
				{
					ischeck = false;
				}
		}
	}

	if (getDistance(_sleep.x, _sleep.y, PLAYER->getplayerX(), PLAYER->getplayerY()) < 50)
	{
		ischeck = true;
	}
	else
	{
		ischeck = false;
	}

}

void Myhouse::render()
{
	_tilem->render();
	IMAGEMANAGER->render("침대", getMemDC(), 635, 490);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("침대2", getMemDC(), 635, 500);

	PLAYER->invenrender(getMemDC());
	if (ischeck)uirender();
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _sleep.bedrect.left, _sleep.bedrect.top, _sleep.bedrect.right, _sleep.bedrect.bottom);
	}

}

void Myhouse::uirender()
{
	IMAGEMANAGER->render("물어보는창", CAMERA->getCameraDC(), 10, WINSIZEY / 2 + 100);
	FontTextOut(CAMERA->getCameraDC(), 40, WINSIZEY / 2 + 150, "오늘은 이만 잠들까요?", 30, "경기천년제목L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 40, WINSIZEY / 2 + 200, "네", 30, "경기천년제목L Light", RGB(41, 41, 41));
	FontTextOut(CAMERA->getCameraDC(), 40, WINSIZEY / 2 + 250, "아니오", 30, "경기천년제목L Light", RGB(41, 41, 41));
	if (isblank)
	{
		_bk->alphaRender(CAMERA->getCameraDC(), 0, 0, i++);
		if (i == 250)
		{
			isblank = false;
		}
	}

}

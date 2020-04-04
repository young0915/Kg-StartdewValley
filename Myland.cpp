#include "stdafx.h"
#include "Myland.h"
#include "effect.h"

Myland::Myland() {}

Myland::~Myland() {}

HRESULT Myland::init()
{
	SOUNDMANAGER->stop("ÀÎÆ®·Î");
	SOUNDMANAGER->play("¸¶À»");
	//¸Ê
	_tilem = new tileManager;
	_tilem->Mylandload();

	//ÇÃ·¹ÀÌ¾î
	PLAYER->init();
	PLAYER->setMapMemoryAdress(_tilem);
	PLAYER->setPlayerPosition(_tilem->getMap()[_tilem->getPosFirst()].rc);
	CAMERA->setCameraCenter(PointMake(PLAYER->getplayerX(), PLAYER->getplayerY()));						//Ä«¸Þ¶ó À§Ä¡

	_minego = RectMakeCenter(430, 300, 80, 80);
	_minegotwinkle = RectMakeCenter(430, 320, 120, 160);
	IMAGEMANAGER->findImage("³»Áý");
	IMAGEMANAGER->findImage("ÁöºØ");
	IMAGEMANAGER->findImage("¿ìÆí");
	_twinkle = new image;
	_twinkle->init("images/UI/³·°ú¹ã.bmp", 2000, 1700, true, RGB(255, 0, 255));
	townrect = RectMakeCenter(1400, 400, 50, 200);

	isturnon = false;
	time2 = 0;
	i = 100;
	IMAGEMANAGER->addFrameImage("³ª¹«°¡¾²·¯Áü", "images/ÀÌÆÑÆ®È¿°ú/maptool_tree1_down.bmp", 2592, 2160, 9, 5, true, RGB(255, 0, 255));
	ANIMATIONMANAGER->addAnimation("ani", "³ª¹«°¡¾²·¯Áü", 0, 44, 10, false, true);
	tree._img = IMAGEMANAGER->findImage("³ª¹«°¡¾²·¯Áü");
	tree._ani = ANIMATIONMANAGER->findAnimation("ani");
	tree.x = 480;
	tree.y = 350;
	tree.atkcount = 0;
	tree.rc = RectMakeCenter(tree.x, tree.y, tree._img->getFrameWidth(), tree._img->getFrameHeight());
	tree.ischeck = false;
	tree.time = 0;

	mashrect[0] = RectMakeCenter(450, 650, 50, 50);
	mashrect[1] = RectMakeCenter(550, 750, 50, 50);
	mashrect[2] = RectMakeCenter(350, 650, 50, 50);
	mashrect[3] = RectMakeCenter(600, 700, 50, 50);


	count = 0;

	_other = new othermanager;
	_other->init();

	treedrop = new effect;
	treedrop->init(IMAGEMANAGER->findImage("³ª¹µÀÙ"), 280, 160, 1, 1.2f);

	grassdrop = new effect;
	grassdrop->init(IMAGEMANAGER->findImage("ÀÜµð¶³¾îÁü"), 48, 48, 1, 0.8f);

	grassdrop1 = new effect;
	grassdrop1->init(IMAGEMANAGER->findImage("ÀÜµð¶³¾îÁü"), 48, 48, 1, 0.8f);

	rockdrop = new effect;
	rockdrop->init(IMAGEMANAGER->findImage("µ¹±úÁü"), 48, 48, 1, 0.8f);
	
	rockdrop1 = new effect;
	rockdrop1->init(IMAGEMANAGER->findImage("µ¹±úÁü"), 48, 48, 1, 1.0f);
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

	//ÀÌµ¿ ¿Ï·á
	RECT temp;
	if (IntersectRect(&temp, &_minego, &PLAYER->getPlayerrect()))
	{
		SCENEMANAGER->changeScene("µ¿±¼");
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
		SCENEMANAGER->changeScene("¸¶À»1");
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
	RECT temptree;
	if (IntersectRect(&temptree, &tree.rc, &PLAYER->getTool()->getaxe()))
	{
		tree.ischeck = true;
		if (tree.ischeck)
		{
			tree._ani = ANIMATIONMANAGER->findAnimation("ani");
			ANIMATIONMANAGER->start("ani");
			tree.time = TIMEMANAGER->getWorldTime();
			treedrop->startEffect(600, 600);
		}
	}
	if (TIMEMANAGER->getWorldTime() - tree.time > 4.2)
	{
		tree._ani = ANIMATIONMANAGER->findAnimation("ani");
		ANIMATIONMANAGER->pause("ani");
		tree.ischeck = false;
	}
	mashground();
	treedrop->update();
	grassdrop->update();
	grassdrop1->update();
	rockdrop->update();
	rockdrop1->update();
}

void Myland::render()
{
	_tilem->render();
	IMAGEMANAGER->render("¿ìÆí", getMemDC(), 1202, 400);
	IMAGEMANAGER->render("³»Áý", getMemDC(), 812, 147);
	PLAYER->render(getMemDC());
	IMAGEMANAGER->render("ÁöºØ", getMemDC(), 812, 150);
	IMAGEMANAGER->render("¿ìÆí", getMemDC(), 1202, 400);
	
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < 4; i++)
		{
			Rectangle(getMemDC(), mashrect[i].left, mashrect[i].top, mashrect[i].right, mashrect[i].bottom);
		}
		Rectangle(getMemDC(), _minegotwinkle.left, _minegotwinkle.top, _minegotwinkle.right, _minegotwinkle.bottom);
		Rectangle(getMemDC(), _minego.left, _minego.top, _minego.right, _minego.bottom);
		Rectangle(getMemDC(), townrect.left, townrect.top, townrect.right, townrect.bottom);
	}
	_other->render();
	PLAYER->invenrender(getMemDC());

	if (!_dropitem.empty())
	{
		for (int i = 0; i < _dropitem.size(); i++)
		{
			_dropitem[i].render(getMemDC());
		}
	}
	if (isturnon) _twinkle->alphaRender(getMemDC(), i++);
	if (tree.ischeck)tree._img->aniRender(getMemDC(), tree.x, tree.y, tree._ani);

	treedrop->render();
	grassdrop->render();
	grassdrop1->render();
	rockdrop->render();
	rockdrop1->render();
}

void Myland::mashground()
{
	RECT onetemp;
	if (IntersectRect(&onetemp, &mashrect[0], &PLAYER->getTool()->getaxe()))
	{
		count++;
		if (count == 35)
		{
			grassdrop->startEffect(450, 650);
			count = 0;
		}
	}
	RECT twotemp;
	if (IntersectRect(&onetemp, &mashrect[1], &PLAYER->getTool()->getaxe()))
	{
		count++;
		if (count == 35)
		{
			grassdrop1->startEffect(550, 750);
			count = 0;
		}
	}

	RECT threetemp;
	if (IntersectRect(&onetemp, &mashrect[2], &PLAYER->getTool()->getpickaxe()))
	{
		count++;
		if (count == 35)
		{
			rockdrop->startEffect(350, 650);
			count = 0;
		}
	}
	RECT fourtemp;
	if (IntersectRect(&onetemp, &mashrect[3], &PLAYER->getTool()->getpickaxe()))
	{
		count++;
		if (count == 35)
		{
			rockdrop1->startEffect(600, 700);
			count = 0;
		}
	}


}

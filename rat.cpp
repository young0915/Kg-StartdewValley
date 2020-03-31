#include "stdafx.h"
#include "rat.h"
rat::rat()
{
}

rat::~rat()
{
}

HRESULT rat::init()
{
	_rat.img = IMAGEMANAGER->findImage("박쥐");
	_rat.x = WINSIZEX/2;
	_rat.y = WINSIZEY/2;
	_rat.rc = RectMakeCenter(_rat.x, _rat.y, 50/*_rat.img->getFrameWidth()*/, 50/*_rat.img->getFrameHeight()*/);
	//충돌
	_rat.collison1 = RectMakeCenter(704, 885, 1000, 580);
	ANIMATIONMANAGER->addAnimation("날아", "박쥐", 0, 3, 10, false, true);
	//시작 애니메이션 설정
	_rat._ani = ANIMATIONMANAGER->findAnimation("날아");
	ANIMATIONMANAGER->resume("날아");
	_rat._isdie = false;
	return S_OK;
}

void rat::release(){}

void rat::update()
{
	ratmove();
	RECT temp;
	if (IntersectRect(&temp, &_rat.rc, &PLAYER->getweapon()))
	{
		_rat._isdie = true;
	}
	RECT playerrect;
	if (IntersectRect(&playerrect, &_rat.rc, &PLAYER->getPlayerrect()))
	{
		PLAYER->setHp(PLAYER->getHp() +1);
	}
}

void rat::render()
{
	AlphaRectangle(getMemDC(), _rat.collison1.left, _rat.collison1.top, _rat.collison1.right, _rat.collison1.bottom);
	//_rat.img->frameRender(getMemDC(), _rat.rc.left, _rat.rc.top);
	if (!_rat._isdie)
	{
		_rat.img->aniRender(getMemDC(), _rat.rc.left, _rat.rc.top, _rat._ani);
	}
}

void rat::ratmove()
{
	switch (_rat._rat)
	{
	case R_MOVE:
		_rat.count++;
		_rat.img->setFrameY(0);
		if (_rat.count % 5 == 0)
		{
			_rat.count = 0;
			_rat.index++;
			if (_rat.index >= _rat.img->getMaxFrameX())
			{
				_rat.index = 0;
			}
		}
		_rat.img->setFrameX(_rat.index);
		break;
	case R_DIE:
		_rat.count++;
		_rat.img->setFrameY(0);
		if (_rat.count % 5 == 0)
		{
			_rat.count = 0;
			_rat.index++;
			if (_rat.index >= _rat.img->getMaxFrameX())
			{
				_rat.index = 0;
			}
		}
		_rat.img->setFrameX(_rat.index);
		break;
	}
}

void rat::remove(int num)
{
}

#include "stdafx.h"
#include "monster.h"

monster::monster()
{
}

monster::~monster()
{
}

HRESULT monster::init(const char * name, POINT position, M_DIRECTION direction, MONSTERMOVE move, bool ismove)
{
	index = 0;
	count = 0; 
	_img = IMAGEMANAGER->findImage(name);
	_rc = RectMakeCenter(position.x, position.y, _img->getFrameWidth(), _img->getFrameHeight());
	_atkrc = RectMakeCenter(position.x, position.y, _img->getFrameWidth() * 4, _img->getFrameHeight() *3);
	_direction = direction;
	_monster = move;
	_ismove = ismove;
	_item = ITEMMANAGER->additem("게");
	return S_OK;
}

void monster::release()
{
	ANIMATIONMANAGER->deleteALL();

}

void monster::update()
{
	_item.update();
	crabSTATE();
}



void monster::crabSTATE()
{
	switch (_monster)
	{
	case MONSTER_IDLE:
		count++;
		_img->setFrameY(0);
		if (count % 5 == 0)
		{
			count = 0;
			index++;
			if (index >= _img->getMaxFrameX())
			{
				index = 0;
			}
		}
		_img->setFrameX(index);
		break;
	case MONSTER_MOVE:
		_ismove = true;																			//움직이는 동작 실행
		crabmove();
		count++;
		_img->setFrameY(1);
		if (count % 5 == 0)
		{
			count = 0;
			index++;
			if (index >= _img->getMaxFrameX())
			{
				index = 0;
			}
		}
		_img->setFrameX(index);
		break;
	case MONSTER_DIE:
		count++;
		_img->setFrameY(2);
		if (count % 5 == 0)
		{
			count = 0;
			index++;
			if (index >= _img->getMaxFrameX())
			{
				index = 0;
			}
		}
		_img->setFrameX(index);
		break;
	}
}

void monster::crabmove()
{
	num = RND->getFromIntTo(0, _direction);
	switch (_direction)
	{
	case M_LEFT  :
		_rc.left -= 2.f;
		_rc.right -= 2.f;
		break;
	case M_RIGHT:
		_rc.left += 2.f;
		_rc.right += 2.f;
		break;
	case  M_UP:
		_rc.top -= 2.f;
		_rc.bottom -= 2.f;
		break;
	case M_DOWN:
		_rc.top += 2.f;
		_rc.bottom += 2.f;
		break;
	case M_LB:
		_rc.left -= 0.5f;
		_rc.bottom -= 0.5f;
		break;
	case M_RB:
		_rc.bottom += 0.5f;
		_rc.right += 0.5f;
		break;
	case M_LU:
		_rc.left -= 0.5f;
		_rc.top -= 0.5f;
		break;
	case M_RU:
		_rc.right -= 0.5f;
		_rc.top -= 0.5f;
		break;
	}
	_atkrc = RectMakeCenter(_rc.right + ((_rc.right - _rc.left) / 2), _rc.bottom + ((_rc.bottom - _rc.top) / 2), _img->getFrameWidth() * 4, _img->getFrameHeight() * 3);
}

void monster::render()
{
	if (KEYMANAGER->isToggleKey('Q'))
	{
		Rectangle(getMemDC(), _atkrc.left, _atkrc.top, _atkrc.right, _atkrc.bottom);
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
	_item.render();
}

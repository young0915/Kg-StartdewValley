#include "stdafx.h"
#include "tool.h"

tool::tool()
{
}

tool::~tool()
{
}

HRESULT tool::init()
{
	_ax._img = IMAGEMANAGER->findImage("µµ³¢");
	_ax._tdir = T_STOP;
	_ax.count = 0;
	_ax.index = 0; 
	_ax.rc = RectMakeCenter(PLAYER->getplayerX(), PLAYER->getplayerY(), _ax._img->getFrameWidth(), _ax._img->getFrameHeight());
	return S_OK;
}

void tool::release()
{
}


void tool::update()
{
}
void tool::axemove(int x, int y, TOOLDIR _dir)
{
}
void tool::pickmove(int x, int y, TOOLDIR _dir)
{
}
void tool::homiemove(int x, int y, TOOLDIR _dir)
{
}
void tool::watercanmove(int x, int y, TOOLDIR _dir)
{
}
//
//void tool::toolmove(TOOLDIR _dir)
//{
//	_ax._tdir = _dir;
//	switch (_dir)
//	{
//	case T_DOWN :
//		_ax.count++;
//		_ax._img->setFrameY(0);
//		if (_ax.count % 4 == 0)
//		{
//			_ax.count = 0; 
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	case T_RIGHT :
//		_ax.count++;
//		_ax._img->setFrameY(1);
//		if (_ax.count % 4 == 0)
//		{
//			_ax.count = 0;
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	case T_LEFT :
//		_ax.count++;
//		_ax._img->setFrameY(2);
//		if (_ax.count % 4 == 0)
//		{
//			_ax.count = 0;
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	case T_UP:
//		_ax.count++;
//		_ax._img->setFrameY(3);
//		if (_ax.count % 4 == 0)
//		{
//			_ax.count = 0;
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	}
//}

void tool::render()
{
	_ax._img->frameRender(getMemDC(), PLAYER->getPlayerrect().left, PLAYER->getPlayerrect().top);
}
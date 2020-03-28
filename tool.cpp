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
	_axe._type = TOOL_AXE;
	_axe._img = IMAGEMANAGER->findImage("µµ³¢");
	_axe._tm = TT_NONE;

	_pickaxe._type = TOOL_PICKAXE;
	_pickaxe._img = IMAGEMANAGER->findImage("°î±ªÀÌ");
	_pickaxe._tm = TT_NONE;

	_hoe._type = TOOL_HOE;
	_hoe._img = IMAGEMANAGER->findImage("È£¹Ì");
	_hoe._tm = TT_NONE;
	return S_OK;
}

void tool::release()
{
}

void tool::update()
{
}


void tool::axemove(int _x, int _y, TOOLTYPE _ttype, TOOLMOVE _move)
{
	_axe.x = _x;
	_axe.y = _y;
	_axe._tm = _move;
	_axe._type = _ttype;
	_axe._rc = RectMakeCenter(-50, -50, _axe._img->getFrameWidth(), _axe._img->getFrameHeight());
	
	switch (_move)
	{
	case T_DOWN:
		_axe._count++;
		_axe._img->setFrameY(0);
		if (_axe._count % 5 == 0)
		{
			_axe._count = 0;
			_axe._index++;
			if (_axe._index >= _axe._img->getMaxFrameX())
			{
				_axe._index = 0;
			}
		}
		_axe._img->setFrameX(_axe._index);
		_axe._rc = RectMakeCenter(PLAYER->getintplayerX(), PLAYER->getintplayerY() , 50, 50);

		break;
	case T_RIGHT:
		_axe._count++;
		_axe._img->setFrameY(1);
		if (_axe._count % 5 == 0)
		{
			_axe._count = 0;
			_axe._index++;
			if (_axe._index >= _axe._img->getMaxFrameX())
			{
				_axe._index = 0;
			}
		}
		_axe._img->setFrameX(_axe._index);
		_axe._rc = RectMakeCenter(PLAYER->getintplayerX() + 25, PLAYER->getintplayerY() - 20, 50, 50);

		break;
	case T_LEFT:
		_axe._count++;
		_axe._img->setFrameY(2);
		if (_axe._count % 5 == 0)
		{
			_axe._count = 0;
			_axe._index++;
			if (_axe._index >= _axe._img->getMaxFrameX())
			{
				_axe._index = 0;
			}
		}
		_axe._img->setFrameX(_axe._index);
		_axe._rc = RectMakeCenter(PLAYER->getintplayerX() - 25, PLAYER->getintplayerY() - 20, 50, 50);
		break;
	case T_UP:
		_axe._count++;
		_axe._img->setFrameY(3);
		if (_axe._count % 5 == 0)
		{
			_axe._count = 0;
			_axe._index++;
			if (_axe._index >= _axe._img->getMaxFrameX())
			{
				_axe._index = 0;
			}
		}
		_axe._img->setFrameX(_axe._index);
		break;
	case T_NONE:
		_axe._count++;
		_axe._img->setFrameY(4);
		if (_axe._count % 5 == 0)
		{
			_axe._count = 0;
			_axe._index++;
			if (_axe._index >= _axe._img->getMaxFrameX())
			{
				_axe._index = 0;
			}
		}
		_axe._img->setFrameX(_axe._index);
		_axe._atkrc = RectMakeCenter(0, 0, 0, 0);
		_axe._rc = RectMakeCenter(0, 0, 0, 0);

		break;
	}

	//_axe._atkrc = RectMakeCenter(0, 0, 0, 0);
	//_axe._rc = RectMakeCenter(0, 0, 0, 0);
}

void tool::pickaxemove(int _x, int _y, TOOLTYPE _ttype, TOOLMOVE _move)
{
	_pickaxe.x = _x;
	_pickaxe.y = _y;
	_pickaxe._tm = _move;
	_pickaxe._type = _ttype;
	_pickaxe._rc = RectMakeCenter(_x, _y, _pickaxe._img->getFrameWidth(), _pickaxe._img->getFrameHeight());

	switch (_move)
	{
	case TT_DOWN:
		_pickaxe._count++;
		_pickaxe._img->setFrameY(0);
		if (_pickaxe._count % 5 == 0)
		{
			_pickaxe._count = 0;
			_pickaxe._index++;
			if (_pickaxe._index >= _pickaxe._img->getMaxFrameX())
			{
				_pickaxe._index = 0;
			}
		}
		_pickaxe._img->setFrameX(_pickaxe._index);
		_pickaxe._rc = RectMakeCenter(PLAYER->getintplayerX(), PLAYER->getintplayerY() + 50, 50, 50);
		break;
	case TT_RIGHT:
		_pickaxe._count++;
		_pickaxe._img->setFrameY(1);
		if (_pickaxe._count % 5 == 0)
		{
			_pickaxe._count = 0;
			_pickaxe._index++;
			if (_pickaxe._index >= _pickaxe._img->getMaxFrameX())
			{
				_pickaxe._index = 0;
			}
		}
		_pickaxe._img->setFrameX(_pickaxe._index);
		_pickaxe._rc = RectMakeCenter(PLAYER->getintplayerX() + 25, PLAYER->getintplayerY() - 20, 50, 50);
		break;
	case TT_LEFT:
		_pickaxe._count++;
		_pickaxe._img->setFrameY(2);
		if (_pickaxe._count % 5 == 0)
		{
			_pickaxe._count = 0;
			_pickaxe._index++;
			if (_pickaxe._index >= _pickaxe._img->getMaxFrameX())
			{
				_pickaxe._index = 0;
			}
		}
		_pickaxe._img->setFrameX(_pickaxe._index);
		_pickaxe._rc = RectMakeCenter(PLAYER->getintplayerX() - 25, PLAYER->getintplayerY() - 20, 50, 50);

		break;
	case TT_UP:
		_pickaxe._count++;
		_pickaxe._img->setFrameY(3);
		if (_pickaxe._count % 5 == 0)
		{
			_pickaxe._count = 0;
			_pickaxe._index++;
			if (_pickaxe._index >= _pickaxe._img->getMaxFrameX())
			{
				_pickaxe._index = 0;
			}
		}
		_pickaxe._img->setFrameX(_pickaxe._index);

		break;
	case TT_NONE:
		_pickaxe._count++;
		_pickaxe._img->setFrameY(4);
		if (_pickaxe._count % 5 == 0)
		{
			_pickaxe._count = 0;
			_pickaxe._index++;
			if (_pickaxe._index >= _pickaxe._img->getMaxFrameX())
			{
				_pickaxe._index = 0;
			}
		}
		_pickaxe._img->setFrameX(_pickaxe._index);
		_pickaxe._rc = RectMakeCenter(-50, -50, 0, 0);
		break;
	
	}
}

void tool::homemove(int _x, int _y, TOOLTYPE _ttype, TOOLMOVE _move)
{
	_hoe.x = _x;
	_hoe.y = _y;
	_hoe._tm = _move;
	_hoe._type = _ttype;
	_hoe._rc = RectMakeCenter(_x, _y, _hoe._img->getFrameWidth(), _hoe._img->getFrameHeight());

	switch (_move)
	{
	case TT_DOWN:
		_hoe._count++;
		_hoe._img->setFrameY(0);
		if (_hoe._count % 5 == 0)
		{
			_hoe._count = 0;
			_hoe._index++;
			if (_hoe._index >= _hoe._img->getMaxFrameX())
			{
				_hoe._index = 0;
			}
		}
		_hoe._img->setFrameX(_hoe._index);
		_hoe._rc = RectMakeCenter(PLAYER->getintplayerX(), PLAYER->getintplayerY(), 50, 50);
		break;
	case TT_RIGHT:
		_hoe._count++;
		_hoe._img->setFrameY(1);
		if (_hoe._count % 5 == 0)
		{
			_hoe._count = 0;
			_hoe._index++;
			if (_hoe._index >= _hoe._img->getMaxFrameX())
			{
				_hoe._index = 0;
			}
		}
		_hoe._img->setFrameX(_hoe._index);
		_hoe._rc = RectMakeCenter(PLAYER->getintplayerX() + 25, PLAYER->getintplayerY() - 20, 50, 50);
		break;
	case TT_LEFT:
		_hoe._count++;
		_hoe._img->setFrameY(2);
		if (_hoe._count % 5 == 0)
		{
			_hoe._count = 0;
			_hoe._index++;
			if (_hoe._index >= _hoe._img->getMaxFrameX())
			{
				_hoe._index = 0;
			}
		}
		_hoe._img->setFrameX(_hoe._index);
		_hoe._rc = RectMakeCenter(PLAYER->getintplayerX() - 25, PLAYER->getintplayerY() - 20, 50, 50);

		break;
	case TT_UP:
		_hoe._count++;
		_hoe._img->setFrameY(3);
		if (_hoe._count % 5 == 0)
		{
			_hoe._count = 0;
			_hoe._index++;
			if (_hoe._index >= _hoe._img->getMaxFrameX())
			{
				_hoe._index = 0;
			}
		}
		_hoe._img->setFrameX(_hoe._index);

		break;
	case TT_NONE:
		_hoe._count++;
		_hoe._img->setFrameY(4);
		if (_hoe._count % 5 == 0)
		{
			_hoe._count = 0;
			_hoe._index++;
			if (_hoe._index >= _hoe._img->getMaxFrameX())
			{
				_hoe._index = 0;
			}
		}
		_hoe._img->setFrameX(_hoe._index);
		_hoe._rc = RectMakeCenter(-50, -50, 0, 0);
		break;

	}
}

void tool::render()
{
		_axe._img->frameRender(getMemDC(), _axe._rc.left, _axe._rc.top);
		_pickaxe._img->frameRender(getMemDC(), _pickaxe._rc.left, _pickaxe._rc.top);
		_hoe._img->frameRender(getMemDC(), _hoe._rc.left, _hoe._rc.top);
	if (KEYMANAGER->isToggleKey('L'))
	{
		Rectangle(getMemDC(), _axe._rc.left, _axe._rc.top, _axe._rc.right, _axe._rc.bottom);
		Rectangle(getMemDC(), _pickaxe._rc.left, _pickaxe._rc.top, _pickaxe._rc.right, _pickaxe._rc.bottom);

	}

}
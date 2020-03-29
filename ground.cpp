#include "stdafx.h"
#include "ground.h"

ground::ground()
{
}

ground::~ground()
{
}

HRESULT ground::init(const char * groundname,POINT position ,STATE_GROUND stateground, bool isact)
{
	_tile.count = 0; 
	_tile.index = 0;
	_tile._img = IMAGEMANAGER->findImage(groundname);
	_tile._state_ground = stateground;
	_tile._rc = RectMakeCenter(position.x, position.y, _tile._img->getWidth(), _tile._img->getHeight());
	_tile._isact = isact;

	return S_OK;
}

void ground::release()
{
}

void ground::update()
{
	move();
}

void ground::move()
{
	if (_tile._state_ground == ITEM_GROUND)
	{
		_tile.count++;
		_tile._img->setFrameY(0);
		if (_tile.count % 5 == 0)
		{
			_tile.count = 0; 
			_tile.index++;
			if (_tile.index >= _tile._img->getMaxFrameX())
			{
				_tile.index = 6;
			}
		}
		_tile._img->setFrameX(_tile.index);
	}
}


void ground::render()
{
	_tile._img->render(getMemDC(), _tile._rc.left, _tile._rc.top);
	if (_tile._state_ground == ITEM_GROUND)
	{
		_tile._img->frameRender(getMemDC(), _tile._rc.left, _tile._rc.top);
	}
}


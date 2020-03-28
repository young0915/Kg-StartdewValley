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
}

void ground::render()
{
}

#include "stdafx.h"
#include "vegetablemanager.h"

vegetablemanager::vegetablemanager()
{
}

vegetablemanager::~vegetablemanager()
{
}

HRESULT vegetablemanager::init()
{
	this->setpotato();
	_item = ITEMMANAGER->additem("°¨ÀÚ");
	return S_OK;
}

void vegetablemanager::release(){}

void vegetablemanager::update(vector<item> &item)
{

	for (int i = 0; i < _vegeta.size(); i++)
	{
		if (_vegeta[i]->getstateveg() == GROWING)
		{
			for (_itervegeta = _vegeta.begin(); _itervegeta != _vegeta.end(); ++_itervegeta)
			{
				(*_itervegeta)->update();
			}
			
		}
	}
	collisiongrow();
}

void vegetablemanager::render()
{
	for (_itervegeta = _vegeta.begin(); _itervegeta != _vegeta.end(); ++_itervegeta)
	{
		(*_itervegeta)->render();
	}
}

void vegetablemanager::setpotato()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j ++)
		{
			vegetable* _potato;
			_potato = new potato;
			_potato->init("°¨ÀÚ³óÀå", PointMake(575 + i *51, 575 + j * 51), NOT_GROW, false);
			//_potato->init("°¨ÀÚ³óÀå", PointMake(575 , 575), NOT_GROW, false);
			_vegeta.push_back(_potato);
			_item = ITEMMANAGER->additem("°¨ÀÚ");
		
		}
		break;
	}
}

void vegetablemanager::collisiongrow()
{
	for (int i = 0; i < _vegeta.size(); i++)
	{
		if (_vegeta[i]->getstateveg() == NOT_GROW)
		{
			RECT temp;
			//¶¥¿¡ ´êÀ¸¸é 
			if (IntersectRect(&temp, &_vegeta[i]->getrect(), &PLAYER->getSeed()))
			{
				_vegeta[i]->setstateveg(GROWING);
			}
		}
		break;
	}

}



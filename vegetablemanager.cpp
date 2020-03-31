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
	return S_OK;
}

void vegetablemanager::release() {}

void vegetablemanager::update(vector<item> &item)
{
		collisiongrow();
		
	
		for (int i = 0; i < _vegeta.size(); i++)
		{
			if (_vegeta[i]->getstateveg() == GROWING)
			{
				for (_itervegeta = _vegeta.begin(); _itervegeta != _vegeta.end(); ++_itervegeta)
				{
						(*_itervegeta)->update();
				}
				time = TIMEMANAGER->getWorldTime();
				if (TIMEMANAGER->getWorldTime() - time >= 0.9f)
				{
					_vegeta[i]->setstateveg(PICK);
				}
			}
			if (_vegeta[i]->getstateveg() == PICK)
			{
				_item = _vegeta[i]->getitem();
				_dropimg = _item.getItemInfo()._img;
				_item.setRect(RectMakeCenter(_vegeta[i]->getrect().right - ((_vegeta[i]->getrect().right - _vegeta[i]->getrect().left) / 2),
					(_vegeta[i]->getrect().bottom - (_vegeta[i]->getrect().bottom - _vegeta[i]->getrect().top) / 2), _item.getItemInfo()._img->getWidth(),
					_item.getItemInfo()._img->getHeight()));
				_item.setMove(true);
				item.push_back(_item);
				removepotato(i);
				break;
			}

		}
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
			for (int j = 0; j < 2; j++)
			{
				vegetable* _potato;
				_potato = new potato;
				_potato->init("°¨ÀÚ³óÀå", PointMake(575 + i * 51, 575 + j * 51), NOT_GROW, false);
				_vegeta.push_back(_potato);
			break;
			}
		}
	}

	void vegetablemanager::collisiongrow()
	{
		for (int i = 0; i < _vegeta.size(); i++)
		{
			RECT temp;
			if (_vegeta[i]->getstateveg() == NOT_GROW)
			{
				//¶¥¿¡ ´êÀ¸¸é 
				if (IntersectRect(&temp, &_vegeta[i]->getrect(), &PLAYER->getSeed()))
				{
					_vegeta[i]->setstateveg(GROWING);
				
				}
			}
			//break;
		}
	}

	void vegetablemanager::removepotato(int num)
	{
		_vegeta.erase(_vegeta.begin() + num);
	}



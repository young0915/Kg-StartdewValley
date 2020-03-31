#include "stdafx.h"
#include "Monstermanager.h"

Monstermanager::Monstermanager() {}

Monstermanager::~Monstermanager() {}



HRESULT Monstermanager::init()
{
	this->setcrab();
	return S_OK;
}
void Monstermanager::release() {}
void Monstermanager::update(vector<item> _item)
{
	for (_vitermonser = _vmonster.begin(); _vitermonser != _vmonster.end(); ++_vitermonser)
	{
		(*_vitermonser)->update();
	}
	for (int i = 0; i < _vmonster.size(); i++)
	{
		if (_vmonster[i]->getmove() == MONSTER_DIE)
		{
			_dropitem = _vmonster[i]->getitem();
			_itemimg = _dropitem.getItemInfo()._img;

			_dropitem.setRect(RectMakeCenter(_vmonster[i]->getRect().right - ((_vmonster[i]->getRect().right - _vmonster[i]->getRect().left) / 2),
				(_vmonster[i]->getRect().bottom - (_vmonster[i]->getRect().bottom - _vmonster[i]->getRect().top) / 2), _dropitem.getItemInfo()._img->getWidth(),
				_dropitem.getItemInfo()._img->getHeight()));
			_dropitem.setMove(true);
			_item.push_back(_dropitem);
			monsterremove(i);
		}
	}
	acessmonster();
	attackmonster();
	monstercollisionwall();
}

void Monstermanager::monsterremove(int num)
{
	_vmonster.erase(_vmonster.begin() + num);
}

void Monstermanager::monstercollisionwall()
{
	for (int i = 0; i < _vmonster.size(); i++)
	{
		if (_vmonster[i]->getmove() == MONSTER_MOVE)
		{
			atkcount = RND->getFromIntTo(0, 4);
			if (atkcount == 0)
			{
				test++;
				if (test == 20)
				{
				_vmonster[i]->setdriection(M_RIGHT);
				}
			}
			if (atkcount == 1)
			{
					_vmonster[i]->setdriection(M_LEFT);
				}
			if (atkcount == 2)
			{
				_vmonster[i]->setdriection(M_DOWN);
			}
			if (atkcount == 3)
			{
				_vmonster[i]->setdriection(M_UP);
			}
			if (atkcount == 4)
			{
				_vmonster[i]->setdriection(M_STOP);
			}
		}
	}

}

void Monstermanager::setcrab()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			monster* _crab;
			_crab = new crab;
			_crab->init("꽃게", PointMake(600 + i * 400, 600 + j * 400), M_STOP, MONSTER_IDLE, false);
			_vmonster.push_back(_crab);
		}
	}
}

//몬스터가 나에게 접근하는 함수
void Monstermanager::acessmonster()
{
	for (int i = 0; i < _vmonster.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_vmonster[i]->getatckrange(), &PLAYER->getPlayerrect()))
		{
			_vmonster[i]->setismove(true);
			_vmonster[i]->setmove(MONSTER_MOVE);
			break;
		}
	}
}

void Monstermanager::attackmonster()
{
	for (int i = 0; i < _vmonster.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_vmonster[i]->getRect(), &PLAYER->getweapon()))
		{
			if (_vmonster[i]->getmove() == MONSTER_MOVE);
			{
				_vmonster[i]->setmove(MONSTER_DIE);
				break;
			}
		}
		RECT playertemp;
		if (IntersectRect(&playertemp, &_vmonster[i]->getRect(), &PLAYER->getPlayerrect()))
		{
			PLAYER->setEnergy(PLAYER->getEnergy() + 0.5f);
			PLAYER->setHp(PLAYER->getHp() + 1);
			break;
		}
	}
}



void Monstermanager::render()
{
	for (_vitermonser = _vmonster.begin(); _vitermonser != _vmonster.end(); ++_vitermonser)
	{
		(*_vitermonser)->render();
	}
	char str[128];

	sprintf_s(str, "%d", atkcount);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));



}
#include "stdafx.h"
#include "othermanager.h"

othermanager::othermanager()
{
}

othermanager::~othermanager()
{
}
//집
HRESULT othermanager::init()
{
	this->setStone();

	return S_OK;
}
//동굴
HRESULT othermanager::init1()
{
	this->setruby();
	return S_OK;
}

void othermanager::release() {}

void othermanager::update(vector<item>& item)
{
	for (_viterstone; _viterstone != _vstone.end(); ++_viterstone)
	{
		(*_viterstone)->update();
	}

	for (int i = 0; i < _vstone.size(); i++)
	{
		if (_vstone[i]->getstate() == STONE_MASH)
		{
			_dropitem = _vstone[i]->getitem();
			itemimg = _dropitem.getItemInfo()._img;

			_dropitem.setRect(RectMakeCenter(_vstone[i]->getstonerc().right - ((_vstone[i]->getstonerc().right - _vstone[i]->getstonerc().left) / 2),
			(_vstone[i]->getstonerc().bottom - (_vstone[i]->getstonerc().bottom - _vstone[i]->getstonerc().top) / 2), _dropitem.getItemInfo()._img->getWidth(),
			_dropitem.getItemInfo()._img->getHeight()));

			_dropitem.setMove(true);
			item.push_back(_dropitem);
			removestone(i);
		}
	}
	collisionstone();
}

void othermanager::render()
{
	for (_viterstone = _vstone.begin(); _viterstone != _vstone.end(); ++_viterstone)
	{
		(*_viterstone)->render();
	}
}

void othermanager::removestone(int num)
{
	_vstone.erase(_vstone.begin() + num);
}

void othermanager::setStone()
{
	for (int i = 0; i < 2; i++)
	{
		stone* _stone;
		_stone = new itemstone;
		_stone->init("돌맹이", ETC_STONE, STONE_IDLE, PointMake(350 + i * 250, 650 + i * 50), 4);
		_vstone.push_back(_stone);
	}
	for (int i = 0; i < 2; i++)
	{
		stone* _grass;
		_grass = new grass;
		_grass->init("잔디", GRASS_TYPE, STONE_IDLE, PointMake(450 + i * 150, 650 + i * 100), 2);
		_vstone.push_back(_grass);
	}
	stone* _tree;
	_tree = new tree;
	_tree->init("나무2", TREE_TYPE, STONE_IDLE, PointMake(550, 500), 1);
	_vstone.push_back(_tree);



}

void othermanager::setruby()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			stone* _ruby;
			_ruby = new ruby;
			_ruby->init("루비돌", RUBY_STONE, STONE_IDLE, PointMake(600+j*400, 600 + i * 400), 3);
			_vstone.push_back(_ruby);
		}
	}
}

void othermanager::collisionstone()
{
	for (int i = 0; i < _vstone.size(); i++)
	{
		RECT temp;

		if (IntersectRect(&temp, &_vstone[i]->getstonerc(), &PLAYER->getTool()->getaxe()))
		{
			//상태가 돌이면 
			if (_vstone[i]->gettype() == GRASS_TYPE || _vstone[i]->gettype() == TREE_TYPE)
			{
				atkcount++;
				if (atkcount != 50)
				{
					PLAYER->setHp(PLAYER->getHp() + 0.5f);
				}
				else
				{
					_vstone[i]->setstate(STONE_MASH);
					atkcount = 0;																	//다시 초기화
				}
			}
		}
		//루비
		RECT etc;
		if (IntersectRect(&etc, &_vstone[i]->getstonerc(), &PLAYER->getTool()->getpickaxe()))
		{
			if (_vstone[i]->gettype() == RUBY_STONE || _vstone[i]->gettype() == ETC_STONE)
			{
				atkcount++;
				if (atkcount != 50)
				{
					PLAYER->setHp(PLAYER->getHp() + 1);
					PLAYER->setEnergy(PLAYER->getEnergy() + 1);
				}
				else
				{
					_vstone[i]->setstate(STONE_MASH);
					atkcount = 0;																	//다시 초기화
				}
			}
		}
	}
}

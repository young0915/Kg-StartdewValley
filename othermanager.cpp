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

void othermanager::release(){}

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
			// 아이템 만드는 코드..
			// Item item = new Item;
			// item->init();
			// 벡터.push_back(item);
			
			_dropitem = _vstone[i]->getitem();
			itemimg = _dropitem.getItemInfo()._img;
	_dropitem.setRect(RectMakeCenter(_vstone[i]->getstonerc().right -((_vstone[i]->getstonerc().right -_vstone[i]->getstonerc().left)/2) ,
				(_vstone[i]->getstonerc().bottom-(_vstone[i]->getstonerc().bottom - _vstone[i]->getstonerc().top))
				, _dropitem.getItemInfo()._img->getWidth(), _dropitem.getItemInfo()._img ->getHeight()));
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
	
	if (KEYMANAGER->isToggleKey('O'))
	{
		char str[128];
		sprintf_s(str, "%d", atkcount);
		TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));

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
		_stone->init("돌맹이", ETC_STONE, STONE_IDLE, PointMake(350 + i * 250, 650+i*50), 4);
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
	for (int i = 0; i < 5; i++)
	{
		stone* _ruby;
		_ruby = new ruby;
		_ruby->init("루비돌", RUBY_STONE, STONE_IDLE, PointMake(350, 350 + i * 200), 3);
		_vstone.push_back(_ruby);
	}
}

void othermanager::collisionstone()
{
	for (int i = 0; i < _vstone.size(); i++)
	{
		RECT temp;

			if (IntersectRect(&temp, &_vstone[i]->getstonerc(), &PLAYER->getweapon()))
			{

				//상태가 돌이면 
				if (_vstone[i]->gettype() == ETC_STONE || _vstone[i]->gettype() == GRASS_TYPE || _vstone[i]->gettype() == TREE_TYPE)
				{
					atkcount++;
					if (atkcount != 100)
					{
						PLAYER->setHp(PLAYER->getHp() + 0.5f);
					}
					else
					{
						_vstone[i]->setstate(STONE_MASH);
						atkcount = 0;																	//다시 초기화
					}
				}
				//루비
				if(_vstone[i]->gettype() == RUBY_STONE)
				{
					
				}
			}

	}

}

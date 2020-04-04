#include "stdafx.h"
#include "groundManager.h"

groundManager::groundManager(){}

groundManager::~groundManager(){}

HRESULT groundManager::init()
{
	this->setwetground();
	this->sethoeground();
	this->setjustground();

	return S_OK;
}
void groundManager::update()
{
	for (_viterground = _vground.begin(); _viterground != _vground.end(); ++_viterground)
	{
		(*_viterground)->update();
	}
	for (int i = 0; i < _vground.size(); i++)
	{
		if (_vground[i]->getsateground() == JUST_GROUND)
		{
			collision();
		}
	}
}

void groundManager::release(){}
void groundManager::render()
{
	for (_viterground = _vground.begin(); _viterground != _vground.end(); ++_viterground)
	{
		(*_viterground)->render();
	}
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < _vground.size(); i++)
		{
			Rectangle(getMemDC(), _vground[i]->getgroundrect().left, _vground[i]->getgroundrect().top, _vground[i]->getgroundrect().right, _vground[i]->getgroundrect().bottom);
		}
	}

}
//타일을 지워주는 함수
void groundManager::removetile(int num)
{
	//그냥 땅과 으깬땅에만 적용
			_vground.erase(_vground.begin() + num);
}

void groundManager::setjustground()
{
	// y축으로 3개
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ground* _justground;
			_justground = new justground;
			_justground->init("비어진 땅", PointMake(575 + i * 52, 575 + j * 52), JUST_GROUND, false);
			_vground.push_back(_justground);
		}
	}

}

void groundManager::sethoeground()
{
	// y축으로 3개
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ground* _hoeground;
			_hoeground = new hoeground;
			_hoeground->init("호미타일", PointMake(575 + i * 52, 575 + j * 52), MASH_GROUND, false);
			_vground.push_back(_hoeground);
		}
	}
	
}


void groundManager::setwetground()
{
	// y축으로 3개
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ground* _wetground;
			_wetground = new justground;
			_wetground->init("물뿌리개타일", PointMake(575 + i * 52, 575 + j * 52), WET_GROUND, false);
			_vground.push_back(_wetground);
		}
	}
}
void groundManager::collision()
{
	//true전환, MASH_GROUND->전환
	for (int i = 0; i < _vground.size(); i++)
	{
		RECT temp;
		//호미질
		if (IntersectRect(&temp, &_vground[i]->getgroundrect(), &PLAYER->getTool()->gethoe()))
		{
			if (_vground[i]->getsateground() == JUST_GROUND)
			{
				PLAYER->setEnergy(PLAYER->getEnergy() + 1.f);
				removetile(i);
			}
		}
		RECT waterTemp;
		if (IntersectRect(&waterTemp, &_vground[i]->getgroundrect(), &PLAYER->getweapon()))
		{
			if (_vground[i]->getsateground() == MASH_GROUND)
			{
				removetile(i);
			}
		}
		//씨앗을 뿌렸을 때
		//RECT seedTemp;
		//if (IntersectRect(&seedTemp, &_vground[i]->getgroundrect(), &PLAYER->getSeed()))
		//{
		//	if (_vground[i]->getsateground() == WET_GROUND)
		//	{
		//	//	_vground[i]->setstateground(ITEM_GROUND);										//아이템 생성 이거 어떻게 설정할 지 에휴
		//	}
		//}
	}
	
}

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
//Ÿ���� �����ִ� �Լ�
void groundManager::removetile(int num)
{
	//�׳� ���� ���������� ����
			_vground.erase(_vground.begin() + num);
}

void groundManager::setjustground()
{
	// y������ 3��
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ground* _justground;
			_justground = new justground;
			_justground->init("����� ��", PointMake(575 + i * 52, 575 + j * 52), JUST_GROUND, false);
			_vground.push_back(_justground);
		}
	}

}

void groundManager::sethoeground()
{
	// y������ 3��
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ground* _hoeground;
			_hoeground = new hoeground;
			_hoeground->init("ȣ��Ÿ��", PointMake(575 + i * 52, 575 + j * 52), MASH_GROUND, false);
			_vground.push_back(_hoeground);
		}
	}
	
}


void groundManager::setwetground()
{
	// y������ 3��
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ground* _wetground;
			_wetground = new justground;
			_wetground->init("���Ѹ���Ÿ��", PointMake(575 + i * 52, 575 + j * 52), WET_GROUND, false);
			_vground.push_back(_wetground);
		}
	}
}
void groundManager::collision()
{
	//true��ȯ, MASH_GROUND->��ȯ
	for (int i = 0; i < _vground.size(); i++)
	{
		RECT temp;
		//ȣ����
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
		//������ �ѷ��� ��
		//RECT seedTemp;
		//if (IntersectRect(&seedTemp, &_vground[i]->getgroundrect(), &PLAYER->getSeed()))
		//{
		//	if (_vground[i]->getsateground() == WET_GROUND)
		//	{
		//	//	_vground[i]->setstateground(ITEM_GROUND);										//������ ���� �̰� ��� ������ �� ����
		//	}
		//}
	}
	
}

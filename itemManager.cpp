#include "stdafx.h"
#include "itemManager.h"

itemManager::itemManager(){}

itemManager::~itemManager(){}

HRESULT itemManager::init()
{
	//�̸�, Ÿ��, ����, �÷��̾� ���� �� ��,  ������, hp, ����,�ִ밹��
	_item.init("�������", ITEM_EMPTY, 0, 0, 0, 0, 0, 0);
	_vItem.push_back(_item);

	_item.init("����", ITEM_SWORD, 5000, 2500, 0, -3,  1, 1);
	_vItem.push_back(_item);

	_item.init("���Ѹ���", ITEM_SWORD, 1000, 500, 0, -4,  1, 1);
	_vItem.push_back(_item);

	_item.init("����", ITEM_ETC, 0, 100, 0, 0, 0, 5);
	_vItem.push_back(_item);

	_item.init("��", ITEM_ETC, 0, 100, 0, -6, 0, 5);
	_vItem.push_back(_item);

	_item.init("����", ITEM_ETC, 0, 500, 0, -3, 0, 5);
	_vItem.push_back(_item);

	_item.init("����", ITEM_ETC, 0, 250, 0, 0, 0, 5);
	_vItem.push_back(_item);

	_item.init("����", ITEM_ETC, 0, 500, 23, 15, 0, 5);
	_vItem.push_back(_item);

	_item.init("�Ĵս� ����", ITEM_ETC, 500, 250, 0, 0, 0, 5);
	_vItem.push_back(_item);

	_item.init("������", ITEM_ETC, 400, 200, 0,0, 0, 5);
	_vItem.push_back(_item);

	_item.init("�ݸ��ö�� ����", ITEM_ETC, 100, 50, 0,0, 0, 5);
	_vItem.push_back(_item);

	_item.init("���� ����", ITEM_ETC, 300, 150, 0,0, 0, 5);
	_vItem.push_back(_item);

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	_viItem = _vItem.begin();
	for (_viItem; _viItem != _vItem.end; ++_viItem)
	{
		(*_viItem).update();
	}
}

void itemManager::render(HDC hdc)
{
	_viItem = _vItem.begin();
	for (_viItem; _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem).render(hdc);
	}
}

item itemManager::additem(string itemName)
{
	_viItem = _vItem.begin();
	for (_viItem; _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->getItemInfo().itemName == itemName)
		{
			return (*_viItem);
		}
	}
}

item itemManager::additem(string itemName, int CntNum)
{
	_viItem = _vItem.begin();
	for (_viItem; _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->getItemInfo().itemName == itemName)
		{
			return (*_viItem);
			break;
		}
	}

}

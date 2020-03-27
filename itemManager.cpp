#include "stdafx.h"
#include "itemManager.h"

itemManager::itemManager(){}

itemManager::~itemManager(){}

HRESULT itemManager::init()
{
	// init(const char* name, itemType type, int price, int shareprice, int hp,int energy, int maxCnt);							//아이템 초기화
	//인벤토리의 상태를 알리기 위해서 
	_item.init("비어있음", ITEM_EMPTY, 0, 0, 0, 0, 0);
	_vItem.push_back(_item);

	//농장 아이템 
	_item.init("감자", ITEM_ETC, 500, 250, 15, 13, 10);
	_vItem.push_back(_item);
	//상점에 판는 아이템
	_item.init("감자씨앗", ITEM_ETC, 250, 50, 0, 0, 5);
	_vItem.push_back(_item);
	_item.init("콜리플라워 씨앗", ITEM_ETC, 100, 50, 0, 0, 5);
	_vItem.push_back(_item);
	_item.init("콩종자", ITEM_ETC, 400, 200, 0, 0, 5);
	_vItem.push_back(_item);
	_item.init("피닙스 씨앗", ITEM_ETC, 600, 300, 0, 0, 5);
	_vItem.push_back(_item);

	//동굴
	_item.init("루비", ITEM_ETC, 1000, 500, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("게", ITEM_ETC, 500, 0, 0, 0, 010);
	_vItem.push_back(_item);
	_item.init("박쥐", ITEM_ETC, 100, 50, 0, 0, 10);
	_vItem.push_back(_item);

	//기타
	_item.init("나무", ITEM_ETC, 100, 100, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("돌", ITEM_ETC, 10, 5, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("잡초", ITEM_ETC, 10, 5, 0, 0, 10);
	_vItem.push_back(_item);

	//무기
	_item.init("흑요소", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("물뿌리개(아이템)", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("곡괭이(아이템)", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("도끼(아이템)", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("호미(아이템)", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);

	return S_OK;
}

void itemManager::release(){}

void itemManager::update()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem).update();
	}
}

void itemManager::render(HDC hdc)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem).render(hdc);
	}
}
void itemManager::inrender(HDC hdc, int destX, int destY)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem).inrender(hdc, destX, destY);
	}
}

item itemManager::additem(string itemName)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->getItemInfo().itemName == itemName)
		{
			return (*_viItem);
		}
	}
}

item itemManager::additem(string itemName, int CntNum)
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->getItemInfo().itemName == itemName)
		{
			return (*_viItem);
			break;
		}
	}
}

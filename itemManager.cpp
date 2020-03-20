#include "stdafx.h"
#include "itemManager.h"

itemManager::itemManager(){}

itemManager::~itemManager(){}

HRESULT itemManager::init()
{
	// init(const char* name, itemType type, int price, int shareprice, int hp,int energy, int maxCnt);							//¾ÆÀÌÅÛ ÃÊ±âÈ­
	//ÀÎº¥Åä¸®ÀÇ »óÅÂ¸¦ ¾Ë¸®±â À§ÇØ¼­ 
	_item.init("ºñ¾îÀÖÀ½", ITEM_EMPTY, 0, 0, 0, 0, 0);
	_vItem.push_back(_item);

	//³óÀå ¾ÆÀÌÅÛ 
	_item.init("°¨ÀÚ", ITEM_ETC, 500, 250, 15, 13, 10);
	_vItem.push_back(_item);
	//»óÁ¡¿¡ ÆÇ´Â ¾ÆÀÌÅÛ
	_item.init("°¨ÀÚ¾¾¾Ñ", ITEM_ETC, 250, 50, 0, 0, 5);
	_vItem.push_back(_item);
	_item.init("ÄÝ¸®ÇÃ¶ó¿ö ¾¾¾Ñ", ITEM_ETC, 100, 50, 0, 0, 5);
	_vItem.push_back(_item);
	_item.init("ÄáÁ¾ÀÚ", ITEM_ETC, 400, 200, 0, 0, 5);
	_vItem.push_back(_item);
	_item.init("ÇÇ´Õ½º ¾¾¾Ñ", ITEM_ETC, 600, 300, 0, 0, 5);

	//µ¿±¼
	_item.init("·çºñ", ITEM_ETC, 1000, 500, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("°Ô", ITEM_ETC, 500, 0, 0, 0, 010);
	_vItem.push_back(_item);
	_item.init("¹ÚÁã", ITEM_ETC, 100, 50, 0, 0, 10);
	_vItem.push_back(_item);

	//±âÅ¸
	_item.init("³ª¹«", ITEM_ETC, 100, 100, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("µ¹", ITEM_ETC, 10, 5, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("ÀâÃÊ", ITEM_ETC, 10, 5, 0, 0, 10);
	_vItem.push_back(_item);

	//¹«±â
	_item.init("Èæ¿ä¼Ò", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);
	_item.init("¹°»Ñ¸®°³(¾ÆÀÌÅÛ)", ITEM_SWORD, 10, 10, 0, 0, 10);
	_vItem.push_back(_item);


	return S_OK;
}

void itemManager::release()
{
}

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

//HRESULT itemManager::init()
//{
//	//ÀÌ¸§, Å¸ÀÔ, ¿ø°¡, ÇÃ·¹ÀÌ¾î µ·°¡ ÆÈ µ·,  ¿¡³ÊÁö, hp, °¹¼ö,ÃÖ´ë°¹¼ö
//	_item.init("ºñ¾îÀÖÀ½", ITEM_EMPTY, 0, 0, 0, 0, 0, 0);
//	_vItem.push_back(_item);
//
//	//µ¿±¼
//	_item.init("·çºñ", ITEM_ETC, 0, 5000, 0, 0, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("¹ÚÁã", ITEM_ETC, 0, 250, 0, 0, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("°Ô", ITEM_ETC, 0, 250, 0, 0, 0, 5);
//	//ÀÎº¥Åä¸®
//	_item.init("Èæ¿ä¼Ò", ITEM_SWORD, 5000, 2500, 0, -3,  1, 1);
//	_vItem.push_back(_item);
//
//	_item.init("¹°»Ñ¸®°³", ITEM_SWORD, 1000, 500, 0, -4,  1, 1);
//	_vItem.push_back(_item);
//	//Àâ 
//	_item.init("ÀâÃÊ", ITEM_ETC, 0, 100, 0, 0, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("µ¹", ITEM_ETC, 0, 100, 0, -6, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("³ª¹«", ITEM_ETC, 0, 500, 0, -3, 0, 5);
//	_vItem.push_back(_item);
//
//	//½Ä¹°
//	_item.init("°¨ÀÚ", ITEM_ETC, 0, 500, 23, 15, 0, 5);
//	_vItem.push_back(_item);
//
//	//»óÁ¡
//	_item.init("ÆÄ´Õ½º ¾¾¾Ñ", ITEM_ETC, 500, 250, 0, 0, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("ÄáÁ¾ÀÚ", ITEM_ETC, 400, 200, 0,0, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("ÄÝ¸®ÇÃ¶ó¿ö ¾¾¾Ñ", ITEM_ETC, 100, 50, 0,0, 0, 5);
//	_vItem.push_back(_item);
//
//	_item.init("°¨ÀÚ ¾¾¾Ñ", ITEM_ETC, 300, 150, 0,0, 0, 5);
//	_vItem.push_back(_item);
//
//	return S_OK;
//}
//
//void itemManager::release()
//{
//}
//
//void itemManager::update()
//{
//	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
//	{
//		(*_viItem).update();
//	}
//
//}
//
//void itemManager::render(HDC hdc)
//{
//	_viItem = _vItem.begin();
//	for (_viItem; _viItem != _vItem.end(); ++_viItem)
//	{
//		(*_viItem).render(hdc);
//	}
//}
//
//item itemManager::additem(string itemName)
//{
//	_viItem = _vItem.begin();
//	for (_viItem; _viItem != _vItem.end(); ++_viItem)
//	{
//		if (_viItem->getItemInfo().itemName == itemName)
//		{
//			return (*_viItem);
//		}
//	}
//}

//item itemManager::additem(string itemName, int CntNum)
//{
//	_viItem = _vItem.begin();
//	for (_viItem; _viItem != _vItem.end(); ++_viItem)
//	{
//		if (_viItem->getItemInfo().itemName == itemName)
//		{
//			return (*_viItem);
//			break;
//		}
//	}
//
//}

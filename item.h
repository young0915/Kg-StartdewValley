#pragma once

enum  itemType
{
	ITEM_EMPTY,
	ITEM_SWORD,				
	ITEM_ETC									//±âÅ¸
};

struct itemInfo
{
	image* _img;							//ÀÌ¹ÌÁö
	string itemName;						//ÀÌ¸§
	itemType type;							//¾ÆÀÌÅÛÀÇ Á¾·ù
	RECT rc;										//·¢Æ®

	bool move;							//¹Ù´Ú¿¡ ¶³¾îÁø ¾ÆÀÌÅÛÀÎÁö ¾Æ´ÑÁö
	int x, y;

	int Price;									//¿ø°¡
	int sharePrice;						//ÇÃ·¹ÀÌ¾î°¡ Á¤ÇÑ °¡°İ 
	int energy;								//¿¡³ÊÁö
	int hp;										//Ã¼·Â
	
	int cnt;									//°¹¼ö
	int maxCnt;							//ÀÎº¥Åä¸® 1Ä­ ´ç ­CÀç¼ÒÁö °¹¼ö
};
class item
{
private:
	itemInfo _item;

public :
	item();
	~item();

	HRESULT init(const char* name, itemType type, int price, int sharePrice, int energy, int hp, int cnt,int maxCnt);
	void release();
	void update();
	void render(HDC hdc);

	void magenet(POINT playerPoint);
	bool maxitem();

	itemInfo getItemInfo() { return _item; }									//¾ÆÀÌÅÛ Á¤º¸¸¦ °¡Á®¿È
	RECT getRect() { return _item.rc;  }											//¾ÆÀÌÅÛ ·ºÆ®¸¦ °¡Á®¿È
				
	void setItemCnt() { _item.cnt++;}												//°¹¼ö 1Áõ°¡ 
	void setItemCnt(int num) { _item.cnt += num; }						//°¹¼ö¸¦ num¸¸Å­ Áõ°¡
	void setItemCnt_equal(int num) { _item.cnt = num;  }			//°¹¼ö¸¦ numÀ¸·Î ¸¸µë

	//·ºÆ®ÀÇ À§Ä¡¸¦ ¼³Á¤ 
	void setRect(int x, int y) { _item.rc = RectMakeCenter(x, y, _item._img->getWidth(), _item._img->getHeight()); }
	void setRect(RECT rc) { _item.rc = rc; }

	//¾ÆÀÌÅÛÀÇ »óÅÂ¸¦ ¹Ù²ãÁÜ(ÀÎº¥¿¡ ÀÖÀ»¶§ false, ¹Ù´Ú¿¡ ¶³¾îÁ®ÀÖÀ»¶§ true)
	void setMove(bool move) { _item.move = move; }

	//ÇÃ·¹ÀÌ¾î°¡ ¾ÆÀÌÅÛ °¢°ÜÀ» Á¤ÇÒ ¶§ ¾²´Â ÇÔ¼ö 
	void setPlayerPrice(int price) { _item.sharePrice = price; }
};

/*
¾ÆÀÌÅÛ ¸Å´ÏÀú
Èæ¿ä¼Ò(°Ë)
¹°»Ñ¸®°³
ÀâÃÊ
µ¹
³ª¹«
´ÙÀÌ¾Æ¸óµå
¹ÚÁã ¾ÆÀÌÅÛ
°¨ÀÚ

»óÁ¡
ÆÄ½º´Õ ¾¾¾Ñ
ÄáÁ¾ÀÚ
Äİ¸®ÇÃ¶ó¿ö ¾¾¾Ñ
°¨ÀÚ ¾¾¾Ñ

*/
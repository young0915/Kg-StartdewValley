#pragma once

enum  itemType
{
	ITEM_EMPTY,
	ITEM_SWORD,				
	ITEM_ETC									//╠Бе╦
};

struct itemInfo
{
	image* _img;							//юл╧лаЖ
	string itemName;						//юл╦╖
	itemType _type;							//╬фюлешюг а╬╥Ы
	RECT rc;										//╥╒ф╝

	bool move;							//╧ы╢з©║ ╤Ё╬НаЬ ╬фюлешюнаЖ ╬ф╢яаЖ
	int _x, _y;

	int _Price;									//©Ь╟║
	int _sharePrice;						//гц╥╧юл╬Н╟║ а╓гя ╟║╟щ 
	int _energy;								//©║ЁйаЖ
	int _hp;										//ц╪╥б
	
	int _cnt;									//╟╧╪Ж
	int _maxCnt;							//юн╨╔еД╦╝ 1д╜ ╢Г ╜CюГ╪раЖ ╟╧╪Ж
};
class item 
{
private:
	itemInfo _item;

public:
	item();
	~item();

	HRESULT init(const char* name, itemType type, int price, int shareprice, int hp,int energy, int maxCnt);							//╬фюлеш цй╠Бх╜
	void release();
	void update();
	void render();
	void render(HDC hdc);
	void inrender(HDC hdc, int x, int y);

	void magenet(POINT _playerPoint);																			//╬фюлеш юл гц╥╧юл╬Н©║╟т ╡Ь╬Н╢Г╠Б╣╣╥о го╠Б
	bool maxitem();


	itemInfo getItemInfo() { return _item; }																		//╬фюлеш а╓╨╦╦╕ ╟║а╝©х
	RECT getRect() { return  _item.rc; }																				//╬фюлеш ╥╒ф╝ ╟║а╝©х

	void setItem() { _item._cnt++; }																						//╟╧╪Ж╦╕ num╦╦е╜ аУ╟║
	void setItemCnt(int num) { _item._cnt += num; }														//╟╧╪Ж╦╕ numю╦╥н ╦╦╣К
	void setItemCnt_equal(int num) { _item._cnt = num; }

	//╥╒ф╝юг ю╖д║ ╪Ёа╓
	void setRect(int x, int y) { _item.rc = RectMakeCenter(_item._x, _item._y, _item._img->getWidth(), _item._img->getHeight()); }
	void setRect(RECT _rc) { _item.rc = _rc; }

	//╬фюлеш ╩Себ╦╕ ╧ы╡ыаэюн╨╔©║ южю╩ ╤╖ false, ╧ы╢з©║ ╤Ё╬На╝ южю╩ ╤╖ true
	void setMove(bool _move) { _item.move = _move; }


	//гц╥╧юл╬Н╟║ ╬фюлеш ╟║╟щю╩ а╓гр ╤╖ ╬╡╢б гт╪Ж 
	void setPlayerPrice(int price) { _item._Price = price; }





};

/*
╬фюлеш ╦е╢оюЗ
хФ©Д╪р(╟к)
╧╟╩я╦╝╟Ё
юБцй
╣╧
Ё╙╧╚
╢ыюл╬ф╦С╣Е
╧заЦ ╬фюлеш
╟╗юз

╩Са║
фд╫╨╢у ╬╬╬я
дАа╬юз
дщ╦╝гц╤С©Ж ╬╬╬я
╟╗юз ╬╬╬я

*/
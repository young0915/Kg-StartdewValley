#pragma once
#include"gameNode.h"
#include "tileManager.h"

struct shopmain
{
	image* _img;
	RECT rc;
	float x, y;
	bool _isopen;
};

struct shop
{
	image* _img;
	RECT _rc;
	item _item;
	int x, y;
};

struct tagCarpet
{
	image* _img;
	RECT _rc;
	int x, y;
};

class shopscene :public gameNode
{
private:
	shopmain _shopmain;
	shop _shop;
	tagCarpet  _carpet;
	vector<shop> _vshop;
	vector<shop>::iterator _vitershop;


	POINT _shoppoimt;

	RECT _gotown;
	RECT _gotowntwinkle;
	image* _twinkle;
	bool istwinkel;
	int i;
public :
	shopscene();
	~shopscene();

	HRESULT init();
	void rlease();
	void update();
	void itemSetup();
	void sellitem();
	
	//void sellitem(int &gold, shop _item);
	//void additem(shop item);
	
	void test();
	void shoprender();
	void render();


private:
	tileManager* _tilem;
	RECT shopsell;

};


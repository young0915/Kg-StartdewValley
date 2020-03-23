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

class shopscene :public gameNode
{
private:
	shopmain _shopmain;

	


public :
	shopscene();
	~shopscene();

	HRESULT init();
	void rlease();
	void update();
	void itemsell();									//구매할 함수 

	void shoprender();
	void render();


private:
	tileManager* _tilem;
	RECT shopsell;

};


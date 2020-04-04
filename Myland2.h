#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "groundManager.h"
#include "vegetablemanager.h"
#include "item.h"
#include "effect.h"

/*
논밭 갈 예정
인벤토리에 씨앗을 사용할 경우도 넣을 것 
*/

class Myland2 : public gameNode
{
private :
	tileManager* _tilem;
	groundManager* _ground;
	vegetablemanager* _vegetable;
	vector<item> _item;

	RECT myhome;
	RECT myhomerect;
	image* _twinkle;
	bool istwinkel;
	int i;
	int count;


public :
	Myland2();
	~Myland2();

	HRESULT init();
	void release();
	void update();
	void render();
	void groundmash();
};


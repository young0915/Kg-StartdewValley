#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "groundManager.h"
#include "vegetablemanager.h"
#include "item.h"
#include "effect.h"

/*
��� �� ����
�κ��丮�� ������ ����� ��쵵 ���� �� 
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


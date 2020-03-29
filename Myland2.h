#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "groundManager.h"
#include "item.h"

/*
��� �� ����
�κ��丮�� ������ ����� ��쵵 ���� �� 
*/

class Myland2 : public gameNode
{
private :
	tileManager* _tilem;
	groundManager* _ground;
	vector<item> _item;
public :
	Myland2();
	~Myland2();

	HRESULT init();
	void release();
	void update();
	void render();
};


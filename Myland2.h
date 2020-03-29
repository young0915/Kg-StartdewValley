#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "groundManager.h"
#include "item.h"

/*
논밭 갈 예정
인벤토리에 씨앗을 사용할 경우도 넣을 것 
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


#pragma once
#include "gameNode.h"
#include "potato.h"
#include "item.h"
class vegetablemanager : public gameNode
{
private :
	typedef vector<vegetable*> _vegetable;
	typedef vector<vegetable*>::iterator _itervegetable;

private:
	_vegetable _vegeta;
	_itervegetable _itervegeta;
	item _item;

public:
	vegetablemanager();
	~vegetablemanager();


	HRESULT init();
	void release();
	void update(vector<item> &item);
	void render();

	void setpotato();
	void collisiongrow();																//¾¾¾ÑÀÌ ¶¥¿¡ ´ê¾ÒÀ» ¶§ 


};


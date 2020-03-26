#pragma once
#include "gameNode.h"
#include "stone.h"
#include "itemstone.h"
#include "ruby.h"
class othermanager :public gameNode 
{
private:

public :
	othermanager();
	~othermanager();

	HRESULT init();
	void release();
	void update();
	void render();

};


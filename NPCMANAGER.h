#pragma once
#include "gameNode.h"
class NPCMANAGER :public gameNode
{
private:

public :
	NPCMANAGER();
	~NPCMANAGER();

	HRESULT init();
	void release();
	void render();
	void update();
};


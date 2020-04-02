#pragma once
#include "gameNode.h"
#include "Abigail.h"
#include "Alex.h"
#include "Sebastian.h"
class NPCMANAGER :public gameNode
{
private:
	Abigail* _abigail;
	Alex* _alex;
	Sebastian* _sebastian;

	RECT rc;

public :
	NPCMANAGER();
	~NPCMANAGER();

	HRESULT init();
	void release();
	void render();
	void update();

	Abigail* gethuman() { return _abigail; }
	Alex* gethumantwo() { return _alex; }
	Sebastian* gethumsntree() {return _sebastian;}
};


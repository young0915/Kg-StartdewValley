#pragma once
#include "gameNode.h"
class Myland : public gameNode
{
private :
	tagTile _tile[TILEX* TILEY];
	tagTile _temp[TILEX* TILEY];
	

public :
	Myland();
	~Myland();

	HRESULT init();
	void release();
	void update();
	void render();
	void maptoolinit();												//���� �̹��� �ҷ�����
	void maptoolrender();											
};


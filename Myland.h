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
	void maptoolinit();												//맵툴 이미지 불러오기
	void maptoolrender();											
};


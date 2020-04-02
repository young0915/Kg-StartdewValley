#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "othermanager.h"
class Myland : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];
	tagTile _temp[TILEX * TILEY];
	tagObJAttribute _OBJattribute[TILEX* TILEY];
	tagSampleTile _sampleMap[SAMPLETILEX* SAMPLETILEY];
	DWORD _attribute[TILEX* TILEY];
	int _pos[2];
	tileManager* _tilem;
	RECT _minego;
	RECT _myhouse;
	RECT townrect;

	othermanager* _other;
	vector<item> _dropitem;

public:
	Myland();
	~Myland();

	HRESULT init();
	void release();
	void update();
	void render();
};


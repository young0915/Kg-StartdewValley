#pragma once
#include "gameNode.h"
class tileManager : public gameNode
{
private:
	tagCurrentTile _currentTile;
	tagTile _map[TILEX* TILEY];
	tagObJAttribute _OBJattribute[TILEX* TILEY];
	tagSampleTile _sampleMap[SAMPLETILEX* SAMPLETILEY];
	DWORD _attribute[TILEX* TILEY];
	int _pos[2];

public:
	tileManager();
	~tileManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void mapattribute();

	void Mylandload(int x, int y);
	void Mineload();


	DWORD* getAttribute() { return _attribute; }
	tagTile* getMap() { return _map; }
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }
	void attackBlock(int tileN);
};


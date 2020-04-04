#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "othermanager.h"
#include "effect.h"
struct tagtrees
{
	animation* _ani;
	image* _img;
	RECT rc;
	float x, y;
	bool ischeck;
	int time;
	int atkcount;
};


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
	RECT _minegotwinkle;

	RECT townrect;

	othermanager* _other;
	vector<item> _dropitem;

	image* _twinkle;
	bool isturnon;
	bool istwinkel;
	int i;
	int time2;

	tagtrees  tree;

	effect* treedrop;
	effect* grassdrop;
	effect* grassdrop1;
	effect* rockdrop;
	effect* rockdrop1;

	RECT mashrect[4];
	int count;
public:
	Myland();
	~Myland();

	HRESULT init();
	void release();
	void update();
	void render();
	void mashground();
};


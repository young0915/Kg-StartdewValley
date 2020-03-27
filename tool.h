#pragma once
#include "gameNode.h"

enum TOOLTYPE
{
	TOOL_AXE,
	TOOL_PICKAXE,
	TOOL_HOE
};

enum TOOLMOVE
{
	TT_DOWN,
	TT_RIGHT,
	TT_LEFT,
	TT_UP,
	TT_NONE
};

struct tagtooluse
{
	TOOLTYPE _type;
	TOOLMOVE _tm;
	image* _img;
	RECT _rc;
	RECT _atkrc;
	float x, y;
	int _count;
	int _index;
};

class tool :public gameNode
{
private:
	tagtooluse _axe;
	tagtooluse _pickaxe;
	tagtooluse _hoe;
public :
	tool();
	~tool();

	HRESULT init();
	void release();
	void update();
	void render();
	image* getaxeimg() { return _axe._img; }
	RECT getaxe() { return _axe._rc; }
	RECT getpickaxe() { return _pickaxe._rc; }
	RECT gethoe() { return _hoe._rc; }


	TOOLTYPE axetype() { return _axe._type; }
	void setaxetype(TOOLMOVE _axetype) { _axe._tm = _axetype; }
	void setpicktype(TOOLMOVE _picktype) { _pickaxe._tm = _picktype; }
	void sethomtype(TOOLMOVE _ho) { _hoe._tm = _ho; }

	TOOLTYPE picktype() { return _pickaxe._type; }
	TOOLMOVE axemove() { return _axe._tm; }
	TOOLMOVE pickmove() { return _pickaxe._tm; }


	void axemove(int _x, int _y, TOOLTYPE _ttype, TOOLMOVE _move);
	void pickaxemove(int _x, int _y, TOOLTYPE _ttype, TOOLMOVE _move);
	void homemove(int _x, int _y, TOOLTYPE _ttype, TOOLMOVE _move);


};


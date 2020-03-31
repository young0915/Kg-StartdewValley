#pragma once
#include "gameNode.h" 
#include "item.h"

enum MONSTERMOVE
{
	MONSTER_IDLE,
	MONSTER_MOVE,
	MONSTER_DIE
};
enum M_DIRECTION
{
	M_LEFT =0,
	M_RIGHT,
	M_UP,
	M_DOWN,
	M_LB,
	M_RB,
	M_LU,
	M_RU,
	M_STOP
};

class monster : public gameNode 
{
private :
	MONSTERMOVE _monster;
	M_DIRECTION _direction;
	image* _img;
	animation* _ani;
	RECT _rc;
	RECT _atkrc;
	image* _imgitem;
	item _item;
	int index;
	int count;
	int movecount;
	bool _ismove;
	int num;
public :
	monster();
	~monster();

	HRESULT init(const char* name, POINT position, M_DIRECTION direction, MONSTERMOVE move, bool ismove);
	void release();
	void update();
	void render();

	MONSTERMOVE getmove() { return _monster; }
	void setmove(MONSTERMOVE _move) { _monster = _move; }

	M_DIRECTION getdirection() { return _direction; }
	void setdriection(M_DIRECTION _mdir) { _direction = _mdir; }

	bool getismove() { return _ismove; }
	void setismove(bool isact) { _ismove = isact; }

	void crabSTATE();
	void crabmove();

	RECT getRect() { return _rc; }
	RECT getatckrange() { return _atkrc; }
	item getitem() { return _item; }
};


#pragma once
#include "gameNode.h"


enum TOOLS
{
	TOOL_AXE,
	TOOL_HOE,
	TOOL_PICKAXE,
	TOOL_WATERCAN,
	TOOL_EMPTY
};
//¹«±â ¹æÇâ
enum TOOLDIR
{
	T_DOWN,
	T_RIGHT,
	T_LEFT,
	T_UP,
	T_STOP
};
struct  tagtool
{
	TOOLDIR _tdir;									//¹«±â¹æÇâ
	TOOLS _tool;
	image* _img;
	RECT rc;
	float x, y;
	int count;
	int index;
};
class tool :public gameNode
{
private:
	tagtool _ax;															//µµ³¢
	tagtool _pick;														//°î±ªÀÌ
	tagtool _homie;													//È£¹Ì
	tagtool _watercan;												//¹°»Ñ¸®°³
	tagtool _sickle;														//³´

public:
	tool();
	~tool();

	HRESULT init();
	void release();
	void render();
	void update();

	void toolmove(TOOLDIR _dir);
};


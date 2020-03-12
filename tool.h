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
//���� ����
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
	TOOLDIR _tdir;									//�������
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
	tagtool _ax;															//����
	tagtool _pick;														//���
	tagtool _homie;													//ȣ��
	tagtool _watercan;												//���Ѹ���
	tagtool _sickle;														//��

public:
	tool();
	~tool();

	HRESULT init();
	void release();
	void render();
	void update();

	void toolmove(TOOLDIR _dir);
};


#pragma once
#include "gameNode.h"

enum STONE_TYPE
{
	ETC_STONE,
	RUBY_STONE,
	GRASS_TYPE,
	TREE_TYPE
};

enum STONE_STATE
{
	STONE_IDLE,															//������ �ִ�	����
	STONE_MASH														//���� ����
};

class stone :public gameNode
{
private:
	STONE_STATE _sstate;
	STONE_TYPE _tone;
	image* _img;
	RECT _rc;
	item _item;
	int _atk;
	int _currentX, _currentY;
	int hitcount;

public :
	stone();
	~stone();

	HRESULT init();
						//�̹��� 								��ġ x, y     �÷��̾� ���� ��� �ϴ� ���ݷ�
	HRESULT init(const char* imagename, STONE_TYPE tone, STONE_STATE sstate, POINT position, int atk);
	void release();
	void update();
	void render();


	STONE_STATE getstate() { return _sstate; }
	STONE_TYPE gettype() {return _tone;}

	void setstate(STONE_STATE state) { _sstate = state; }			// ���� ����


	int getCurrentX() { return _currentX; }
	int getCurrentY() { return _currentY; }


	RECT getstonerc() { return _rc; }
	item getitem() { return _item; }
}; 


//���̶� ��� �︮�Ѵ� �� 

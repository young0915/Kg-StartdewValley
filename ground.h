#pragma once
#include "gameNode.h"
#include "item.h"

enum STATE_GROUND
{
	JUST_GROUND,														//�׳� ��
	MASH_GROUND,														// ���� �� ->ȣ�� �� �� ��
	WET_GROUND,														//���� �� ->���Ѹ��� �� ��
	ITEM_GROUND															//������ �� �ڶ� �� -> item ����
};
//�� Ÿ��
struct  taggorundtile
{
	STATE_GROUND _state_ground;
	item _item;
	image* _img;
	RECT _rc;
	int _x, _y;
	int count; 
	int index;
	bool _isact;															//Ȱ���� �߳� ���߳�-> Ÿ�� ü������ �ϱ� ���� bool ��
};

class ground :public gameNode
{
private:
	taggorundtile _tile;

public :
	ground();
	~ground();

	bool getisact() { return _tile._isact; }
	void setisact(bool isact) { _tile._isact = isact; }

	STATE_GROUND getsateground() { return _tile._state_ground; }
	void setstateground(STATE_GROUND _state) { _tile._state_ground = _state; }

	HRESULT init(const char* groundname, POINT position, STATE_GROUND stateground, bool isact);
	void release();
	void update();
	void render();

};


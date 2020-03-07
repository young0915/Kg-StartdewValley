#pragma once
#include "gameNode.h"
#include "cusor.h"

enum INTROBUTTON
{
	STARTBTN,
	MAPTOOLBUTN,
	EXITBTN
};

//��Ʈ�� UI����
struct  tagintroUI
{
	image* _img;
	RECT rc;
	float x, y;
};

class introscene :public gameNode
{
private:
	INTROBUTTON _btn;
	tagintroUI _tile;																	//����
	tagintroUI _button[3];															//����, ����, �������ư
	image* _cloud[7];																//���� �����̱� 
	int loopX, loopY;																	//���� ���� �ʱ�ȭ��
	float speed;

	cusor* _cursor;
public:
	introscene();
	~introscene();

	HRESULT init();
	void release();
	void update();
	void render();

	void introbtnn();																//��Ʈ�ι�ư
	void cloudinit();																//���� �ʱ�ȭ��
	void cloudrender();															//���� ������ ����
};


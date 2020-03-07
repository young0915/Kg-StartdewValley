#pragma once
#include "gameNode.h"
#include "cusor.h"

enum INTROBUTTON
{
	STARTBTN,
	MAPTOOLBUTN,
	EXITBTN
};

//인트로 UI정보
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
	tagintroUI _tile;																	//제목
	tagintroUI _button[3];															//시작, 맵툴, 나가기버튼
	image* _cloud[7];																//구름 움직이기 
	int loopX, loopY;																	//구름 랜더 초기화값
	float speed;

	cusor* _cursor;
public:
	introscene();
	~introscene();

	HRESULT init();
	void release();
	void update();
	void render();

	void introbtnn();																//인트로버튼
	void cloudinit();																//구름 초기화값
	void cloudrender();															//구름 움직임 랜더
};


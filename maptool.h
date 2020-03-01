#pragma once
#include "gameNode.h"
#include "tileNode.h"


//맵툴 버튼 
struct tagButton
{
	RECT rc;
	image* _btnimg;
	int x, y;
};
//맵툴 보드
struct tagSampleBoard
{
	tagButton _button[8];																						// 버튼 렉트 
	image* _boardimg;																							//맵툴 보드 이미지
	RECT boardrc;																									//맵툴 보드 렉트
	bool _isopen;																									//맵툴이 오픈
	int x, y;
};
//맵툴 선택 
enum SELECT
{
	TRRAINDRAW,																						//지형(Ex 밟을 때 사운드를 나게 하거나 이동할 수 없는 지역 등등)
	OBJDRAW,																								//오브젝트(Ex 지형위쪽에 배치. 움직이거나 부서지거나 하는 녀석 등등 변화를 줄 수 있는 물체)
	ERASER																									//삭제
};


class maptool : public gameNode
{
private:
	tagCurrentTile _currentTile;																// 현재 타일
	tagTile _tile[TILEX*TILEY];																	//타일  붙이기 
	tagTile _tmep[TILEX*TILEY];																//빈타일
	tagSampleTile _sampleTile[SAMPLETILEX*SAMPLETILEY];			//샘플 타일

	tagSampleBoard _sampleboard;														//샘플 보드
	tagButton _samplebutton[2];															//샘플에 버튼

	RECT rc[25];																							//샘플 이미지 칸
	RECT saveload[25];																				//샘플 이미지 
	//image* saveload

public:
	maptool();
	~maptool();

	HRESULT init();
	void relaese();
	void update();
	void render();

	void save();
	void load();

	void cameraMove();
	void setUp();
	void mapInit();
	void setMaptoolBoard();																//맵툴보드 상태
	void controlMaptoolBoard();														//맵툴보드 

};


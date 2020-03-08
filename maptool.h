#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include "sampleimage.h"
//#include "cusor.h"

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
	tagButton _button[3];																						// 버튼 렉트 
	image* _boardimg;																							//맵툴 보드 이미지
	RECT boardrc;																									//맵툴 보드 렉트
	bool _isopen;																									//맵툴이 오픈
	int x, y;
};
//맵툴 선택 
enum SELECT
{
	TRRAINDRAW,	//지형(Ex 밟을 때 사운드를 나게 하거나 이동할 수 없는 지역 등등)
	OBJDRAW,																								//오브젝트(Ex 지형위쪽에 배치. 움직이거나 부서지거나 하는 녀석 등등 변화를 줄 수 있는 물체)
	ERASER																									//삭제
};
//
//enum MAPKIND
//{
//	/*S, M*/
//	SPRING_FLOOR,
//	MOUNTAIN,
//	MINE
//};

class maptool :public gameNode
{
private:
	tagTile _tile[TILEX* TILEY];																						 //타일  
	tagTile _temp[TILEX*TILEY];																					 //빈타일 
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];							 //샘플 타일
	tagCurrentTile _currentTile;																					// 현재 타일

	tagSampleBoard _sampleboard;																			//타일 보드 
	tagButton _samplebutton[5];																				//샘플 버튼

	RECT rc[36];
	image* _springfloor[36];																						//페이지에 뿌려줄 이미지-> 봄 바닥


	int page;																														//페이지

	SELECT _select;																											//선택
	POINT _start;																												//스타트
	POINT _end;																												//끝점

	POINT _mousePoint;

	//	bool first;
	bool mouse;																											//마우스 닿았을 때  활성화 비활성화

	//클래스
	sampleimage* _sampleimg;

	//	MAPKIND mapKind;
public:
	maptool();
	~maptool();

	HRESULT init();
	void release();
	void update();
	void render();

	void drage();

	void save();																			//세이브
	void load();																			//로드

	void CameraMove();															//카메라 이동
	void setUp();																			//타일 셋팅하는 함수

	//샘플보드 설정
	void mapinit();																		// 샘플북 초기화 설정
	void setsampleTile();															//샘플 타일 설정
	void setsampleboard();														//샘플보드
	void sampleboardcontrol();												//샘플보드에서 버튼 조정하는 함수
	void setboardbutton();														//샘플 보드 설정
	void sampleRc();																	//랙트 뿌리기
	void setpageSample();															//샘플 페이지에 넣을 이미지들
	void setMap();																		//타일 들 설정
	void setsampleMap();															//현재타일 찍기 함수
	//void drag();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

private:
	//cusor* _cursor;
};


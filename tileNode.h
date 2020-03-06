#pragma once



//타일사이즈
#define TILESIZE 50

//크기
#define TILEX 50
#define TILEY 50


//타일 총 사이즈 
#define TILESIZEX TILESIZE * TILEX 
#define TILESIZEY TILESIZE * TILEY

//타일셋(샘플 타일) 화면 오른쪽 이미지 타일 갯수 
#define SAMPLETILEX 6
#define SAMPLETILEY 6

//비트연산을 하기 위해 
#define ATTR_UNMOVABLE 0x00000001
#define ATTR_POSITION 0x00000002

//지형(Ex 밟을 때 사운드를 나게 하거나 이동할 수 없는 지역 등등)
enum TERRAIN
{	//아무것도 없는,          벽				땅
	TERAIN_NONE, TERAIN_WALL, TERAIN_GROUND, TERAIN_MOUNTAIN, TERAIN_MINE

};

//오브젝트(Ex 지형위쪽에 배치. 움직이거나 부서지거나 하는 녀석 등등 변화를 줄 수 있는 물체)
enum OBJECT
{
	//						벽					돌					강				온천			나무			꽃					농밭
	OBJ_NONE, OBJ_WALL, OBJ_STONE, OBJ_RIVER, OBJ_SPA, OBJ_TREE, OBJ_FLOWER, OBJ_FARM
};

//포지션 정의
enum POS
{
	POS_PLAYER,							//플레이어
	POS_NPC,								//다른 캐릭터
	POS_ANIMAL,						//동물
	POS_MONSTER						//몬스터
};
//타일 구조체 
struct tagTile
{
	TERRAIN terrain;					//지형변수
	OBJECT obj;							//물체 변수
	RECT rc;									//타일에 사용할 렉트

	int terrainFrameX;				//지형프레임x 
	int terrainFrameY;				//지형프레임y
	int objFrameX;						//물체프레임x
	int objFrameY;						//물체프레임y
	int x, y;									//타일 중점좌표
};

//이미지 타일 구조체
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//현재 타일 구조체
struct tagCurrentTile
{
	int x;
	int y;
};

struct tagObJAttribute
{
	int strengh;		//내구도
};


/*
tileNode.h 는 씬에도 필요함
*/
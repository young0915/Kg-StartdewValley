#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "rat.h"

#define BIGNUM	5000	// 초기값(F)
#define astarTileX 20
#define astarTileY 600
#define astarTileSize astarTileX * astarTileY

//선택
enum Select
{
	SELECT_START,						//시작점
	SELECT_END,							//끝점
	SELECT_BLOCK						//SELECT_BLOCK
};

//방향
enum Direction
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFTUP,																			//z방향 때문
	DIRECTION_RIGHTDOWN,																	//z방향 때문
	DIRECTION_LEFTDOWN,																		//z방향 때문
	DIRECTION_RIGHTUP																			//z방향 때문
};

struct tagastarTile
{
	RECT rc;
	OBJECT obj;
	bool block;																							//충돌처리
	int node;
	int showState;
	int f, g, h;
};

//파일 상태를 저장하기 위한 상태들
enum State
{
	STATE_NONE,
	STATE_OPEN,
	STATE_CLOSE,
	STATE_PATH
};

class aStarScene : public gameNode
{
private:
	tileManager* _mine;
	rat* _rat;
	tagastarTile tile[astarTileSize];

	vector<int> openlist;
	vector<int>closelist;
	vector<int>pathList;
	vector<int>::iterator iter;

	Select currentselect;

	int startTile;
	int endTile;
	int currentTile;

	int exTile;

	//=========몬스터 시작점 끝점========
	int m_startX;
	int m_startY;

	int m_endX;
	int m_endY;
	//=========몬스터 시작점 끝점========

	bool isFind;
	bool noPath;
	bool startAstar;



//	int temp;
	RECT _enemyrect;
	int moveX = 0;															//원점 말고 이동한 값
	int moveY = 0;															//원점 말고 이동한 값
	int toGoX = 0;
	int toGoY = 0;
	int moveCount;

	//시간함수를 쓰기 위한 변수
	float deltaTime;		
	float pastTime = 0.f;
	float addCharDeley = 0.01f;

	Direction enemyDirection;
	bool enemyMoveOk;
	int directionCount = 0;

	HBRUSH brush;
public :
	aStarScene();
	~aStarScene();

	HRESULT init(tagTile _tile[]);
	//HRESULT mineinit();
	void release();
	void update(tagTile _tile[]/* ,RECT _playerRect*/);
	void  render();

	void Astar();
	void enemylistSet();
	void playerTileSet(RECT rc);
	void blockType();

	void rectMoveDirect();


//	void mineastar();															//동굴 박쥐에게 사용할 에이스타
//	void villageastar();														//마을에서 사용할 에이스타
};


//일부분이라서 
/*
 



*/
#pragma once
#include "gameNode.h"
#include "tileManager.h"
#include "rat.h"

#define BIGNUM	5000	// �ʱⰪ(F)
#define astarTileX 20
#define astarTileY 600
#define astarTileSize astarTileX * astarTileY

//����
enum Select
{
	SELECT_START,						//������
	SELECT_END,							//����
	SELECT_BLOCK						//SELECT_BLOCK
};

//����
enum Direction
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFTUP,																			//z���� ����
	DIRECTION_RIGHTDOWN,																	//z���� ����
	DIRECTION_LEFTDOWN,																		//z���� ����
	DIRECTION_RIGHTUP																			//z���� ����
};

struct tagastarTile
{
	RECT rc;
	OBJECT obj;
	bool block;																							//�浹ó��
	int node;
	int showState;
	int f, g, h;
};

//���� ���¸� �����ϱ� ���� ���µ�
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

	//=========���� ������ ����========
	int m_startX;
	int m_startY;

	int m_endX;
	int m_endY;
	//=========���� ������ ����========

	bool isFind;
	bool noPath;
	bool startAstar;



//	int temp;
	RECT _enemyrect;
	int moveX = 0;															//���� ���� �̵��� ��
	int moveY = 0;															//���� ���� �̵��� ��
	int toGoX = 0;
	int toGoY = 0;
	int moveCount;

	//�ð��Լ��� ���� ���� ����
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


//	void mineastar();															//���� ���㿡�� ����� ���̽�Ÿ
//	void villageastar();														//�������� ����� ���̽�Ÿ
};


//�Ϻκ��̶� 
/*
 



*/
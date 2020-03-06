#pragma once



//Ÿ�ϻ�����
#define TILESIZE 50

//ũ��
#define TILEX 50
#define TILEY 50


//Ÿ�� �� ������ 
#define TILESIZEX TILESIZE * TILEX 
#define TILESIZEY TILESIZE * TILEY

//Ÿ�ϼ�(���� Ÿ��) ȭ�� ������ �̹��� Ÿ�� ���� 
#define SAMPLETILEX 6
#define SAMPLETILEY 6

//��Ʈ������ �ϱ� ���� 
#define ATTR_UNMOVABLE 0x00000001
#define ATTR_POSITION 0x00000002

//����(Ex ���� �� ���带 ���� �ϰų� �̵��� �� ���� ���� ���)
enum TERRAIN
{	//�ƹ��͵� ����,          ��				��
	TERAIN_NONE, TERAIN_WALL, TERAIN_GROUND, TERAIN_MOUNTAIN, TERAIN_MINE

};

//������Ʈ(Ex �������ʿ� ��ġ. �����̰ų� �μ����ų� �ϴ� �༮ ��� ��ȭ�� �� �� �ִ� ��ü)
enum OBJECT
{
	//						��					��					��				��õ			����			��					���
	OBJ_NONE, OBJ_WALL, OBJ_STONE, OBJ_RIVER, OBJ_SPA, OBJ_TREE, OBJ_FLOWER, OBJ_FARM
};

//������ ����
enum POS
{
	POS_PLAYER,							//�÷��̾�
	POS_NPC,								//�ٸ� ĳ����
	POS_ANIMAL,						//����
	POS_MONSTER						//����
};
//Ÿ�� ����ü 
struct tagTile
{
	TERRAIN terrain;					//��������
	OBJECT obj;							//��ü ����
	RECT rc;									//Ÿ�Ͽ� ����� ��Ʈ

	int terrainFrameX;				//����������x 
	int terrainFrameY;				//����������y
	int objFrameX;						//��ü������x
	int objFrameY;						//��ü������y
	int x, y;									//Ÿ�� ������ǥ
};

//�̹��� Ÿ�� ����ü
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};

//���� Ÿ�� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};

struct tagObJAttribute
{
	int strengh;		//������
};


/*
tileNode.h �� ������ �ʿ���
*/
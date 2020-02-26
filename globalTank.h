
#define TILESIZE 32 //������ ȭ�� Ÿ�� ������
#define TILEX 20	//����ȭ�� Ÿ�� ������ X
#define TILEY 20	//���� ȭ�� Ÿ�� ������ Y

#define TILESIZEX TILEX * TILESIZE
#define TILESIZEY TILEY * TILESIZE

//ȭ�� ������ �̹��� Ÿ�� ����
#define SAMPLETILEX 20
#define SAMPLETILEY 9

//��Ʈ������ �ϱ� ���� 
#define ATTR_UNMOVABLE 0x00000001
#define ATTR_POSITION 0x00000002
//����(EX ������ ���带 ���� �ϰų� �̵��� �� ���� ���� ���)
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ(EX �������ʿ� ��ġ �����̰ų� �μ����ų� �ϴ� �༮ ��� ��ȭ�� �ټ� �ִ� ��ü)
enum OBJECT
{
	OBJ_BLOCK,
	OBJ_BLOCK3,
	OBJ_BLOCKS,
	OBJ_TANK1,
	OBJ_TANK2,
	OBJ_NONE
};

//��ġ ��ǥ
enum POS
{
	POS_TANK1,
	POS_TANK2
};
//Ÿ�� ����ü

struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rcTile;

	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
};
//�̹��� Ÿ�� ����ü
struct tagSampleTile
{
	RECT rcTile[SAMPLETILEX* SAMPLETILEY];
	int terrainFrameX;
	int terrainFrameY;
};
//���� Ÿ�� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};

struct tagOBJAttribute
{
	int strengh;		//������
};

#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include "sampleimage.h"
//#include "cusor.h"

//���� ��ư 
struct tagButton
{
	RECT rc;
	image* _btnimg;
	int x, y;
};
//���� ����
struct tagSampleBoard
{
	tagButton _button[3];																						// ��ư ��Ʈ 
	image* _boardimg;																							//���� ���� �̹���
	RECT boardrc;																									//���� ���� ��Ʈ
	bool _isopen;																									//������ ����
	int x, y;
};
//���� ���� 
enum SELECT
{
	TRRAINDRAW,	//����(Ex ���� �� ���带 ���� �ϰų� �̵��� �� ���� ���� ���)
	OBJDRAW,																								//������Ʈ(Ex �������ʿ� ��ġ. �����̰ų� �μ����ų� �ϴ� �༮ ��� ��ȭ�� �� �� �ִ� ��ü)
	ERASER																									//����
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
	tagTile _tile[TILEX* TILEY];																						 //Ÿ��  
	tagTile _temp[TILEX*TILEY];																					 //��Ÿ�� 
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];							 //���� Ÿ��
	tagCurrentTile _currentTile;																					// ���� Ÿ��

	tagSampleBoard _sampleboard;																			//Ÿ�� ���� 
	tagButton _samplebutton[5];																				//���� ��ư

	RECT rc[36];
	image* _springfloor[36];																						//�������� �ѷ��� �̹���-> �� �ٴ�


	int page;																														//������

	SELECT _select;																											//����
	POINT _start;																												//��ŸƮ
	POINT _end;																												//����

	POINT _mousePoint;

	//	bool first;
	bool mouse;																											//���콺 ����� ��  Ȱ��ȭ ��Ȱ��ȭ

	//Ŭ����
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

	void save();																			//���̺�
	void load();																			//�ε�

	void CameraMove();															//ī�޶� �̵�
	void setUp();																			//Ÿ�� �����ϴ� �Լ�

	//���ú��� ����
	void mapinit();																		// ���ú� �ʱ�ȭ ����
	void setsampleTile();															//���� Ÿ�� ����
	void setsampleboard();														//���ú���
	void sampleboardcontrol();												//���ú��忡�� ��ư �����ϴ� �Լ�
	void setboardbutton();														//���� ���� ����
	void sampleRc();																	//��Ʈ �Ѹ���
	void setpageSample();															//���� �������� ���� �̹�����
	void setMap();																		//Ÿ�� �� ����
	void setsampleMap();															//����Ÿ�� ��� �Լ�
	//void drag();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

private:
	//cusor* _cursor;
};


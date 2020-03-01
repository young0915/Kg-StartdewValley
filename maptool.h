#pragma once
#include "gameNode.h"
#include "tileNode.h"


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
	tagButton _button[8];																						// ��ư ��Ʈ 
	image* _boardimg;																							//���� ���� �̹���
	RECT boardrc;																									//���� ���� ��Ʈ
	bool _isopen;																									//������ ����
	int x, y;
};
//���� ���� 
enum SELECT
{
	TRRAINDRAW,																						//����(Ex ���� �� ���带 ���� �ϰų� �̵��� �� ���� ���� ���)
	OBJDRAW,																								//������Ʈ(Ex �������ʿ� ��ġ. �����̰ų� �μ����ų� �ϴ� �༮ ��� ��ȭ�� �� �� �ִ� ��ü)
	ERASER																									//����
};


class maptool : public gameNode
{
private:
	tagCurrentTile _currentTile;																// ���� Ÿ��
	tagTile _tile[TILEX*TILEY];																	//Ÿ��  ���̱� 
	tagTile _tmep[TILEX*TILEY];																//��Ÿ��
	tagSampleTile _sampleTile[SAMPLETILEX*SAMPLETILEY];			//���� Ÿ��

	tagSampleBoard _sampleboard;														//���� ����
	tagButton _samplebutton[2];															//���ÿ� ��ư

	RECT rc[25];																							//���� �̹��� ĭ
	RECT saveload[25];																				//���� �̹��� 
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
	void setMaptoolBoard();																//�������� ����
	void controlMaptoolBoard();														//�������� 

};


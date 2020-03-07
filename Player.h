#pragma once
#include "singletonBase.h"
#include "tileNode.h"
#include "cusor.h"
#include "progressBar.h"											//�÷��̾� ���α׷�����
//#include "closet.h"
//�÷��̾� ������
enum PLAYERMOVE
{
	//�÷��̾� �⺻ ������
	PLAYER_DOWN,
	PLAYER_RIGHT,
	PLAYER_LEFT,
	PLAYER_UP,
	//�÷��̾� ���, ����, ����, ��, �� 
	PLAYER_PWR_DOWN,
	PLAYER_PWR_RIGHT,
	PLAYER_PWR_LEFT,
	PLAYER_PWR_UP,
	//�÷��̾� ����
	PLAYER_PIS_DOWN,
	PLAYER_PIS_RIGHT,
	PLAYER_PIS_LEFT,
	PLAYER_PIS_UP,
	PLAYER_STOP												//���߱� ���� ��
};
//�÷��̾� �� ������
enum PLAYERARMMOVE
{
	//�÷��̾� �⺻ (��) ������
	PLAYER_ARM_DOWN,
	PLAYER_ARM_RIGHT,
	PLAYER_ARM_LEFT,
	PLAYER_ARM_UP,
	//�÷��̾� (��) ���, ����, ����, ��, �� 
	PLAYER_ARM_PWR_DOWN,
	PLAYER_ARM_PWR_RIGHT,
	PLAYER_ARM_PWR_LEFT,
	PLAYER_ARM_PWR_UP,
	//�÷��̾�  (��) ����
	PLAYER_ARM_PIS_DOWN,
	PLAYER_ARM_PIS_RIGHT,
	PLAYER_ARM_PIS_LEFT,
	PLAYER_ARM_PIS_UP,
	//�÷��̾� ���Ѹ���
	PLAYER_ARM_WATCAN_DOWN,
	PLAYER_ARM_WATCAN_RIGHT,
	PLAYER_ARM_WATCAN_LEFT,
	PLAYER_ARM_WATCAN_UP,
	PLAYER_ARM_STOP												//���߱� ���� ��
};
//�÷��̾� ���� ������
enum PLAYERPANTS
{
	//�÷��̾� �⺻ ������
	PLAYER_PANTS_DOWN,
	PLAYER_PANTS_RIGHT,
	PLAYER_PANTS_LEFT,
	PLAYER_PANTS_UP,
	//�÷��̾� ���, ����, ����, ��, �� 
	PLAYER_PANTS_PWR_DOWN,
	PLAYER_PANTS_PWR_RIGHT,
	PLAYER_PANTS_PWR_LEFT,
	PLAYER_PANTS_PWR_UP,
	//�÷��̾� ����
	PLAYER_PANTS_PIS_DOWN,
	PLAYER_PANTS_PIS_RIGHT,
	PLAYER_PANTS_PIS_LEFT,
	PLAYER_PANTS_PIS_UP,
	//�÷��̾� ���Ѹ���
	PLAYER_PANTS_WATERCAN_DOWN,
	PLAYER_PANTS_WATERCAN_RIGHT,
	PLAYER_PANTS_WATERCAN_LEFT,
	PLAYER_PANTS_WATERCAN_UP,
	PLAYER_PANT_STOP
};
// �÷��̾� ���� 
struct tagplayer
{
	PLAYERMOVE _playermove;								//�÷��̾� ������
	PLAYERARMMOVE _playerarmmove;				//�÷��̾� �� ������ 
	PLAYERPANTS _playerpants;								//�÷��̾� ���� ������
	image* _playerimg;												//�÷��̾� �̹���(��:��, ��)
	image* _playerarmimg;										//�÷��̾� �̹���(��)
	image* _playercloth;											//�÷��̾� ��
	image* _pantsimg;													//�÷��̾� ����
	RECT _playerect;													// ������ rect 
	float x;																	//�÷��̾� x 
	float y;																	//�÷��̾� y
	int _placount;														//�÷��̾� �̹����Ŵ����� ����� ī��Ʈ
	int _plaindex;														//�÷��̾� �̹��� �Ŵ����� ����� �ε���
};
//�÷��̾� ���α׷�����(Hp & Energy)
struct tagplayerHpbar
{
	progressBar* _hpbar;
	int Hp;
	int _maxhp;
};

struct  tagenergybar
{
	energybar* _energy;
	int energy;
	int _maxenergy;
};
class Player : public singletonBase<Player>
{
private:
	tagplayer _player;												//�÷��̾� ����
	tagplayerHpbar _hp;											//hp
	tagenergybar _energy;									//�÷��̾� ������

	//Ŀ��
	cusor* _cursor;

public:
	Player();
	~Player();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void playerkeycontrol();											//�÷��̾� Ű�� ��Ƶ� ��													
	void playermove();													//�÷��̾� ������(body)
	void clothmove();														//�÷��̾� ����
	void playerenergybar();											//��������

	void playerimg();														//�÷��̾� �̹��� ���� �Լ� 
	void energydamage(float _energy);						//energy������
	void hpdamage(float _hp);										//hp������

	float getplayerX() { return _player.x; }
	float getplayerY() { return _player.y; }
};


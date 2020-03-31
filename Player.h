#pragma once
#include "singletonBase.h"
#include "tileManager.h"
#include "inventory.h"
#include "clock.h"
//#include "cusor.h"
#include "progressBar.h"											//�÷��̾� ���α׷�����
#include "tool.h"


enum PLAYERDIRECTION
{
	PLAYER_D_DOWN,
	PLAYER_D_RIGHT,
	PLAYER_D_LEFT,
	PLAYER_D_UP
};

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
	//�÷��̾� �����̵�
	PLAYER_IDLE_DOWN,
	PLAYER_IDLE_RIGHT,
	PLAYER_IDLE_LEFT,
	PLAYER_IDLE_UP,
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
	//�÷��̾� ��
	PlAYER_SWORD_DOWN,
	PlAYER_SWORD_RIGHT,
	PlAYER_SWORD_LEFT,
	PlAYER_SWORD_UP,
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
	//���߱�
	PLAYER_ARM_IDLE_DOWN,
	PLAYER_ARM_IDLE_RIGHT,
	PLAYER_ARM_IDLE_LEFT,
	PLAYER_ARM_IDLE_UP,
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
	//�÷��̾� ���̵�
	PLAYER_PANTS_IDLE_DOWN,
	PLAYER_PANTS_IDLE_RIGHT,
	PLAYER_PANTS_IDLE_LEFT,
	PLAYER_PANTS_IDLE_UP,
	PLAYER_PANT_STOP,
	PLAYER_PANT_PWR_STOP
};

//���� ����
enum TOOLDIR
{
	T_DOWN,
	T_RIGHT,
	T_LEFT,
	T_UP,
	T_NONE
};
// �÷��̾� ���� 
struct tagplayer
{
	PLAYERDIRECTION _playerdirection;				//�÷��̾� ����
	PLAYERMOVE _playermove;								//�÷��̾� ������
	PLAYERARMMOVE _playerarmmove;				//�÷��̾� �� ������ 
	PLAYERPANTS _playerpants;								//�÷��̾� ���� ������
	image* _playerimg;												//�÷��̾� �̹���(��:��, ��)
	image* _playerarmimg;										//�÷��̾� �̹���(��)
	image* _playercloth;											//�÷��̾� ��
	image* _pantsimg;												//�÷��̾� ����
	RECT _playerect;													// ������ rect 
	RECT rc;																	//�ݸ��� �Լ�(�߷� �̿��� ��)
	int x;																	//�÷��̾� x 
	int y;																	//�÷��̾� y
	float speed;															//�÷��̾� ���ǵ�
	int _frameY;
	int _placount;														//�÷��̾� �̹����Ŵ����� ����� ī��Ʈ
	int _plaindex;														//�÷��̾� �̹��� �Ŵ����� ����� �ε���
	int _money;															//�÷��̾� ��
	int tileX, tileY;														//�÷��̾ ��� �ִ� ��ȣ

	bool _istool;														//���� ��� ����

};
//���� 
struct tagsword
{
	TOOLDIR _toorldir; 			//���� ����
	image* _toolimg;				//�÷��̾� �̹���
	RECT toolrc;						//RECT
	float x, y;							//���� x, y
	int _toolcount;
	int _toolindex;
};

struct  tagwatercan
{
	TOOLDIR _dir;
	image* _img;
	RECT _rc;
	int _watercount;
	int _waterindex;
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
	//�ٸ� Ŭ���� ����
	tileManager* _tilem;
	inventory* _inven;												//�κ�
	clock* _clock;														//�ð�
	tool* _tool;															//��ⱸ
	//Ŀ��
	//cusor* _cursor;


private:
	tagplayer _player;												//�÷��̾� ����
	tagplayerHpbar _hp;											//hp
	tagenergybar _energy;										//�÷��̾� ������
	tagsword _sword;													//����
	tagwatercan _can;												//���Ѹ���

	RECT rcCollision;
	RECT _attackrc;														//���� ��Ʈ ����
	RECT seedRECT;


	float time;																//TIMEMANAGER�� ����� �� 
	bool isinven;															//�����κ� �Ǵ� �κ��丮�� ����
	bool ismove;

	
public:
	Player();
	~Player();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void invenrender(HDC hdc);

	void playerkeycontrol();											//�÷��̾� Ű�� ��Ƶ� ��													
	void playermove();													//�÷��̾� ������(body)
	void playercollisionmove();									//�÷��̾� �浹 ����
	void setPlayerPosition(RECT rc);							//�÷��̾� ������ 
	void weapon();															//���� ����� ��
	void attackmove();													//��ⱸ,�ο�� ��
	void wattecanmove();												//���Ѹ���
	void playerenergybar();											//��������
	void inventorymove();												//�κ��丮
	void playerimg();														//�÷��̾� �̹��� ���� �Լ� 
	void energydamage(float _energy);						//energy������
	void hpdamage(float _hp);										//hp������

	float getplayerX() { return _player.x; }
	float getplayerY() { return _player.y; }


	int getintplayerX() { return _player.x; }
	int getintplayerY() { return _player.y; }
	void setplayerXY(int x, int y)
	{
		_player.x = x;
		_player.y = y;
	}


	RECT getPlayerrect() { return _player.rc;}
	RECT getplayermoverect() { return _player._playerect; }
	RECT getweapon() { return _attackrc; }
	RECT getSeed() { return seedRECT; }
	
	int getplayermoney() {return _player._money;}
	void setplayermoney(int _money) { _player._money = _money; }


	void setMapMemoryAdress(tileManager* tm) { _tilem = tm; }

	inventory* getinventory() { return _inven; }

	int getHp() { return _hp.Hp; }
	void setHp(int hp) { _hp.Hp = hp; }

	int getEnergy() { return _energy.energy; }
	void setEnergy(int energy) { _energy.energy = energy; }
	tool* getTool() { return _tool; }
};
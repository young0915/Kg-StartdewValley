#pragma once
#include "singletonBase.h"
#include "tileManager.h"
#include "inventory.h"
#include "clock.h"
//#include "cusor.h"
#include "progressBar.h"											//플레이어 프로그래스바
#include "tool.h"


enum PLAYERDIRECTION
{
	PLAYER_D_DOWN,
	PLAYER_D_RIGHT,
	PLAYER_D_LEFT,
	PLAYER_D_UP
};

//플레이어 움직임
enum PLAYERMOVE
{
	//플렐이어 기본 움직임
	PLAYER_DOWN,
	PLAYER_RIGHT,
	PLAYER_LEFT,
	PLAYER_UP,
	//플레이어 곡괭이, 괭이, 도끼, 낫, 검 
	PLAYER_PWR_DOWN,
	PLAYER_PWR_RIGHT,
	PLAYER_PWR_LEFT,
	PLAYER_PWR_UP,
	//플레이어 낚시
	PLAYER_PIS_DOWN,
	PLAYER_PIS_RIGHT,
	PLAYER_PIS_LEFT,
	PLAYER_PIS_UP,
	//플레이어 아이이들
	PLAYER_IDLE_DOWN,
	PLAYER_IDLE_RIGHT,
	PLAYER_IDLE_LEFT,
	PLAYER_IDLE_UP,
	PLAYER_STOP												//멈추기 위한 것
};
//플레이어 팔 움직임
enum PLAYERARMMOVE
{
	//플렐이어 기본 (팔) 움직임
	PLAYER_ARM_DOWN,
	PLAYER_ARM_RIGHT,
	PLAYER_ARM_LEFT,
	PLAYER_ARM_UP,
	//플레이어 검
	PlAYER_SWORD_DOWN,
	PlAYER_SWORD_RIGHT,
	PlAYER_SWORD_LEFT,
	PlAYER_SWORD_UP,
	//플레이어 (팔) 곡괭이, 괭이, 도끼, 낫, 검 
	PLAYER_ARM_PWR_DOWN,
	PLAYER_ARM_PWR_RIGHT,
	PLAYER_ARM_PWR_LEFT,
	PLAYER_ARM_PWR_UP,
	//플레이어  (팔) 낚시
	PLAYER_ARM_PIS_DOWN,
	PLAYER_ARM_PIS_RIGHT,
	PLAYER_ARM_PIS_LEFT,
	PLAYER_ARM_PIS_UP,
	//플레이어 물뿌리개
	PLAYER_ARM_WATCAN_DOWN,
	PLAYER_ARM_WATCAN_RIGHT,
	PLAYER_ARM_WATCAN_LEFT,
	PLAYER_ARM_WATCAN_UP,
	//멈추기
	PLAYER_ARM_IDLE_DOWN,
	PLAYER_ARM_IDLE_RIGHT,
	PLAYER_ARM_IDLE_LEFT,
	PLAYER_ARM_IDLE_UP,
	PLAYER_ARM_STOP												//멈추기 위한 것
};
//플레이어 바지 움직임
enum PLAYERPANTS
{
	//플렐이어 기본 움직임
	PLAYER_PANTS_DOWN,
	PLAYER_PANTS_RIGHT,
	PLAYER_PANTS_LEFT,
	PLAYER_PANTS_UP,
	//플레이어 곡괭이, 괭이, 도끼, 낫, 검 
	PLAYER_PANTS_PWR_DOWN,
	PLAYER_PANTS_PWR_RIGHT,
	PLAYER_PANTS_PWR_LEFT,
	PLAYER_PANTS_PWR_UP,
	//플레이어 낚시
	PLAYER_PANTS_PIS_DOWN,
	PLAYER_PANTS_PIS_RIGHT,
	PLAYER_PANTS_PIS_LEFT,
	PLAYER_PANTS_PIS_UP,
	//플레이어 물뿌리개
	PLAYER_PANTS_WATERCAN_DOWN,
	PLAYER_PANTS_WATERCAN_RIGHT,
	PLAYER_PANTS_WATERCAN_LEFT,
	PLAYER_PANTS_WATERCAN_UP,
	//플레이어 아이들
	PLAYER_PANTS_IDLE_DOWN,
	PLAYER_PANTS_IDLE_RIGHT,
	PLAYER_PANTS_IDLE_LEFT,
	PLAYER_PANTS_IDLE_UP,
	PLAYER_PANT_STOP,
	PLAYER_PANT_PWR_STOP
};

//무기 방향
enum TOOLDIR
{
	T_DOWN,
	T_RIGHT,
	T_LEFT,
	T_UP,
	T_NONE
};
// 플레이어 정보 
struct tagplayer
{
	PLAYERDIRECTION _playerdirection;				//플레이어 방향
	PLAYERMOVE _playermove;								//플레이어 움직임
	PLAYERARMMOVE _playerarmmove;				//플레이어 팔 움직임 
	PLAYERPANTS _playerpants;								//플레이어 바지 움직임
	image* _playerimg;												//플레이어 이미지(몸:얼굴, 발)
	image* _playerarmimg;										//플레이어 이미지(팔)
	image* _playercloth;											//플레이어 옷
	image* _pantsimg;												//플레이어 바지
	RECT _playerect;													// 움직임 rect 
	RECT rc;																	//콜리전 함수(발로 이용한 것)
	int x;																	//플레이어 x 
	int y;																	//플레이어 y
	float speed;															//플레이어 스피드
	int _frameY;
	int _placount;														//플레이어 이미지매니저에 사용할 카운트
	int _plaindex;														//플레이어 이미지 매니저에 사용할 인덱스
	int _money;															//플레이어 돈
	int tileX, tileY;														//플레이어가 밟고 있는 번호

	bool _istool;														//무기 사용 유무

};
//무기 
struct tagsword
{
	TOOLDIR _toorldir; 			//무기 방향
	image* _toolimg;				//플레이어 이미지
	RECT toolrc;						//RECT
	float x, y;							//무기 x, y
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

//플레이어 프로그래스바(Hp & Energy)
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
	//다른 클래스 모임
	tileManager* _tilem;
	inventory* _inven;												//인벤
	clock* _clock;														//시계
	tool* _tool;															//농기구
	//커서
	//cusor* _cursor;


private:
	tagplayer _player;												//플레이어 정보
	tagplayerHpbar _hp;											//hp
	tagenergybar _energy;										//플레이어 에너지
	tagsword _sword;													//무기
	tagwatercan _can;												//물뿌리개

	RECT rcCollision;
	RECT _attackrc;														//공격 랙트 설정
	RECT seedRECT;


	float time;																//TIMEMANAGER에 사용할 것 
	bool isinven;															//메인인벤 또는 인벤토리에 들어갔냐
	bool ismove;

	
public:
	Player();
	~Player();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void invenrender(HDC hdc);

	void playerkeycontrol();											//플레이어 키를 모아둔 곳													
	void playermove();													//플레이어 움직임(body)
	void playercollisionmove();									//플레이어 충돌 무브
	void setPlayerPosition(RECT rc);							//플레이어 포지션 
	void weapon();															//무기 사용한 곳
	void attackmove();													//농기구,싸우는 거
	void wattecanmove();												//물뿌리개
	void playerenergybar();											//에너지바
	void inventorymove();												//인벤토리
	void playerimg();														//플레이어 이미지 모음 함수 
	void energydamage(float _energy);						//energy데미지
	void hpdamage(float _hp);										//hp데미지

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
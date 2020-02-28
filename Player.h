#pragma once
#include "singletonBase.h"
//#include "progressBar.h"											//플레이어 프로그래스바
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
	PLAYER_ARM_STOP												//멈추기 위한 것
};
// 플레이어 정보 
struct tagplayer
{
	PLAYERMOVE _playermove;								//플레이어 움직임
	PLAYERARMMOVE _playerarmmove;				//플레이어 팔 움직임 
	image* _playerimg;												//플레이어 이미지(몸:얼굴, 발)
	image* _playerarmimg;										//플레이어 이미지(팔)
	RECT _playerect;													// 움직임 rect 
	float x;																	//플레이어 x 
	float y;																	//플레이어 y
	int _placount;														//플레이어 이미지매니저에 사용할 카운트
	int _plaindex;														//플레이어 이미지 매니저에 사용할 인덱스
};
//플레이어 프로그래스바(Hp & Energy)
struct tagplayerHpbar
{
};
class Player : public singletonBase<Player>
{
private:
	tagplayer _player;												//플레이어 정보
public:
	Player();
	~Player();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void playerkeycontrol();											//플레이어 키를 모아둔 곳													
	void playermove();													//플레이어 움직임(body)

	void playerimg();														//플레이어 이미지 모음 함수 
};


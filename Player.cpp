#include "stdafx.h"
#include "Player.h"


Player::Player() {}
Player::~Player() {}

HRESULT Player::init()
{
	playerimg();
	playerimg();																																																									//플레이어 이미지 모음
	_player._playerimg = IMAGEMANAGER->findImage("플레이어몸통");																															//플레이어 몸통 이미지 불러오기 
	_player._playerarmimg = IMAGEMANAGER->findImage("팔");
	_player._pantsimg = IMAGEMANAGER->findImage("바지");																																			//플레이어 바지 
	_player._playerect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());
	//_player.rc = RectMakeCenter(/*(_player._playerect.left + _player._playerect.right) / 2*/_player.x, /*(_player._playerect.top + _player._playerect.bottom) / 2 + 20*/_player.y+100, 50, 35);
	_player.speed = 100.f;

	//변수 정보
	_player._plaindex = 0;																																																					//플레이어 이미지 매니저 돌릴 index
	_player._placount = 0;																																																					//플레이어 이미지 매니저 돌릴 count

	//플레이어 움직임 초기값
	_player._playerdirection = PLAYER_D_DOWN;
	_player._playermove = PLAYER_STOP;
	_player._playerarmmove = PLAYER_ARM_STOP;
	_player._playerpants = PLAYER_PANTS_DOWN;

	//프로그래스바
	//hp
	_hp._maxhp = 100;
	_hp.Hp = 0;
	_hp._hpbar = new progressBar;
	_hp._hpbar->init("images/UI/progressbar/Ui_hp_Hp_bar_front.bmp", "images/UI/progressbar/Ui_hp_energy_bar.bmp", 850, 550, 30, 180);
	_hp._hpbar->setGauge(_hp.Hp, _hp._maxhp);
	//energy
	_energy._maxenergy = 100;
	_energy.energy = 0;
	_energy._energy = new energybar;
	_energy._energy->init("images/UI/progressbar/Ui_hp_Hp_bar_front.bmp", "images/UI/progressbar/Ui_hp_bar (1).bmp", 810, 550, 30, 180);
	_energy._energy->setGauge(_energy.energy, _energy._maxenergy);

	//다른 클래스 불러오기
	//_cursor = new cusor;
	//_cursor->init();

	return S_OK;
}

void Player::release()
{
	_hp._hpbar->release();
	_energy._energy->release();
}

void Player::update()
{
	playerkeycontrol();
	playermove();
	//	_cursor->update();
	playerenergybar();
}


void Player::playerkeycontrol()
{
	if (KEYMANAGER->isStayKeyDown('S') && _player.y < TILESIZEY - 100)
	{
		_player._playerdirection = PLAYER_D_DOWN;
		_player._playermove = PLAYER_DOWN;
		_player._playerarmmove = PLAYER_ARM_DOWN;
		_player._playerpants = PLAYER_PANTS_DOWN;
		playercollisionmove();
	//	if (CAMERA->getCameraCenter().y - WINSIZEY / 2 < TILESIZEY)CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y + 3));
	}
	if (KEYMANAGER->isStayKeyDown('D') && _player.x < CAMERA->getCameraCenter().x + WINSIZEX + (TILESIZEX - 100))
	{
		_player._playerdirection = PLAYER_D_RIGHT;
		_player._playermove = PLAYER_RIGHT;
		_player._playerarmmove = PLAYER_ARM_RIGHT;
		_player._playerpants = PLAYER_PANTS_RIGHT;
			playercollisionmove();
		//	if (CAMERA->getCameraCenter().x + WINSIZEX / 2 < TILESIZEX) CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x + 3, CAMERA->getCameraCenter().y));

	}
	if (KEYMANAGER->isStayKeyDown('A') && _player.x > 0)
	{
		_player._playerdirection = PLAYER_D_LEFT;
		_player._playermove = PLAYER_LEFT;
		_player._playerarmmove = PLAYER_ARM_LEFT;
		_player._playerpants = PLAYER_PANTS_LEFT;
		playercollisionmove();
//	if (CAMERA->getCameraCenter().x - WINSIZEX / 2 > 0)	CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x - 3, CAMERA->getCameraCenter().y));

	}
	if (KEYMANAGER->isStayKeyDown('W') && _player.y > 0)
	{
		_player._playerdirection = PLAYER_D_UP;
		_player._playermove = PLAYER_UP;
		_player._playerarmmove = PLAYER_ARM_UP;
		_player._playerpants = PLAYER_PANTS_UP;
		playercollisionmove();
	//if (CAMERA->getCameraCenter().y - WINSIZEY / 2 > 0)CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y - 3));

	}
	//멈춘 상태
	if (KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp('D'))
	{
		_player._playermove = PLAYER_STOP;
		_player._playerarmmove = PLAYER_ARM_STOP;
		_player._playerpants = PLAYER_PANT_STOP;
		_player._plaindex = 0;
		_player._playerimg->setFrameX(_player._plaindex);										// 이렇게 해야지 캐릭터 움직일 때 딱 멈춤
	}
	//'E' 인벤토리 열기 창
	//마우스 왼쪽은 사람한테 말걸기 오른쪽은 먹기 싸우기, 심기, 씬이동
}
//플레이어 움직임(body&arm&pants)
void Player::playermove()
{
	switch (_player._playerarmmove)
	{
	case PLAYER_ARM_DOWN:
		_player._placount++;
		_player._playerarmimg->setFrameY(0);
		if (_player._playermove == PLAYER_DOWN) _player._playerimg->setFrameY(0);
		if (_player._playerpants == PLAYER_PANTS_DOWN) _player._pantsimg->setFrameY(0);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_RIGHT:
		_player._placount++;
		_player._playerarmimg->setFrameY(1);
		if (_player._playermove == PLAYER_RIGHT) _player._playerimg->setFrameY(1);
		if (_player._playerpants == PLAYER_PANTS_RIGHT) _player._pantsimg->setFrameY(1);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_LEFT:
		_player._placount++;
		_player._playerarmimg->setFrameY(2);
		if (_player._playermove == PLAYER_LEFT) _player._playerimg->setFrameY(2);
		if (_player._playerpants == PLAYER_PANTS_LEFT) _player._pantsimg->setFrameY(2);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_UP:
		_player._placount++;
		_player._playerarmimg->setFrameY(3);
		if (_player._playermove == PLAYER_UP) _player._playerimg->setFrameY(3);
		if (_player._playerpants == PLAYER_PANTS_UP) _player._pantsimg->setFrameY(3);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PlAYER_SWORD_DOWN:
		_player._placount++;
		_player._playerarmimg->setFrameY(4);
		if (_player._playermove == PLAYER_PWR_DOWN) _player._playerimg->setFrameY(4);
		if (_player._playerpants == PLAYER_ARM_PWR_DOWN) _player._pantsimg->setFrameY(4);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX())
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX())
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PlAYER_SWORD_RIGHT:
		_player._placount++;
		_player._playerarmimg->setFrameY(5);
		if (_player._playermove == PLAYER_PWR_RIGHT) _player._playerimg->setFrameY(5);
		if (_player._playerpants == PLAYER_PANTS_PWR_RIGHT) _player._pantsimg->setFrameY(5);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX())
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX())
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PlAYER_SWORD_LEFT:
		_player._placount++;
		_player._playerarmimg->setFrameY(6);
		if (_player._playermove == PLAYER_PWR_LEFT) _player._playerimg->setFrameY(6);
		if (_player._playerpants == PLAYER_PANTS_PWR_LEFT) _player._pantsimg->setFrameY(6);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX())
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX())
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PlAYER_SWORD_UP:
		_player._placount++;
		_player._playerarmimg->setFrameY(7);
		if (_player._playermove == PLAYER_PWR_UP) _player._playerimg->setFrameY(7);
		if (_player._playerpants == PLAYER_PANTS_PWR_UP) _player._pantsimg->setFrameY(7);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX())
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX())
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;




	case PLAYER_ARM_PWR_DOWN:
		_player._placount++;
		_player._playerarmimg->setFrameY(8);
		if (_player._playermove == PLAYER_PWR_DOWN) _player._playerimg->setFrameY(4);
		if (_player._playerpants == PLAYER_ARM_PWR_DOWN) _player._pantsimg->setFrameY(4);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PWR_RIGHT:
		_player._placount++;
		_player._playerarmimg->setFrameY(9);
		if (_player._playermove == PLAYER_PWR_RIGHT) _player._playerimg->setFrameY(5);
		if (_player._playerpants == PLAYER_PANTS_PWR_RIGHT) _player._pantsimg->setFrameY(5);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PWR_LEFT:
		_player._placount++;
		_player._playerarmimg->setFrameY(10);
		if (_player._playermove == PLAYER_PWR_LEFT) _player._playerimg->setFrameY(6);
		if (_player._playerpants == PLAYER_PANTS_PWR_LEFT) _player._pantsimg->setFrameY(6);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PWR_UP:
		_player._placount++;
		_player._playerarmimg->setFrameY(11);
		if (_player._playermove == PLAYER_PWR_UP) _player._playerimg->setFrameY(7);
		if (_player._playerpants == PLAYER_PANTS_PWR_UP) _player._pantsimg->setFrameY(7);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PIS_DOWN:
		_player._placount++;
		_player._playerarmimg->setFrameY(12);
		if (_player._playermove == PLAYER_PIS_DOWN) _player._playerimg->setFrameY(8);
		if (_player._playerpants == PLAYER_PANTS_PIS_DOWN) _player._pantsimg->setFrameY(8);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PIS_RIGHT:
		_player._placount++;
		_player._playerarmimg->setFrameY(13);
		if (_player._playermove == PLAYER_PIS_RIGHT) _player._playerimg->setFrameY(9);
		if (_player._playerpants == PLAYER_PANTS_PIS_RIGHT) _player._pantsimg->setFrameY(9);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PIS_LEFT:
		_player._placount++;
		_player._playerarmimg->setFrameY(14);
		if (_player._playermove == PLAYER_PIS_LEFT) _player._playerimg->setFrameY(10);
		if (_player._playerpants == PLAYER_PANTS_PIS_LEFT) _player._pantsimg->setFrameY(10);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_PIS_UP:
		_player._placount++;
		_player._playerarmimg->setFrameY(15);
		if (_player._playermove == PLAYER_PIS_UP) _player._playerimg->setFrameY(11);
		if (_player._playerpants == PLAYER_PANTS_PIS_UP) _player._pantsimg->setFrameY(11);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_WATCAN_DOWN:
		_player._placount++;
		_player._playerarmimg->setFrameY(16);
		if (_player._playermove == PLAYER_PWR_DOWN) _player._playerimg->setFrameY(12);
		if (_player._playerpants == PLAYER_PANTS_WATERCAN_DOWN) _player._pantsimg->setFrameY(12);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_WATCAN_RIGHT:
		_player._placount++;
		_player._playerarmimg->setFrameY(17);
		if (_player._playermove == PLAYER_PWR_RIGHT) _player._playerimg->setFrameY(13);
		if (_player._playerpants == PLAYER_PANTS_WATERCAN_RIGHT) _player._pantsimg->setFrameY(13);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_WATCAN_LEFT:
		_player._placount++;
		_player._playerarmimg->setFrameY(18);
		if (_player._playermove == PLAYER_PWR_LEFT) _player._playerimg->setFrameY(14);
		if (_player._playerpants == PLAYER_PANTS_WATERCAN_LEFT) _player._pantsimg->setFrameY(14);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_WATCAN_UP:
		_player._placount++;
		_player._playerarmimg->setFrameY(19);
		if (_player._playermove == PLAYER_PWR_UP) _player._playerimg->setFrameY(14);
		if (_player._playerpants == PLAYER_ARM_WATCAN_UP) _player._pantsimg->setFrameY(15);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	}
}


void Player::setPlayerPosition(RECT rc)
{
	_player.rc = rc;
	_player.x = _player.rc.left + (_player.rc.right - _player.rc.left)/2;
	_player.y = _player.rc.top + (_player.rc.bottom - _player.rc.top) / 2;
}

void Player::playercollisionmove()
{
	RECT rcCollision;
	int tileIndex[2];//검사용 타일

	rcCollision = _player.rc;//가상의 렉트

	//타임매니저를 이용한 방법
	float elpasedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elpasedTime * _player.speed;

	//일단 무조건 이동ㄱㄱ
	switch (_player._playerdirection)
	{
	case PLAYER_D_DOWN:
		_player.y += moveSpeed;
		//rcCollision = RectMakeCenter(_player.x, _player.y, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());
		rcCollision = RectMakeCenter(_player.x, _player.y, 50, 30);
		break;
	case PLAYER_D_RIGHT:
		_player.x += moveSpeed;
		rcCollision = RectMakeCenter(_player.x, _player.y, 50, 30);
		break;
	case PLAYER_D_LEFT:
		_player.x -= moveSpeed;
		rcCollision = RectMakeCenter(_player.x, _player.y, 50, 30);
		break;
	case PLAYER_D_UP:
		_player._frameY = 3;
		_player.y -= moveSpeed;
		rcCollision = RectMakeCenter(_player.x, _player.y, 50, 30);
		break;
	}//end of switch(_direction)

 //타일 번호를 알아오자.
	_player.tileX = rcCollision.left / TILESIZE;
	_player.tileY = rcCollision.top / TILESIZE;


	switch (_player._playerdirection)
	{
	case PLAYER_D_DOWN:
		tileIndex[0] = (_player.tileX + _player.tileY* TILEX) + TILEX;
		tileIndex[1] = (_player.tileX + 1 + _player.tileY* TILEX) + TILEX;
		break;
	case PLAYER_D_RIGHT:
		tileIndex[0] = (_player.tileX + _player.tileY* TILEX) + 1;
		tileIndex[1] = (_player.tileX + (_player.tileY + 1)*TILEX) + 1;
		break;
	case PLAYER_D_LEFT:
		tileIndex[0] = _player.tileX + _player.tileY*TILEX;
		tileIndex[1] = _player.tileX + (_player.tileY + 1)* TILEX;
		break;
	case PLAYER_D_UP:
		tileIndex[0] = _player.tileX + _player.tileY*TILEX;
		tileIndex[1] = _player.tileX + 1 + _player.tileY * TILEX;
		break;
	}//end of switch(_direction)

	for (int i = 0; i < 2; i++)
	{
		RECT rc;
		//해당타일의 속성이 움직이지 못하는 곳이면....
		if (((_tilem->getAttribute()[tileIndex[i]] & ATTR_UNMOVABLE) == ATTR_UNMOVABLE) &&
			IntersectRect(&rc, &_tilem->getMap()[tileIndex[i]].rc, &rcCollision))
		{
			//움직이려 할때 갈수 없는 지역이면 탱크의 움직임을 고정하자
			//ex)땅크가 왼쪽으로갈때 왼쪽지역이 갈수 없으면
			switch (_player._playerdirection)
			{
			case PLAYER_D_DOWN:
				_player._playerect.bottom = _tilem->getMap()[tileIndex[i]].rc.top;
				_player._playerect.top = _player._playerect.bottom - _player._playerimg->getFrameHeight();
				_player.y = _player._playerect.top + (_player._playerect.bottom - _player._playerect.top);
				break;
			case PLAYER_D_RIGHT:
				_player._playerect.right = _tilem->getMap()[tileIndex[i]].rc.left;
				_player._playerect.left = _player._playerect.right - _player._playerimg->getFrameWidth();
				_player.x = _player._playerect.left + (_player._playerect.right - _player._playerect.left);
				break;
			case PLAYER_D_LEFT:
				_player._playerect.left = _tilem->getMap()[tileIndex[i]].rc.left;
				_player._playerect.right = _player._playerect.left - _player._playerimg->getFrameWidth();
				_player.x = _player._playerect.left + (_player._playerect.right - _player._playerect.left);
				break;
			case PLAYER_D_UP:
				_player._playerect.top = _tilem->getMap()[tileIndex[i]].rc.bottom;
				_player._playerect.bottom = _player._playerect.top - _player._playerimg->getFrameHeight();
				_player.y = _player._playerect.top + (_player._playerect.bottom - _player._playerect.top);
				break;
			}
			return;
		}
	}//end of for
	//움직이자
	rcCollision = RectMakeCenter(_player.x, _player.y, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());
	_player.rc = rcCollision;
}

void Player::playerenergybar()
{
	_hp._hpbar->setGauge(_hp.Hp, _hp._maxhp);
	_energy._energy->setGauge(_energy.energy, _energy._maxenergy);
}

void Player::energydamage(float _energy)
{
	_hp.Hp += _energy;
	/*
	최대가 max 95까지 95일 경우 플레이어는 쓰러진다.
	*/
}

void Player::hpdamage(float _hp)
{
	_energy.energy += _hp;
	/*
최대가 max 95까지 95일 경우 플레이어는 쓰러진다.
*/
}

void Player::render(HDC hdc)
{
	_player._pantsimg->frameRender(hdc, _player.rc.left, _player.rc.top);							//캐릭터 바지 
	_player._playerimg->frameRender(hdc, _player.rc.left, _player.rc.top); 					//몸통 얼굴
	_player._playerarmimg->frameRender(hdc, _player.rc.left, _player.rc.top);						//팔
	//Rectangle(hdc, _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
		//_cursor->render();																										//커서
	_hp._hpbar->render();																								//에너지바
	_energy._energy->render();																							//혈액
}
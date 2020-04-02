#include "stdafx.h"
#include "Player.h"


Player::Player() {}
Player::~Player() {}

HRESULT Player::init()
{
	playerimg();			//플레이어 이미지 모음
	_player._playerimg = IMAGEMANAGER->findImage("플레이어몸통");																															//플레이어 몸통 이미지 불러오기 
	_player._playerarmimg = IMAGEMANAGER->findImage("팔");
	_player._pantsimg = IMAGEMANAGER->findImage("바지");																																			//플레이어 바지 

	_player._playerect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());

	_player.speed = 200.f;

	//변수 정보
	_player._plaindex = 0;																																																					//플레이어 이미지 매니저 돌릴 index
	_player._placount = 0;																																																					//플레이어 이미지 매니저 돌릴 count
	_player._money = 9999;																																																				//플레이어 돈 

	ismove = true;


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

	//농기구인가 아니면 그냥 이동인가
	//ismove = false;
	_sword._toorldir = T_NONE;
	_sword._toolimg = IMAGEMANAGER->findImage("칼");
	_sword._toolcount = 0;
	_sword._toolindex = 0;

	//물뿌리개 
	_can._dir = T_NONE;
	_can._img = IMAGEMANAGER->findImage("물뿌리개");
	_can._watercount = 0;
	_can._waterindex = 0;

	_attackrc = RectMakeCenter(_player.x, _player.y, 50, 50);
	seedRECT = RectMakeCenter(0, 0, 0, 0);
	//다른 클래스 불러오기
	//_cursor = new cusor;
	//_cursor->init();

	_inven = new inventory;
	_inven->init();

	isinven = false;

	_clock = new clock;
	_clock->init();

	_tool = new tool;
	_tool->init();

	return S_OK;
}

void Player::release(){}

void Player::update()
{
	
		playerkeycontrol();
		playerenergybar();
		playermove();
		attackmove();
		weapon();
		wattecanmove();
		//	_cursor->update();
		_clock->update();
	 inventorymove();									//인벤토리
	 if (KEYMANAGER->isOnceKeyDown('6') || KEYMANAGER->isOnceKeyDown('7') /*|| KEYMANAGER->isOnceKeyDown('8') || KEYMANAGER->isOnceKeyDown('9')*/)
	 {
		
			 if (_player._playerdirection == PLAYER_D_DOWN)
			 {
				 seedRECT = RectMakeCenter(_player.x, _player.y + 50, 40, 40);
			 }
			 if (_player._playerdirection == PLAYER_D_RIGHT)
			 {
				 seedRECT = RectMakeCenter(_player.x+40, _player.y + 20, 40, 40);
			 }
			 if (_player._playerdirection == PLAYER_D_LEFT)
			 {
				 seedRECT = RectMakeCenter(_player.x - 40, _player.y + 20, 40, 40);
			 }
			 _inven->createseed();
			 _inven->seteat(false);
		
	 }
	 if (KEYMANAGER->isOnceKeyDown('9'))
	 {
		 _inven->seteat(true);
		 _inven->createseed();
		 _inven->setOpen(false);
	}


	 if (KEYMANAGER->isOnceKeyUp('6') || KEYMANAGER->isOnceKeyUp('7') || KEYMANAGER->isOnceKeyUp('8') || KEYMANAGER->isOnceKeyUp('9'))
	 {
		 if (_player._playerdirection == PLAYER_D_DOWN || _player._playerdirection == PLAYER_D_RIGHT || _player._playerdirection == PLAYER_D_LEFT) seedRECT = RectMakeCenter(-50, -50, 0, 0);
	 }
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
		}
		if (KEYMANAGER->isStayKeyDown('D') && _player.x <1500/* CAMERA->getCameraCenter().x + WINSIZEX + (TILESIZEX - 100)*/)
		{
			_player._playerdirection = PLAYER_D_RIGHT;
			_player._playermove = PLAYER_RIGHT;
			_player._playerarmmove = PLAYER_ARM_RIGHT;
			_player._playerpants = PLAYER_PANTS_RIGHT;
			playercollisionmove();
		}
		if (KEYMANAGER->isStayKeyDown('A') && _player.x > 0 )
		{
			_player._playerdirection = PLAYER_D_LEFT;
			_player._playermove = PLAYER_LEFT;
			_player._playerarmmove = PLAYER_ARM_LEFT;
			_player._playerpants = PLAYER_PANTS_LEFT;
			playercollisionmove();
		}
		if (KEYMANAGER->isStayKeyDown('W') && _player.y > 0)
		{
			_player._playerdirection = PLAYER_D_UP;
			_player._playermove = PLAYER_UP;
			_player._playerarmmove = PLAYER_ARM_UP;
			_player._playerpants = PLAYER_PANTS_UP;
			playercollisionmove();
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

		//카메라
		if (_player.x > WINSIZEX / 2)
		{
			CAMERA->setCameraCenter(PointMake(_player.x+20, CAMERA->getCameraCenter().y));
		}
		if(_player.y >WINSIZEY/2)
		{
			CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x,_player.y	));
		}
	_player.rc = RectMakeCenter(_player.x, _player.y, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());
	//'E' 인벤토리 열기 창dd
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
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
		_player._playerarmimg->setFrameY(18);
		if (_player._playermove == PLAYER_PWR_RIGHT) _player._playerimg->setFrameY(13);
		if (_player._playerpants == PLAYER_PANTS_WATERCAN_RIGHT) _player._pantsimg->setFrameY(13);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
		_player._playerarmimg->setFrameY(17);
		if (_player._playermove == PLAYER_PWR_LEFT) _player._playerimg->setFrameY(14);
		if (_player._playerpants == PLAYER_PANTS_WATERCAN_LEFT) _player._pantsimg->setFrameY(14);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
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
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 3)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_IDLE_DOWN:
		_player._placount++;
		_player._playerarmimg->setFrameY(0);
		if (_player._playermove == PLAYER_IDLE_DOWN) _player._playerimg->setFrameY(0);
		if (_player._playerpants == PLAYER_PANTS_IDLE_DOWN) _player._pantsimg->setFrameY(0);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 5)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 5)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 5)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_ARM_IDLE_RIGHT:
		_player._placount++;
		_player._playerarmimg->setFrameY(1);
		if (_player._playermove == PLAYER_IDLE_RIGHT) _player._playerimg->setFrameY(1);
		if (_player._playerpants == PLAYER_PANTS_IDLE_RIGHT) _player._pantsimg->setFrameY(1);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 5)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 5)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 5)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	
	case PLAYER_ARM_IDLE_LEFT:
		_player._placount++;
		_player._playerarmimg->setFrameY(2);
		if (_player._playermove == PLAYER_IDLE_LEFT) _player._playerimg->setFrameY(2);
		if (_player._playerpants == PLAYER_PANTS_IDLE_LEFT) _player._pantsimg->setFrameY(2);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 5)
		{
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 5)
			{
				if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 5)
				{
					_player._plaindex = 0;
				}
			}
		}
		_player._playerarmimg->setFrameX(_player._plaindex);
		_player._playerimg->setFrameX(_player._plaindex);
		_player._pantsimg->setFrameX(_player._plaindex);
		break;
	//case PLAYER_ARM_IDLE_UP :
	//	_player._playerarmimg->setFrameX(3);
	//	if (_player._playermove == PLAYER_IDLE_UP)_player._playerimg->setFrameX(3);
	//	if (_player._playerpants == PLAYER_PANTS_IDLE_UP)_player._pantsimg->setFrameX(3);
	//	if (_player._placount % 7 == 0)
	//	{
	//		_player._placount = 0;
	//		_player._plaindex++;
	//	}
	//	if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 5)
	//	{
	//		if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 5)
	//		{
	//			if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 5)
	//			{
	//				_player._plaindex = 0;
	//			}
	//		}
	//	}
	//	_player._playerarmimg->setFrameX(_player._plaindex);
	//	_player._playerimg->setFrameX(_player._plaindex);
	//	_player._pantsimg->setFrameX(_player._plaindex);
	//	break;
	}
}

//속성때문에 셋팅
void Player::setPlayerPosition(RECT rc)
{
	_player.rc = rc;
	_player.x = _player.rc.left + (_player.rc.right - _player.rc.left) / 2;
	_player.y = _player.rc.top + (_player.rc.bottom - _player.rc.top) / 2;
}

void Player::weapon()
{
	switch (_sword._toorldir)
	{
	case T_DOWN:
		_sword._toolcount++;
		_sword._toolimg->setFrameY(0);
		if (_sword._toolcount % 10 == 0)
		{
			_sword._toolcount = 0; 
			_sword._toolindex++;
			if (_sword._toolindex >= _sword._toolimg->getMaxFrameX())
			{
				_sword._toolindex = 0;
			}
		}
		_sword._toolimg->setFrameX(_sword._toolindex);
		break;
	case T_RIGHT:
		_sword._toolcount++;
		_sword._toolimg->setFrameY(1);
		if (_sword._toolcount % 10 == 0)
		{
			_sword._toolcount = 0;
			_sword._toolindex++;
			if (_sword._toolindex >= _sword._toolimg->getMaxFrameX())
			{
				_sword._toolindex = 0;
			}
		}
		_sword._toolimg->setFrameX(_sword._toolindex);
		break;
	case T_LEFT:
		_sword._toolcount++;
		_sword._toolimg->setFrameY(2);
		if (_sword._toolcount % 10 == 0)
		{
			_sword._toolcount = 0;
			_sword._toolindex++;
			if (_sword._toolindex >= _sword._toolimg->getMaxFrameX())
			{
				_sword._toolindex = 0;
			}
		}
		_sword._toolimg->setFrameX(_sword._toolindex);
		break;
	case T_UP:
		_sword._toolcount++;
		_sword._toolimg->setFrameY(3);
		if (_sword._toolcount % 10 == 0)
		{
			_sword._toolcount = 0;
			_sword._toolindex++;
			if (_sword._toolindex >= _sword._toolimg->getMaxFrameX())
			{
				_sword._toolindex = 0;
			}
		}
		_sword._toolimg->setFrameX(_sword._toolindex);
		break;
	case T_NONE:
		_sword._toolcount++;
		_sword._toolimg->setFrameY(4);
		if (_sword._toolcount % 10 == 0)
		{
			_sword._toolcount = 0;
			_sword._toolindex++;
			if (_sword._toolindex >= _sword._toolimg->getMaxFrameX())
			{
				_sword._toolindex = 0;
			}
		}
		_sword._toolimg->setFrameX(_sword._toolindex);
		break;
	}
}

void Player::attackmove()
{
	//물뿌리개
	if (KEYMANAGER->isStayKeyDown('1'))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_player._playerdirection == PLAYER_D_RIGHT)
			{
				_can._dir = T_RIGHT;
				_player._playermove = PLAYER_PIS_RIGHT;
				_player._playerarmmove = PLAYER_ARM_PIS_RIGHT;
				_player._playerpants = PLAYER_PANTS_PIS_RIGHT;
				_attackrc = RectMakeCenter(_player.x + 50, _player.y + 25, 50, 50);
			}
			if (_player._playerdirection == PLAYER_D_LEFT)
			{
				_can._dir = T_LEFT;
				_player._playermove = PLAYER_PIS_LEFT;
				_player._playerarmmove = PLAYER_ARM_PIS_LEFT;
				_player._playerpants = PLAYER_PANTS_PIS_LEFT;
				_attackrc = RectMakeCenter(_player.x - 50, _player.y + 25, 50, 50);
			}
			if (_player._playerdirection == PLAYER_D_DOWN)
			{
				_can._dir = T_DOWN;
				_player._playermove = PLAYER_PIS_DOWN;
				_player._playerarmmove = PLAYER_ARM_PIS_DOWN;
				_player._playerpants = PLAYER_PANTS_PIS_DOWN;
				_attackrc = RectMakeCenter(_player.x, _player.y - 50, 50, 50);
			}
			//PLAYER_ARM_PIS_UP
			//PLAYER_PIS_UP
			//PLAYER_PANTS_PIS_UP
		}
	}
	if (KEYMANAGER->isOnceKeyUp('1'))
	{
		_can._dir = T_NONE;
		if (_player._playermove == PLAYER_PWR_RIGHT && _player._playerarmmove == PLAYER_ARM_WATCAN_RIGHT && _player._playerpants == PLAYER_PANTS_PWR_RIGHT)
		{
			_player._playerarmmove = PLAYER_ARM_IDLE_RIGHT;
			_player._playermove == PLAYER_IDLE_RIGHT;
			_player._playerpants == PLAYER_PANTS_IDLE_RIGHT;
		}
		else if (_player._playermove == PLAYER_PWR_LEFT && _player._playerarmmove == PLAYER_ARM_WATCAN_LEFT && _player._playerpants == PLAYER_PANTS_PWR_LEFT)
		{
			_player._playermove = PLAYER_IDLE_LEFT;
			_player._playerarmmove = PLAYER_ARM_IDLE_LEFT;
			_player._playerpants = PLAYER_PANTS_IDLE_LEFT;
		}
		else
		{
			_player._playermove = PLAYER_IDLE_DOWN;
			_player._playerarmmove = PLAYER_ARM_IDLE_DOWN;
			_player._playerpants = PLAYER_PANTS_IDLE_DOWN;
		}
		_attackrc = RectMakeCenter(0, 0, 0, 0);
	}

	//낫
	if (KEYMANAGER->isStayKeyDown('2'))
	{
		if (_player._playerdirection == PLAYER_D_RIGHT)
		{
			_player._playermove = PLAYER_PWR_RIGHT;
			_player._playerarmmove = PlAYER_SWORD_RIGHT;
			_player._playerpants = PLAYER_PANTS_PWR_RIGHT;
			_sword._toorldir = T_RIGHT;
			_attackrc = RectMakeCenter(_player.x + 50, _player.y + 25, 50, 50);
		}
		if (_player._playerdirection == PLAYER_D_LEFT)
		{
			_player._playermove = PLAYER_PWR_LEFT;
			_player._playerarmmove = PlAYER_SWORD_LEFT;
			_player._playerpants = PLAYER_PANTS_PWR_LEFT;
			_sword._toorldir = T_LEFT;
			_attackrc = RectMakeCenter(_player.x - 50, _player.y + 25, 50, 50);
		}
		if (_player._playerdirection == PLAYER_D_DOWN)
		{
			_player._playermove = PLAYER_PWR_DOWN;
			_player._playerarmmove = PlAYER_SWORD_DOWN;
			_player._playerpants = PLAYER_PANTS_PWR_DOWN;
			_sword._toorldir = T_DOWN;
			_attackrc = RectMakeCenter(_player.x, _player.y + 50, 50, 50);
		}
	}
	if (KEYMANAGER->isOnceKeyUp('2'))
	{
		_sword._toorldir = T_NONE;
		if (_player._playermove == PLAYER_PWR_RIGHT && _player._playerarmmove == PlAYER_SWORD_RIGHT && _player._playerpants == PLAYER_PANTS_PWR_RIGHT)
		{
			_player._playerarmmove = PLAYER_ARM_IDLE_RIGHT;
			_player._playermove == PLAYER_IDLE_RIGHT;
			_player._playerpants == PLAYER_PANTS_IDLE_RIGHT;
		}

		else if (_player._playermove == PLAYER_PWR_LEFT && _player._playerarmmove == PlAYER_SWORD_LEFT && _player._playerpants == PLAYER_PANTS_PWR_LEFT)
		{
			_player._playermove = PLAYER_IDLE_LEFT;
			_player._playerarmmove = PLAYER_ARM_IDLE_LEFT;
			_player._playerpants = PLAYER_PANTS_IDLE_LEFT;
		}
		else
		{
			_player._playermove = PLAYER_IDLE_DOWN;
			_player._playerarmmove = PLAYER_ARM_IDLE_DOWN;
			_player._playerpants = PLAYER_PANTS_IDLE_DOWN;

		}
		_attackrc = RectMakeCenter(0, 0, 0, 0);
	}
	//도끼
	if (KEYMANAGER->isStayKeyDown('3'))
	{
			if (_player._playerdirection == PLAYER_D_RIGHT)
			{
				_player._playermove = PLAYER_PIS_RIGHT;
				_player._playerarmmove = PLAYER_ARM_PIS_RIGHT;
				_player._playerpants = PLAYER_PANTS_PWR_RIGHT;
				_tool->axemove(_player.x, _player.y, TOOL_AXE, TT_RIGHT);
			}
			if (_player._playerdirection == PLAYER_D_LEFT)
			{
				_player._playermove = PLAYER_PIS_LEFT;
				_player._playerarmmove = PLAYER_ARM_PIS_LEFT;
				_player._playerpants = PLAYER_PANTS_PWR_LEFT;
				_tool->axemove(_player.x, _player.y, TOOL_AXE, TT_LEFT);
			}
	}
	if (KEYMANAGER->isOnceKeyUp('3'))
	{
		_tool->axemove(-50, -50, TOOL_AXE, TT_NONE);
		if (_player._playermove == PLAYER_PIS_RIGHT && _player._playerarmmove == PLAYER_ARM_PIS_RIGHT && _player._playerpants == PLAYER_PANTS_PWR_RIGHT)
		{
			_player._playerarmmove = PLAYER_ARM_IDLE_RIGHT;
			_player._playermove == PLAYER_IDLE_RIGHT;
			_player._playerpants == PLAYER_PANTS_IDLE_RIGHT;
		}
		else
		{
			_player._playermove = PLAYER_IDLE_LEFT;
			_player._playerarmmove = PLAYER_ARM_IDLE_LEFT;
			_player._playerpants = PLAYER_PANTS_IDLE_LEFT;
		}
	}
	//곡괭이
	if (KEYMANAGER->isStayKeyDown('4'))
	{
			if (_player._playerdirection == PLAYER_D_RIGHT)
			{
				_player._playermove = PLAYER_PIS_RIGHT;
				_player._playerarmmove = PLAYER_ARM_PIS_RIGHT;
				_player._playerpants = PLAYER_PANTS_PWR_RIGHT;
			_tool->pickaxemove(_player.x + 15, _player.y + 35, TOOL_PICKAXE, TT_RIGHT);
			}
			if (_player._playerdirection == PLAYER_D_LEFT)
			{
				_player._playermove = PLAYER_PIS_LEFT;
				_player._playerarmmove = PLAYER_ARM_PIS_LEFT;
				_player._playerpants = PLAYER_PANTS_PWR_LEFT;
				_tool->pickaxemove(_player.x - 15, _player.y + 35, TOOL_PICKAXE, TT_LEFT);
			}
			if (_player._playerdirection == PLAYER_D_DOWN)
			{
				_player._playermove = PLAYER_PIS_DOWN;
				_player._playerarmmove = PLAYER_ARM_PIS_DOWN;
				_player._playerpants = PLAYER_PANTS_PWR_DOWN;
				_tool->pickaxemove(_player.x, _player.y + 50, TOOL_PICKAXE, TT_DOWN);
			}
	}
	if (KEYMANAGER->isOnceKeyUp('4'))
	{
		_tool->pickaxemove(-50, -50, TOOL_PICKAXE, TT_NONE);
		if (_player._playermove == PLAYER_PIS_RIGHT && _player._playerarmmove == PLAYER_ARM_PIS_RIGHT && _player._playerpants == PLAYER_PANTS_PWR_RIGHT)
		{
			_player._playerarmmove = PLAYER_ARM_IDLE_RIGHT;
			_player._playermove == PLAYER_IDLE_RIGHT;
			_player._playerpants == PLAYER_PANTS_IDLE_RIGHT;
		}
		else	if (_player._playermove == PLAYER_PIS_LEFT && _player._playerarmmove == PLAYER_ARM_PIS_LEFT && _player._playerpants == PLAYER_PANTS_PWR_LEFT)
		{
			_player._playermove = PLAYER_IDLE_LEFT;
			_player._playerarmmove = PLAYER_ARM_IDLE_LEFT;
			_player._playerpants = PLAYER_PANTS_IDLE_LEFT;
		}
		else
		{
			_player._playermove = PLAYER_IDLE_DOWN;
			_player._playerarmmove = PLAYER_ARM_IDLE_DOWN;
			_player._playerpants = PLAYER_PANTS_IDLE_DOWN;
		}
	}
	if (KEYMANAGER->isStayKeyDown('5'))
	{
		if (_player._playerdirection == PLAYER_D_RIGHT)
		{
			_player._playermove = PLAYER_PIS_RIGHT;
			_player._playerarmmove = PLAYER_ARM_PIS_RIGHT;
			_player._playerpants = PLAYER_PANTS_PWR_RIGHT;
			_tool->homemove(_player.x + 15, _player.y + 35, TOOL_HOE, TT_RIGHT);
		}
		if (_player._playerdirection == PLAYER_D_LEFT)
		{
			_player._playermove = PLAYER_PIS_LEFT;
			_player._playerarmmove = PLAYER_ARM_PIS_LEFT;
			_player._playerpants = PLAYER_PANTS_PWR_LEFT;
			_tool->homemove(_player.x - 15, _player.y + 35, TOOL_HOE, TT_LEFT);
		}
		if (_player._playerdirection == PLAYER_D_DOWN)
		{
			_player._playermove = PLAYER_PIS_DOWN;
			_player._playerarmmove = PLAYER_ARM_PIS_DOWN;
			_player._playerpants = PLAYER_PANTS_PWR_DOWN;
			_tool->homemove(_player.x, _player.y + 50, TOOL_HOE, TT_DOWN);
		}
	}
	if (KEYMANAGER->isOnceKeyUp('5'))
	{
		_tool->homemove(-50, -50, TOOL_HOE, TT_NONE);
		if (_player._playermove == PLAYER_PIS_RIGHT && _player._playerarmmove == PLAYER_ARM_PIS_RIGHT && _player._playerpants == PLAYER_PANTS_PWR_RIGHT)
		{
			_player._playerarmmove = PLAYER_ARM_IDLE_RIGHT;
			_player._playermove == PLAYER_IDLE_RIGHT;
			_player._playerpants == PLAYER_PANTS_IDLE_RIGHT;
		}
		else	if (_player._playermove == PLAYER_PIS_LEFT && _player._playerarmmove == PLAYER_ARM_PIS_LEFT && _player._playerpants == PLAYER_PANTS_PWR_LEFT)
		{
			_player._playermove = PLAYER_IDLE_LEFT;
			_player._playerarmmove = PLAYER_ARM_IDLE_LEFT;
			_player._playerpants = PLAYER_PANTS_IDLE_LEFT;
		}
		else
		{
			_player._playermove = PLAYER_IDLE_DOWN;
			_player._playerarmmove = PLAYER_ARM_IDLE_DOWN;
			_player._playerpants = PLAYER_PANTS_IDLE_DOWN;
		}
	}
}

//물뿌리개
void Player::wattecanmove()
{
	switch (_can._dir)
	{
	case T_DOWN:
		_can._watercount++;
		_can._img->setFrameY(0);
		if (_can._watercount % 5 == 0)
		{
			_can._watercount = 0;
			_can._waterindex++;
			if (_can._waterindex >= _can._img->getMaxFrameX())
			{
				_can._waterindex = 0;
			}
		}
		_can._img->setFrameX(_can._waterindex);
		break;
	case T_RIGHT:
		_can._watercount++;
		_can._img->setFrameY(1);
		if (_can._watercount % 5 == 0)
		{
			_can._watercount = 0;
			_can._waterindex++;
			if (_can._waterindex >= _can._img->getMaxFrameX())
			{
				_can._waterindex = 0;
			}
		}
		_can._img->setFrameX(_can._waterindex);
		break;
	case T_LEFT:
		_can._watercount++;
		_can._img->setFrameY(2);
		if (_can._watercount % 5 == 0)
		{
			_can._watercount = 0;
			_can._waterindex++;
			if (_can._waterindex >= _can._img->getMaxFrameX())
			{
				_can._waterindex = 0;
			}
		}
		_can._img->setFrameX(_can._waterindex);
		break;
	case T_UP:
		_can._watercount++;
		_can._img->setFrameY(3);
		if (_can._watercount % 5 == 0)
		{
			_can._watercount = 0;
			_can._waterindex++;
			if (_can._waterindex >= _can._img->getMaxFrameX())
			{
				_can._waterindex = 0;
			}
		}
		_can._img->setFrameX(_can._waterindex);
		break;
	case T_NONE:
		_can._watercount++;
		_can._img->setFrameY(4);
		if (_can._watercount % 5 == 0)
		{
			_can._watercount = 0;
			_can._waterindex++;
			if (_can._waterindex >= _can._img->getMaxFrameX())
			{
				_can._waterindex = 0;
			}
		}
		_can._img->setFrameX(_can._waterindex);
		break;
	}
}
//함수의 끝

void Player::playercollisionmove()
{
	int tileIndex[2];//검사용 타일


	//타임매니저를 이용한 방법
	float elpasedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elpasedTime * _player.speed;

	//일단 무조건 이동ㄱㄱ
	switch (_player._playerdirection)
	{
	case PLAYER_D_DOWN:
		//	_player.y += moveSpeed;
		rcCollision = RectMake(_player.x, _player.rc.bottom, 30, 4);
		break;
	case PLAYER_D_RIGHT:
		//	_player.x += moveSpeed;
		rcCollision = RectMake(_player.rc.right + 10, _player.y, 4, 30);
		break;
	case PLAYER_D_LEFT:
		//_player.x -= moveSpeed;
		rcCollision = RectMake(_player.rc.left - 10, _player.y, 4, 30);
		break;
	case PLAYER_D_UP:
		//_player.y -= moveSpeed;
		rcCollision = RectMake(_player.x, _player.rc.top, 30, 4);
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
		tileIndex[0] = _player.tileX + _player.tileY * TILEX;
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
		if ((_tilem->getMap()[tileIndex[i]].obj == OBJ_WALL &&
			IntersectRect(&rc, &_tilem->getMap()[tileIndex[i]].rc, &rcCollision))) return;

	}//end of for

	switch (_player._playerdirection)
	{
	case PLAYER_D_DOWN:
		_player.y += moveSpeed;
		break;
	case PLAYER_D_RIGHT:
		_player.x += moveSpeed;
		break;
	case PLAYER_D_LEFT:
		_player.x -= moveSpeed;
		break;
	case PLAYER_D_UP:
		_player.y -= moveSpeed;
		break;
	}//end of switch(_direction)
}

void Player::playerenergybar()
{
	_hp._hpbar->setGauge(_hp.Hp, _hp._maxhp);
	_energy._energy->setGauge(_energy.energy, _energy._maxenergy);
}

void Player::inventorymove()
{
	_inven->update();
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		if (!isinven)
		{
			isinven = true;
			_inven->setOpen(true);
		//	_inven->setTest(true);
		}
		else
		{
			isinven = false;
			_inven->setOpen(false);
			//_inven->setTest(false);
		}
	}
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
	_sword._toolimg->frameRender(hdc, _player.x-40, _player.y-20);								//칼
	_can._img->frameRender(hdc, _player.rc.left-28, _player.rc.top);								//물뿌리개
	_hp._hpbar->render();																										//에너지바
	_energy._energy->render();																							//혈액


	if (KEYMANAGER->isToggleKey('Q'))
	{
		Rectangle(hdc, _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
		Rectangle(hdc, rcCollision.left, rcCollision.top, rcCollision.right, rcCollision.bottom);
		Rectangle(hdc, _attackrc.left, _attackrc.top, _attackrc.right, _attackrc.bottom);
		Rectangle(hdc, seedRECT.left, seedRECT.top, seedRECT.right, seedRECT.bottom);
	}


	_tool->render();

}

void Player::invenrender(HDC hdc)
{
	_clock->render();
	//_clock->setDay(MONDAY);
	if (!isinven)_inven->render(hdc);
	else _inven->invenrender(hdc);
}

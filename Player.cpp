#include "stdafx.h"
#include "Player.h"


Player::Player() {}
Player::~Player() {}

HRESULT Player::init()
{
	playerimg();																																																									//플레이어 이미지 모음
	_player._playerimg = IMAGEMANAGER->findImage("플레이어몸통");																															//플레이어 몸통 이미지 불러오기 
	_player._playerarmimg = IMAGEMANAGER->findImage("팔");
	_player._playercloth = IMAGEMANAGER->findImage("후드티");
	_player._pantsimg = IMAGEMANAGER->findImage("바지");																																			//플레이어 바지 
	_player.x = WINSIZEX / 2;																																																			//플레이어 RECT에 넣을 float  x
	_player.y = WINSIZEY / 2;																																																			//플레이어 RECT에 넣을 float  y
	//렉트들
	_player._playerect = RectMakeCenter(_player.x, _player.y, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());

	//변수 정보
	_player._plaindex = 0;																																																					//플레이어 이미지 매니저 돌릴 index
	_player._placount = 0;																																																					//플레이어 이미지 매니저 돌릴 count

	//플레이어 움직임 초기값
	_player._playermove = PLAYER_STOP;
	_player._playerarmmove = PLAYER_ARM_STOP;
	_player._playerpants = PLAYER_PANTS_DOWN;
	
	//프로그래스바
	// _hp._maxhp = 100;
	//hp
	_hp._maxhp = 100;
	_hp.Hp = 0;
	_hp._hpbar = new progressBar;
	_hp._hpbar->init("images/UI/progressbar/Ui_hp_Hp_bar_front.bmp", "images/UI/progressbar/Ui_hp_energy_bar.bmp",  850, 550, 30, 180);
	_hp._hpbar->setGauge(_hp.Hp, _hp._maxhp);
	//energy
	_energy._maxenergy = 100;
	_energy.energy = 0;
	_energy._energy = new energybar;
	_energy._energy-> init("images/UI/progressbar/Ui_hp_Hp_bar_front.bmp", "images/UI/progressbar/Ui_hp_bar (1).bmp", 810, 550, 30, 180);
	_energy._energy->setGauge(_energy.energy, _energy._maxenergy);

	//다른 클래스 불러오기
	//_cursor = new cusor;
	//_cursor->init();

	return S_OK;
}

void Player::release()
{
	//_cursor->release();
	_hp._hpbar->release();
	_energy._energy->release();
}

void Player::update()
{

	playerkeycontrol();
	playermove();
//	_cursor->update();
	playerenergybar();																					//플레이어 hp 바
}
//플레이어 키를 모아둔 곳		
void Player::playerkeycontrol()
{
	//멈추지 않은 상태
	if (KEYMANAGER->isStayKeyDown('S') && _player.y < TILESIZEY - 100)
	{
		_player._playermove = PLAYER_DOWN;
		_player._playerarmmove = PLAYER_ARM_DOWN;
		_player._playerpants = PLAYER_PANTS_DOWN;
		_player.y += 2.f;
		if (CAMERA->getCameraCenter().y - WINSIZEY / 2 < TILESIZEY)CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y + 2));
	}
	if (KEYMANAGER->isStayKeyDown('D') && _player.x < CAMERA->getCameraCenter().x + WINSIZEX + (TILESIZEX - 100))
	{
		_player._playermove = PLAYER_RIGHT;
		_player._playerarmmove = PLAYER_ARM_RIGHT;
		_player._playerpants = PLAYER_PANTS_RIGHT;
		_player.x += 2.f;
		if (CAMERA->getCameraCenter().x + WINSIZEX / 2 < TILESIZEX) CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x + 2, CAMERA->getCameraCenter().y));
	}
	if (KEYMANAGER->isStayKeyDown('A') && _player.x > 0)
	{
		_player._playermove = PLAYER_LEFT;
		_player._playerarmmove = PLAYER_ARM_LEFT;
		_player._playerpants = PLAYER_PANTS_LEFT;
		_player.x -= 2.f;
		if (CAMERA->getCameraCenter().x - WINSIZEX / 2 > 0)	CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x - 2, CAMERA->getCameraCenter().y));
	}
	if (KEYMANAGER->isStayKeyDown('W') && _player.y > 0)
	{
		_player._playermove = PLAYER_UP;
		_player._playerarmmove = PLAYER_ARM_UP;
		_player._playerpants = PLAYER_PANTS_UP;
		_player.y -= 2.f;
		if (CAMERA->getCameraCenter().y - WINSIZEY / 2 > 0)CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y - 2));
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

//플레이어 움직임(body&arm)
void Player::playermove()
{
	switch (_player._playermove)
	{
		//플렐이어 기본 움직임
	case PLAYER_DOWN:
		_player._placount++;
		_player._playerimg->setFrameY(0);
		if (_player._playerarmmove == PLAYER_ARM_DOWN)_player._playerarmimg->setFrameY(0);
		if (_player._playerpants == PLAYER_PANTS_DOWN) _player._pantsimg->setFrameY(0);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
		}
		if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
		{
			if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
	case PLAYER_RIGHT:
		_player._placount++;
		_player._playerimg->setFrameY(1);
		if (_player._playerarmmove == PLAYER_ARM_RIGHT)_player._playerarmimg->setFrameY(1);
		if (_player._playerpants == PLAYER_PANTS_RIGHT) _player._pantsimg->setFrameY(1);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
	case PLAYER_LEFT:
		_player._placount++;
		_player._playerimg->setFrameY(2);
		if (_player._playerarmmove == PLAYER_ARM_LEFT)_player._playerarmimg->setFrameY(2);
		if (_player._playerpants == PLAYER_PANTS_LEFT) _player._pantsimg->setFrameY(2);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
	case PLAYER_UP:
		_player._placount++;
		_player._playerimg->setFrameY(3);
		if (_player._playerarmmove == PLAYER_ARM_UP)_player._playerarmimg->setFrameY(3);
		if (_player._playerpants == PLAYER_PANTS_UP) _player._pantsimg->setFrameY(3);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
		//플레이어 곡괭이, 괭이, 도끼, 낫, 검 
	case PLAYER_PWR_DOWN:
		_player._placount++;
		_player._playerimg->setFrameY(4);
		if (_player._playerarmmove == PLAYER_ARM_PWR_DOWN)_player._playerarmimg->setFrameY(4);
		if (_player._playerpants == PLAYER_PANTS_PWR_DOWN) _player._pantsimg->setFrameY(4);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					if (_player._plaindex >= _player._pantsimg->getMaxFrameX())
					{
						_player._plaindex = 0;
					}
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
			_player._pantsimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PWR_RIGHT:
		_player._placount++;
		_player._playerimg->setFrameY(5);
		if (_player._playerarmmove == PLAYER_ARM_PWR_RIGHT)_player._playerarmimg->setFrameY(5);
		if (_player._playerpants == PLAYER_PANTS_PWR_RIGHT) _player._pantsimg->setFrameY(5);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					if (_player._plaindex >= _player._pantsimg->getMaxFrameX())
					{
						_player._plaindex = 0;
					}
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
			_player._pantsimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PWR_LEFT:
		_player._placount++;
		_player._playerimg->setFrameY(6);
		if (_player._playerarmmove == PLAYER_ARM_PWR_LEFT)_player._playerarmimg->setFrameY(6);
		if (_player._playerpants == PLAYER_PANTS_PWR_LEFT) _player._pantsimg->setFrameY(6);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					if (_player._plaindex >= _player._pantsimg->getMaxFrameX())
					{
						_player._plaindex = 0;
					}
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
			_player._pantsimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PWR_UP:
		_player._placount++;
		_player._playerimg->setFrameY(7);
		if (_player._playerarmmove == PLAYER_ARM_PWR_UP)_player._playerarmimg->setFrameY(7);
		if (_player._playerpants == PLAYER_PANTS_PWR_UP) _player._pantsimg->setFrameY(7);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					if (_player._plaindex >= _player._pantsimg->getMaxFrameX())
					{
						_player._plaindex = 0;
					}
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
			_player._pantsimg->setFrameX(_player._plaindex);
		}
		break;
		//플레이어 낚시
	case PLAYER_PIS_DOWN:
		_player._placount++;
		_player._playerimg->setFrameY(8);
		if (_player._playerarmmove == PLAYER_ARM_PIS_DOWN)_player._playerarmimg->setFrameY(8);
		if (_player._playerpants == PLAYER_PANTS_PIS_DOWN) _player._pantsimg->setFrameY(8);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
	case PLAYER_PIS_RIGHT:
		_player._placount++;
		_player._playerimg->setFrameY(9);
		if (_player._playerarmmove == PLAYER_ARM_PIS_RIGHT)_player._playerarmimg->setFrameY(9);
		if (_player._playerpants == PLAYER_PANTS_PIS_RIGHT) _player._pantsimg->setFrameY(9);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
	case PLAYER_PIS_LEFT:
		_player._placount++;
		_player._playerimg->setFrameY(10);
		if (_player._playerarmmove == PLAYER_ARM_PIS_LEFT)_player._playerarmimg->setFrameY(10);
		if (_player._playerpants == PLAYER_PANTS_PIS_LEFT) _player._pantsimg->setFrameY(10);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
	case PLAYER_PIS_UP:
		_player._placount++;
		_player._playerimg->setFrameY(11);
		if (_player._playerarmmove == PLAYER_ARM_PIS_UP)_player._playerarmimg->setFrameY(11);
		if (_player._playerpants == PLAYER_PANTS_PIS_UP) _player._pantsimg->setFrameY(11);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
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
		}
		break;
	}
	clothmove();
}

void Player::clothmove()
{
	switch (_player._playerpants)
	{
	case PLAYER_PANTS_WATERCAN_DOWN:
		_player._placount++;
		_player._pantsimg->setFrameY(12);
		if (_player._playerarmmove == PLAYER_ARM_WATCAN_DOWN) _player._playerarmimg->setFrameY(12);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
		}
		if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
			{
				_player._plaindex = 0;
			}
		}
		_player._pantsimg->setFrameX(_player._plaindex);
		_player._playerarmimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_PANTS_WATERCAN_RIGHT:
		_player._placount++;
		_player._pantsimg->setFrameY(13);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
		}
		if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
			{
				_player._plaindex = 0;
			}
		}
		_player._pantsimg->setFrameX(_player._plaindex);
		_player._playerarmimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_PANTS_WATERCAN_LEFT:
		_player._placount++;
		_player._pantsimg->setFrameY(14);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
		}
		if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
			{
				_player._plaindex = 0;
			}
		}
		_player._pantsimg->setFrameX(_player._plaindex);
		_player._playerarmimg->setFrameX(_player._plaindex);
		break;
	case PLAYER_PANTS_WATERCAN_UP:
		_player._placount++;
		_player._pantsimg->setFrameY(15);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
		}
		if (_player._plaindex >= _player._pantsimg->getMaxFrameX() - 3)
		{
			if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
			{
				_player._plaindex = 0;
			}
		}
		_player._pantsimg->setFrameX(_player._plaindex);
		_player._playerarmimg->setFrameX(_player._plaindex);
		break;
	}
}

void Player::playerenergybar()
{
	_hp._hpbar->setGauge(_hp.Hp, _hp._maxhp);
	_energy._energy->setGauge(_energy.energy,_energy._maxenergy);
}
//hp데미지
void Player::energydamage(float _energy)
{
	_hp.Hp += _energy;
	/*
	최대가 max 95까지 95일 경우 플레이어는 쓰러진다.
	*/

}
//에너지 데미지
void Player::hpdamage(float _hp)
{
	_energy.energy += _hp;
	/*
최대가 max 95까지 95일 경우 플레이어는 쓰러진다.
*/

}

void Player::render(HDC hdc)
{
	_player._pantsimg->frameRender(hdc, _player.x, _player.y);						//캐릭터 바지 
	_player._playerimg->frameRender(hdc, _player.x, _player.y);							//몸통 얼굴
	_player._playerarmimg->frameRender(hdc, _player.x, _player.y);						//팔
	//_player._playercloth->frameRender(hdc, _player.x + 8, _player.y + 29);
	//_cursor->render();																										//커서
	_hp._hpbar->render();																								//에너지바
	_energy._energy->render();																							//혈액

}
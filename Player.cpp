#include "stdafx.h"
#include "Player.h"

Player::Player() {}
Player::~Player() {}

HRESULT Player::init()
{
	playerimg();																																																									//플레이어 이미지 모음
	_player._playerimg = IMAGEMANAGER->findImage("플레이어몸통");																															//플레이어 몸통 이미지 불러오기 
	_player._playerarmimg = IMAGEMANAGER->findImage("팔");
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

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	playerkeycontrol();
	playermove();
}
//플레이어 키를 모아둔 곳		
void Player::playerkeycontrol()
{
	//멈추지 않은 상태
		if (KEYMANAGER->isStayKeyDown('S'))
		{
			_player._playermove = PLAYER_DOWN;
			_player._playerarmmove = PLAYER_ARM_DOWN;
			_player.y += 2.f;
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_player._playermove = PLAYER_RIGHT;
			_player._playerarmmove = PLAYER_ARM_RIGHT;
			_player.x +=2.f;
		}
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_player._playermove = PLAYER_LEFT;
			_player._playerarmmove = PLAYER_ARM_LEFT;
			_player.x -= 2.f;
		}
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_player._playermove = PLAYER_UP;
			_player._playerarmmove = PLAYER_ARM_UP;
			_player.y -= 2.f;
		}
		//멈춘 상태
		if (KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('A') ||KEYMANAGER->isOnceKeyUp('D'))
		{
			_player._playermove = PLAYER_STOP;
			_player._playerarmmove = PLAYER_ARM_STOP;
			_player._plaindex = 0;
			_player._placount = 0;

		}
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
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_RIGHT:
		_player._placount++;
		_player._playerimg->setFrameY(1);
		if (_player._playerarmmove == PLAYER_ARM_RIGHT)_player._playerarmimg->setFrameY(1);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_LEFT:
		_player._placount++;
		_player._playerimg->setFrameY(2);
		if (_player._playerarmmove == PLAYER_ARM_LEFT)_player._playerarmimg->setFrameY(2);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_UP:
		_player._placount++;
		_player._playerimg->setFrameY(3);
		if (_player._playerarmmove == PLAYER_ARM_UP)_player._playerarmimg->setFrameY(3);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
		//플레이어 곡괭이, 괭이, 도끼, 낫, 검 
	case PLAYER_PWR_DOWN:
		_player._placount++;
		_player._playerimg->setFrameY(4);
		if (_player._playerarmmove == PLAYER_ARM_PWR_DOWN)_player._playerarmimg->setFrameY(4);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PWR_RIGHT:
		_player._placount++;
		_player._playerimg->setFrameY(5);
		if (_player._playerarmmove == PLAYER_ARM_PWR_RIGHT)_player._playerarmimg->setFrameY(5);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PWR_LEFT:
		_player._placount++;
		_player._playerimg->setFrameY(6);
		if (_player._playerarmmove == PLAYER_ARM_PWR_LEFT)_player._playerarmimg->setFrameY(6);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PWR_UP:
		_player._placount++;
		_player._playerimg->setFrameY(7);
		if (_player._playerarmmove == PLAYER_ARM_PWR_UP)_player._playerarmimg->setFrameY(7);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
		//플레이어 낚시
	case PLAYER_PIS_DOWN:
		_player._placount++;
		_player._playerimg->setFrameY(8);
		if (_player._playerarmmove == PLAYER_ARM_PIS_DOWN)_player._playerarmimg->setFrameY(8);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PIS_RIGHT:
		_player._placount++;
		_player._playerimg->setFrameY(9);
		if (_player._playerarmmove == PLAYER_ARM_PIS_RIGHT)_player._playerarmimg->setFrameY(9);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PIS_LEFT:
		_player._placount++;
		_player._playerimg->setFrameY(10);
		if (_player._playerarmmove == PLAYER_ARM_PIS_LEFT)_player._playerarmimg->setFrameY(10);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	case PLAYER_PIS_UP:
		_player._placount++;
		_player._playerimg->setFrameY(11);
		if (_player._playerarmmove == PLAYER_ARM_PIS_UP)_player._playerarmimg->setFrameY(11);
		if (_player._placount % 7 == 0)
		{
			_player._placount = 0;
			_player._plaindex++;
			if (_player._plaindex >= _player._playerimg->getMaxFrameX() - 1)
			{
				if (_player._plaindex >= _player._playerarmimg->getMaxFrameX() - 1)
				{
					_player._plaindex = 0;
				}
			}
			_player._playerarmimg->setFrameX(_player._plaindex);
			_player._playerimg->setFrameX(_player._plaindex);
		}
		break;
	}
}

void Player::render(HDC hdc)
{
	_player._playerimg->frameRender(hdc, _player.x, _player.y);							//몸통 얼굴
	_player._playerarmimg->frameRender(hdc, _player.x, _player.y);						//팔
	

}
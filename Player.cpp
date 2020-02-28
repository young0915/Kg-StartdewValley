#include "stdafx.h"
#include "Player.h"

Player::Player() {}
Player::~Player() {}

HRESULT Player::init()
{
	playerimg();																																																									//�÷��̾� �̹��� ����
	_player._playerimg = IMAGEMANAGER->findImage("�÷��̾����");																															//�÷��̾� ���� �̹��� �ҷ����� 
	_player._playerarmimg = IMAGEMANAGER->findImage("��");
	_player.x = WINSIZEX / 2;																																																			//�÷��̾� RECT�� ���� float  x
	_player.y = WINSIZEY / 2;																																																			//�÷��̾� RECT�� ���� float  y
	//��Ʈ��
	_player._playerect = RectMakeCenter(_player.x, _player.y, _player._playerimg->getFrameWidth(), _player._playerimg->getFrameHeight());

	//���� ����
	_player._plaindex = 0;																																																					//�÷��̾� �̹��� �Ŵ��� ���� index
	_player._placount = 0;																																																					//�÷��̾� �̹��� �Ŵ��� ���� count

	//�÷��̾� ������ �ʱⰪ
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
//�÷��̾� Ű�� ��Ƶ� ��		
void Player::playerkeycontrol()
{
	//������ ���� ����
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
		//���� ����
		if (KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('A') ||KEYMANAGER->isOnceKeyUp('D'))
		{
			_player._playermove = PLAYER_STOP;
			_player._playerarmmove = PLAYER_ARM_STOP;
			_player._plaindex = 0;
			_player._placount = 0;

		}
}

//�÷��̾� ������(body&arm)
void Player::playermove()
{
	switch (_player._playermove)
	{
		//�÷��̾� �⺻ ������
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
		//�÷��̾� ���, ����, ����, ��, �� 
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
		//�÷��̾� ����
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
	_player._playerimg->frameRender(hdc, _player.x, _player.y);							//���� ��
	_player._playerarmimg->frameRender(hdc, _player.x, _player.y);						//��
	

}
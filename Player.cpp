#include "stdafx.h"
#include "Player.h"


Player::Player() {}
Player::~Player() {}

HRESULT Player::init()
{
	playerimg();																																																									//�÷��̾� �̹��� ����
	_player._playerimg = IMAGEMANAGER->findImage("�÷��̾����");																															//�÷��̾� ���� �̹��� �ҷ����� 
	_player._playerarmimg = IMAGEMANAGER->findImage("��");
	_player._playercloth = IMAGEMANAGER->findImage("�ĵ�Ƽ");
	_player._pantsimg = IMAGEMANAGER->findImage("����");																																			//�÷��̾� ���� 
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
	_player._playerpants = PLAYER_PANTS_DOWN;

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
	//���� ����
	if (KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp('D'))
	{
		_player._playermove = PLAYER_STOP;
		_player._playerarmmove = PLAYER_ARM_STOP;
		_player._playerpants = PLAYER_PANT_STOP;
		_player._plaindex = 0;
		_player._playerimg->setFrameX(_player._plaindex);										// �̷��� �ؾ��� ĳ���� ������ �� �� ����
	}
	//'E' �κ��丮 ���� â
	//���콺 ������ ������� ���ɱ� �������� �Ա� �ο��, �ɱ�, ���̵�
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
		//�÷��̾� ���, ����, ����, ��, �� 
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
		//�÷��̾� ����
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

void Player::render(HDC hdc)
{
	_player._pantsimg->frameRender(hdc, _player.x, _player.y);						//ĳ���� ���� 
	_player._playerimg->frameRender(hdc, _player.x, _player.y);							//���� ��
	_player._playerarmimg->frameRender(hdc, _player.x, _player.y);						//��
	//_player._playercloth->frameRender(hdc, _player.x + 8, _player.y + 29);


}
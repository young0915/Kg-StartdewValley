#include "stdafx.h"
#include "Player.h"
/*
�̰��� �÷��̾� �̹����� �ִ� ��
*/

void Player::playerimg()
{
	//�÷��̾� ����
	IMAGEMANAGER->addFrameImage("�÷��̾����", "images/player/player_body.bmp", 96*2, 512*2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/player/player_arm.bmp", (_player._playerect.right + (_player._playerect.left - _player._playerect.right) / 2) - 16, (_player._playerect.bottom + (_player._playerect.top - _player._playerect.bottom / 2)) - 33, 96*2, 640*2, 6, 20, true, RGB(255, 0, 255));

}

#include "stdafx.h"
#include "Player.h"
/*
�̰��� �÷��̾� �̹����� �ִ� ��
*/

void Player::playerimg()
{
	//�÷��̾� ����
	IMAGEMANAGER->addFrameImage("�÷��̾����", "images/player/player_body.bmp", 97 * 2.8, 509 * 2.8, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/player/player_arm.bmp", 97 * 2.8, 640 * 2.8, 6, 20, true, RGB(255, 0, 255));

	//�÷��̾� �� 
	IMAGEMANAGER->addFrameImage("����", "images/cloth/����.bmp", 97 * 2.8, 510 * 2.8, 6, 16, true, RGB(255, 0, 255));


	//�÷��̾� ���α׷����� 
	IMAGEMANAGER->addImage("��������", "images/UI/progressbar/Ui_hp_energy_bar.bmp", 40, 180, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/UI/progressbar/Ui_hp_energy_bar_front.bmp", 20, 132, true, RGB(255, 0, 255));
}

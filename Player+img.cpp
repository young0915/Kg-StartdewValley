#include "stdafx.h"
#include "Player.h"
/*
�̰��� �÷��̾� �̹����� �ִ� ��
*/

void Player::playerimg()
{
	//�÷��̾� ����
	IMAGEMANAGER->addFrameImage("�÷��̾����", "images/player/player_body.bmp", 96 * 2.5, 512 * 2.5, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/player/player_arm.bmp", 96 * 2.5, 640 * 2.5, 6, 20, true, RGB(255, 0, 255));

	//�÷��̾� �� 
	IMAGEMANAGER->addFrameImage("����", "images/cloth/����.bmp", 96 * 2.5, 510 * 2.5, 6, 16, true, RGB(255, 0, 255));


	//�÷��̾� ���α׷����� 
	IMAGEMANAGER->addImage("��������", "images/UI/progressbar/Ui_hp_energy_bar.bmp", 40, 180, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/UI/progressbar/Ui_hp_energy_bar_front.bmp", 20, 132, true, RGB(255, 0, 255));
}

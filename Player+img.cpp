#include "stdafx.h"
#include "Player.h"
/*
�̰��� �÷��̾� �̹����� �ִ� ��
*/
/*
�̰��� �÷��̾� �̹����� �ִ� ��
*/

void Player::playerimg()
{
	//�÷��̾� ����
	IMAGEMANAGER->addFrameImage("�÷��̾����", "images/player/player_body.bmp", 96 * 3, 512 * 3, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/player/player_arm.bmp", 96 * 3, 640 * 3, 6, 20, true, RGB(255, 0, 255));

	//�÷��̾� �� 
	IMAGEMANAGER->addFrameImage("����", "images/cloth/����.bmp", 96 * 3, 510 *3, 6, 16, true, RGB(255, 0, 255));


	//�÷��̾� ���α׷����� 
	IMAGEMANAGER->addImage("��������", "images/UI/progressbar/Ui_hp_energy_bar.bmp", 40, 180, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/UI/progressbar/Ui_hp_energy_bar_front.bmp", 20, 132, true, RGB(255, 0, 255));

	//����
	IMAGEMANAGER->addFrameImage("Į", "images/�ⱸ/weapon_glaxysward.bmp", 160 * 3, 160 * 3, 5, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���Ѹ���", "images/�ⱸ/tool_wateringcan.bmp", 96*3, 160*3, 3,5,true, RGB(255, 0, 255));
}

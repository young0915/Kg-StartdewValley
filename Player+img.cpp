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

	//�÷��̾� ��ⱸ
	IMAGEMANAGER->addFrameImage("����", "images/�ⱸ/tool_axe.bmp", 110 * 2.8, 88 * 2.8,5,4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ȣ��", "images/�ⱸ/tool_hoe.bmp", 110 * 2.8, 88 * 2.8, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���Ѹ���", "images/�ⱸ/tool_wateringcan.bmp", 110 * 2.8, 88 * 2.8, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���", "images/�ⱸ/tool_pickaxe.bmp", 110 * 2.8, 88 * 2.8, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/�ⱸ/tool_scythe.bmp", 96 * 2.8, 64 * 2.8, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/�ⱸ/weapon_glaxysward.bmp", 96 * 2.8, 64 * 2.8, 6, 4, true, RGB(255, 0, 255));
}

#include "stdafx.h"
#include "Player.h"
/*
이곳은 플레이어 이미지만 있는 곳
*/
/*
이곳은 플레이어 이미지만 있는 곳
*/

void Player::playerimg()
{
	//플레이어 정보
	IMAGEMANAGER->addFrameImage("플레이어몸통", "images/player/player_body.bmp", 96 * 3, 512 * 3, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("팔", "images/player/player_arm.bmp", 96 * 3, 640 * 3, 6, 20, true, RGB(255, 0, 255));

	//플레이어 옷 
	IMAGEMANAGER->addFrameImage("바지", "images/cloth/바지.bmp", 96 * 3, 510 *3, 6, 16, true, RGB(255, 0, 255));


	//플레이어 프로그래스바 
	IMAGEMANAGER->addImage("에너지바", "images/UI/progressbar/Ui_hp_energy_bar.bmp", 40, 180, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에너지", "images/UI/progressbar/Ui_hp_energy_bar_front.bmp", 20, 132, true, RGB(255, 0, 255));

	//무기
	IMAGEMANAGER->addFrameImage("칼", "images/기구/weapon_glaxysward.bmp", 160 * 3, 160 * 3, 5, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물뿌리개", "images/기구/tool_wateringcan.bmp", 96*3, 160*3, 3,5,true, RGB(255, 0, 255));
}

#include "stdafx.h"
#include "Player.h"
/*
이곳은 플레이어 이미지만 있는 곳
*/

void Player::playerimg()
{
	//플레이어 정보
	IMAGEMANAGER->addFrameImage("플레이어몸통", "images/player/player_body.bmp", 97 * 2.8, 509 * 2.8, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("팔", "images/player/player_arm.bmp", 97 * 2.8, 640 * 2.8, 6, 20, true, RGB(255, 0, 255));

	//플레이어 옷 
	IMAGEMANAGER->addFrameImage("바지", "images/cloth/바지.bmp", 97 * 2.8, 510 * 2.8, 6, 16, true, RGB(255, 0, 255));


	//플레이어 프로그래스바 
	IMAGEMANAGER->addImage("에너지바", "images/UI/progressbar/Ui_hp_energy_bar.bmp", 40, 180, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("에너지", "images/UI/progressbar/Ui_hp_energy_bar_front.bmp", 20, 132, true, RGB(255, 0, 255));

	//플레이어 농기구
	IMAGEMANAGER->addFrameImage("도끼", "images/기구/tool_axe.bmp", 110 * 2.8, 88 * 2.8,5,4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("호미", "images/기구/tool_hoe.bmp", 110 * 2.8, 88 * 2.8, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물뿌리개", "images/기구/tool_wateringcan.bmp", 110 * 2.8, 88 * 2.8, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("곡괭이", "images/기구/tool_pickaxe.bmp", 110 * 2.8, 88 * 2.8, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("낫", "images/기구/tool_scythe.bmp", 96 * 2.8, 64 * 2.8, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("검", "images/기구/weapon_glaxysward.bmp", 96 * 2.8, 64 * 2.8, 6, 4, true, RGB(255, 0, 255));
}

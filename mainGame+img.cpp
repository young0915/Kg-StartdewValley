#include "stdafx.h"
#include "mainGame.h"

/*
이미지 때려박는 곳

*/

void mainGame::maingameimg()
{

	//플레이어 옷 
	IMAGEMANAGER->addFrameImage("머리", "images/cloth/머리.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("후드티", "images/cloth/후드티.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));
}




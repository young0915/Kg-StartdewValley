#include "stdafx.h"
#include "mainGame.h"

/*
이미지 모음
*/

void mainGame::maingameimg()
{
	//맵툴 UI
	IMAGEMANAGER->addImage("맵툴", "images/맵툴/맵툴UI/maptool2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("도구", "images/맵툴/맵툴UI/Ui_menuKinds.bmp", 18 * 3, 18 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("맵툴오른쪽", "images/맵툴/맵툴UI/Ui_maptool_beforeButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("맵툴왼쪽", "images/맵툴/맵툴UI/Ui_maptool_nextButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("나가기", "images/맵툴/맵툴UI/Ui_cancelButton.bmp", 26 * 2, 12 * 2, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("지우기", "images/맵툴/맵툴UI/Ui_maptool_erase.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("로드", "images/맵툴/맵툴UI/Ui_maptool_load.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("저장", "images/맵툴/맵툴UI/Ui_maptool_save.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("타일", "images/맵툴/맵툴UI/Ui_maptool_tile.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오브젝트", "images/맵툴/맵툴UI/Ui_maptool_object.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));


	//맵툴 이미지
	IMAGEMANAGER->addFrameImage("봄바닥", "images/맵툴/maptool_tile1_spring.bmp", 576, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));


	//플레이어 옷 
	IMAGEMANAGER->addFrameImage("머리", "images/cloth/머리.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("후드티", "images/cloth/후드티.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));
}



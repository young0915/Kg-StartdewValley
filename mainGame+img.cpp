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
	IMAGEMANAGER->addFrameImage("맵툴바닥", "images/맵툴/maptool_tile.bmp", 600, 1550, 12, 31, true, RGB(255, 0, 255));



	//플레이어 옷 
	IMAGEMANAGER->addFrameImage("머리", "images/cloth/머리.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("후드티", "images/cloth/후드티.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));

	//인트로 씬
	IMAGEMANAGER->addImage("시작화면", "images/introscene/title_backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름1", "images/introscene/title_cloud1.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름2", "images/introscene/title_cloud2.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름3", "images/introscene/title_cloud3.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름4", "images/introscene/title_cloud4.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름5", "images/introscene/title_cloud5.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름6", "images/introscene/title_cloud10.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름7", "images/introscene/title_cloud6.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("게임제목", "images/introscene/게임제목.bmp", 600, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("시작", "images/introscene/시작.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("맵툴버튼", "images/introscene/map.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("나가기버튼", "images/introscene/나가기.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));

	//몬스터 
	IMAGEMANAGER->addFrameImage("게", "images/몬스터/꽃게.bmp", 64, 144, 4, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("박쥐", "images/몬스터/박쥐.bmp", 64, 80, 4, 5, true, RGB(255, 0, 255));


	//커서 
	IMAGEMANAGER->addFrameImage("커서", "images/cursor/Ui_cursor.bmp", 128 * 2, 16 * 2, 8, 1, true, RGB(255, 0, 255));
	 
	//인벤토리
	IMAGEMANAGER->addImage("인벤토리", "images/인벤토리/Ui_mainInventory.bmp", 655, 90, true, RGB(255, 0, 255));
}



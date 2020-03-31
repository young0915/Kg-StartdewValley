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
	IMAGEMANAGER->addFrameImage("맵툴바닥", "images/맵툴/maptool_tile.bmp", 600, 2100, 12, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("샵1", "images/맵툴/샵1.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("샵2", "images/맵툴/샵2.bmp", 300 ,50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("샵3", "images/맵툴/샵3.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("샵4", "images/맵툴/샵4.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("아저씨", "images/맵툴/아저씨.bmp", 60, 60, true, RGB(255, 0, 255));

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
	IMAGEMANAGER->addFrameImage("꽃게", "images/몬스터/꽃게.bmp", 64*3, 96*3, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("박쥐", "images/몬스터/박쥐.bmp", 64*3, 64*3, 4, 4, true, RGB(255, 0, 255));

	//커서 
	IMAGEMANAGER->addFrameImage("커서", "images/cursor/Ui_cursor.bmp", 128 * 2, 16 * 2, 8, 1, true, RGB(255, 0, 255));
	 
	//인벤토리
	IMAGEMANAGER->addImage("인벤토리", "images/인벤토리/Ui_mainInventory.bmp", 655, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("E벤토리", "images/인벤토리/인벤토리창.bmp", 680,540, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인벤칸", "images/인벤토리/인벤토리요소칸.bmp", 47, 67, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("쓰레기통", "images/인벤토리/쓰레기통.bmp", 20*3, 27*3, true, RGB(255, 0, 255));

	//건물
	IMAGEMANAGER->addImage("내집", "images/맵툴/내집.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지붕", "images/맵툴/지붕.bmp", 400, 140, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("우편", "images/맵툴/우편.bmp", 70, 146, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("침대", "images/맵툴/내방/housebed.bmp", 32, 49, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("침대2", "images/맵툴/내방/침대2.bmp", 32, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점", "images/맵툴/집1.bmp", 240*3, 165*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상점1", "images/맵툴/집11.bmp", 240*3, 100*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("집1", "images/맵툴/세바스찬집.bmp", 113*4, 100*4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("집11", "images/세바스찬집1.bmp", 113*4, 150*4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("집2", "images/맵툴/집2.bmp", 150*3, 170*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("집22", "images/맵툴/집22.bmp", 150*3, 100*3, true, RGB(255, 0, 255));

	//아이템
	IMAGEMANAGER->addImage("감자", "images/item/감자.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("감자씨앗", "images/item/감자씨앗.bmp", 14*3, 16*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("콜리플라워 씨앗", "images/item/콜리플라워 씨앗.bmp", 16*3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("콩종자", "images/item/콩종자.bmp", 16 * 3, 14 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("피닙스 씨앗","images/item/피닙스씨앗.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("게", "images/item/꽃게.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("나무", "images/item/나무.bmp", 16*3, 16*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌", "images/item/돌.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("잡초", "images/item/잡초.bmp", 16 * 3, 15 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("루비", "images/item/루비.bmp", 11 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("물뿌리개(아이템)", "images/item/물뿌리개.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("흑요소", "images/item/검.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("박쥐", "images/item/박쥐.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("비어있음", "images/item/비어있음.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("곡괭이(아이템)", "images/item/곡괭이.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("도끼(아이템)", "images/item/도끼.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("호미(아이템)", "images/item/호미.bmp", 48, 48, true, RGB(255, 0, 255));

	//UI
	IMAGEMANAGER->addImage("시계", "images/UI/Ui_time.bmp", 72*3, 57*3, true, RGB(255, 0, 255));

	//상점
	IMAGEMANAGER->addImage("상점아저씨", "images/shop/Ui_shop.bmp", 650, 395, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("상점칸", "images/shop/상점칸.bmp", 478, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("카펫트", "images/shop/카펫트.bmp", 100, 50, true, RGB(255, 0, 255));

	//잡것
	IMAGEMANAGER->addImage("나무1", "images/etc/나무1.bmp", 48, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나무2", "images/etc/나무2.bmp", 50*3, 100*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌맹이", "images/기타등등/돌맹이.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("루비돌", "images/기타등등/루비돌.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("잔디", "images/etc/잔디.bmp", 48, 48, true, RGB(255, 0, 255));

	//농장
	IMAGEMANAGER->addImage("비어진 땅", "images/타일/비어진땅.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("물뿌리개타일", "images/타일/물뿌리개타일.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("호미타일", "images/타일/호미타일.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("감자농장", "images/타일/감자농장.bmp", 312, 72, 8,1,true, RGB(255, 0, 255));


	//NPC
	 IMAGEMANAGER->addFrameImage("아비게일", "images/NPC/Abigail.bmp", 64 * 3, 32 * 3, 4, 1, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addFrameImage("알렉스", "images/NPC/Alex.bmp", 64 * 3, 64 * 3, 4, 2, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addFrameImage("세바스찬", "images/NPC/Sebastian.bmp", 64 * 3, 64 * 3, 4, 2, true, RGB(255, 0, 255));


}



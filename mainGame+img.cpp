#include "stdafx.h"
#include "mainGame.h"

/*
ÀÌ¹ÌÁö ¸ðÀ½
*/

void mainGame::maingameimg()
{
	//¸ÊÅø UI
	IMAGEMANAGER->addImage("¸ÊÅø", "images/¸ÊÅø/¸ÊÅøUI/maptool2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("µµ±¸", "images/¸ÊÅø/¸ÊÅøUI/Ui_menuKinds.bmp", 18 * 3, 18 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("¸ÊÅø¿À¸¥ÂÊ", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_beforeButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("¸ÊÅø¿ÞÂÊ", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_nextButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("³ª°¡±â", "images/¸ÊÅø/¸ÊÅøUI/Ui_cancelButton.bmp", 26 * 2, 12 * 2, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Áö¿ì±â", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_erase.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("·Îµå", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_load.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ÀúÀå", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_save.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Å¸ÀÏ", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_tile.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("¿ÀºêÁ§Æ®", "images/¸ÊÅø/¸ÊÅøUI/Ui_maptool_object.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));


	//¸ÊÅø ÀÌ¹ÌÁö
	IMAGEMANAGER->addFrameImage("¸ÊÅø¹Ù´Ú", "images/¸ÊÅø/maptool_tile.bmp", 600, 1550, 12, 31, true, RGB(255, 0, 255));



	//ÇÃ·¹ÀÌ¾î ¿Ê 
	IMAGEMANAGER->addFrameImage("¸Ó¸®", "images/cloth/¸Ó¸®.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ÈÄµåÆ¼", "images/cloth/ÈÄµåÆ¼.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));

	//ÀÎÆ®·Î ¾À
	IMAGEMANAGER->addImage("½ÃÀÛÈ­¸é", "images/introscene/title_backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§1", "images/introscene/title_cloud1.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§2", "images/introscene/title_cloud2.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§3", "images/introscene/title_cloud3.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§4", "images/introscene/title_cloud4.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§5", "images/introscene/title_cloud5.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§6", "images/introscene/title_cloud10.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("±¸¸§7", "images/introscene/title_cloud6.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("°ÔÀÓÁ¦¸ñ", "images/introscene/°ÔÀÓÁ¦¸ñ.bmp", 600, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("½ÃÀÛ", "images/introscene/½ÃÀÛ.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("¸ÊÅø¹öÆ°", "images/introscene/map.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("³ª°¡±â¹öÆ°", "images/introscene/³ª°¡±â.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));

	//Ä¿¼­ 
	IMAGEMANAGER->addFrameImage("Ä¿¼­", "images/cursor/Ui_cursor.bmp", 128 * 2, 16 * 2, 8, 1, true, RGB(255, 0, 255));
}



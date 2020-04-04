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
	IMAGEMANAGER->addFrameImage("¸ÊÅø¹Ù´Ú", "images/¸ÊÅø/maptool_tile.bmp", 600, 2100, 12, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¼¥1", "images/¸ÊÅø/¼¥1.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¼¥2", "images/¸ÊÅø/¼¥2.bmp", 300 ,50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¼¥3", "images/¸ÊÅø/¼¥3.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¼¥4", "images/¸ÊÅø/¼¥4.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¾ÆÀú¾¾", "images/¸ÊÅø/¾ÆÀú¾¾.bmp", 60, 60, true, RGB(255, 0, 255));

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

	//¸ó½ºÅÍ 
	IMAGEMANAGER->addFrameImage("²É°Ô", "images/¸ó½ºÅÍ/²É°Ô.bmp", 64*3, 96*3, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("¹ÚÁã", "images/¸ó½ºÅÍ/¹ÚÁã.bmp", 64*3, 64*3, 4, 4, true, RGB(255, 0, 255));

	//Ä¿¼­ 
	IMAGEMANAGER->addFrameImage("Ä¿¼­", "images/cursor/Ui_cursor.bmp", 128 * 2, 16 * 2, 8, 1, true, RGB(255, 0, 255));
	 
	//ÀÎº¥Åä¸®
	IMAGEMANAGER->addImage("ÀÎº¥Åä¸®", "images/ÀÎº¥Åä¸®/Ui_mainInventory.bmp", 655, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Eº¥Åä¸®", "images/ÀÎº¥Åä¸®/ÀÎº¥Åä¸®Ã¢.bmp", 680,540, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÀÎº¥Ä­", "images/ÀÎº¥Åä¸®/ÀÎº¥Åä¸®¿ä¼ÒÄ­.bmp", 47, 67, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¾²·¹±âÅë", "images/ÀÎº¥Åä¸®/¾²·¹±âÅë.bmp", 20*3, 27*3, true, RGB(255, 0, 255));

	//°Ç¹°
	IMAGEMANAGER->addImage("³»Áý", "images/¸ÊÅø/³»Áý.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÁöºØ", "images/¸ÊÅø/ÁöºØ.bmp", 400, 140, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¿ìÆí", "images/¸ÊÅø/¿ìÆí.bmp", 70, 146, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ä§´ë", "images/¸ÊÅø/³»¹æ/housebed.bmp", 110, 119, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ä§´ë2", "images/¸ÊÅø/³»¹æ/Ä§´ë2.bmp", 110, 106, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("»óÁ¡", "images/¸ÊÅø/Áý1.bmp", 240*3, 165*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("»óÁ¡1", "images/¸ÊÅø/Áý11.bmp", 240*3, 100*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Áý1", "images/¸ÊÅø/¼¼¹Ù½ºÂùÁý.bmp", 113*4, 100*4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Áý11", "images/¼¼¹Ù½ºÂùÁý1.bmp", 113*4, 150*4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Áý2", "images/¸ÊÅø/Áý2.bmp", 150*3, 170*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Áý22", "images/¸ÊÅø/Áý22.bmp", 150*3, 100*3, true, RGB(255, 0, 255));

	//¾ÆÀÌÅÛ
	IMAGEMANAGER->addImage("°¨ÀÚ", "images/item/°¨ÀÚ.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("°¨ÀÚ¾¾¾Ñ", "images/item/°¨ÀÚ¾¾¾Ñ.bmp", 14*3, 16*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÄÝ¸®ÇÃ¶ó¿ö ¾¾¾Ñ", "images/item/ÄÝ¸®ÇÃ¶ó¿ö ¾¾¾Ñ.bmp", 16*3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÄáÁ¾ÀÚ", "images/item/ÄáÁ¾ÀÚ.bmp", 16 * 3, 14 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÇÇ´Õ½º ¾¾¾Ñ","images/item/ÇÇ´Õ½º¾¾¾Ñ.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("°Ô", "images/item/²É°Ô.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("³ª¹«", "images/item/³ª¹«.bmp", 16*3, 16*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("µ¹", "images/item/µ¹.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÀâÃÊ", "images/item/ÀâÃÊ.bmp", 16 * 3, 15 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("·çºñ", "images/item/·çºñ.bmp", 11 * 4, 16 * 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¹°»Ñ¸®°³(¾ÆÀÌÅÛ)", "images/item/¹°»Ñ¸®°³.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Èæ¿ä¼Ò", "images/item/°Ë.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¹ÚÁã", "images/item/¹ÚÁã.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ºñ¾îÀÖÀ½", "images/item/ºñ¾îÀÖÀ½.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("°î±ªÀÌ(¾ÆÀÌÅÛ)", "images/item/°î±ªÀÌ.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("µµ³¢(¾ÆÀÌÅÛ)", "images/item/µµ³¢.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("È£¹Ì(¾ÆÀÌÅÛ)", "images/item/È£¹Ì.bmp", 48, 48, true, RGB(255, 0, 255));

	//UI
	IMAGEMANAGER->addImage("½Ã°è", "images/UI/Ui_time.bmp", 72*3, 57*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¹°¾îº¸´ÂÃ¢", "images/UI/Ui_selectDialog.bmp", 880, 228, true, RGB(255, 0, 255));

	//»óÁ¡
	IMAGEMANAGER->addImage("»óÁ¡¾ÆÀú¾¾", "images/shop/Ui_shop.bmp", 650, 395, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("»óÁ¡Ä­", "images/shop/»óÁ¡Ä­.bmp", 478, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ä«ÆêÆ®", "images/shop/Ä«ÆêÆ®.bmp", 100, 50, true, RGB(255, 0, 255));

	//Àâ°Í
	IMAGEMANAGER->addImage("³ª¹«1", "images/etc/³ª¹«1.bmp", 48, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("³ª¹«2", "images/etc/³ª¹«2.bmp", 50*3, 100*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("³ª¹«3", "images/ÀÌÆÑÆ®È¿°ú/tree_1.bmp", 142, 285, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("µ¹¸ÍÀÌ", "images/±âÅ¸µîµî/µ¹¸ÍÀÌ.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("·çºñµ¹", "images/±âÅ¸µîµî/·çºñµ¹.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÀÜµð", "images/etc/ÀÜµð.bmp", 48, 48, true, RGB(255, 0, 255));

	//³óÀå
	IMAGEMANAGER->addImage("ºñ¾îÁø ¶¥", "images/Å¸ÀÏ/ºñ¾îÁø¶¥.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¹°»Ñ¸®°³Å¸ÀÏ", "images/Å¸ÀÏ/¹°»Ñ¸®°³Å¸ÀÏ.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("È£¹ÌÅ¸ÀÏ", "images/Å¸ÀÏ/È£¹ÌÅ¸ÀÏ.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("°¨ÀÚ³óÀå", "images/Å¸ÀÏ/°¨ÀÚ³óÀå.bmp", 312, 72, 8,1,true, RGB(255, 0, 255));


	//NPC
	 IMAGEMANAGER->addFrameImage("¾Æºñ°ÔÀÏ", "images/NPC/Abigail.bmp", 64 * 3.5, 32 * 3.5, 4, 1, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addFrameImage("¾Ë·º½º", "images/NPC/Alex.bmp", 64 * 3.5, 64 * 3.5, 4, 2, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addFrameImage("¼¼¹Ù½ºÂù", "images/NPC/Sebastian.bmp", 64 * 3.5, 64 * 3.5, 4, 2, true, RGB(255, 0, 255));

	 //´ëÈ­Ã¢
	 IMAGEMANAGER->addImage("¼¼¹Ù½ºÂù´ëÈ­Ã¢", "images/NPC/Ui_dialog¼¼¹Ù½ºÂù.bmp", 800, 284, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("¾Æºñ°ÔÀÏ´ëÈ­Ã¢", "images/NPC/Ui_dialog¾Æºñ°ÔÀÏ.bmp", 800, 284, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("¾Ë·º½º´ëÈ­Ã¢", "images/NPC/Ui_dialog¾Ë·º½º.bmp", 800, 284, true, RGB(255, 0, 255));

	 //È¿°ú
	 IMAGEMANAGER->addFrameImage("³ª¹«°¡¾²·¯Áü", "images/ÀÌÆÑÆ®È¿°ú/maptool_tree1_down.bmp", 2592, 2160, 9, 5, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("ÀÜµð¶³¾îÁü", "images/ÀÌÆÑÆ®È¿°ú/animation_grass.bmp", 336, 48, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("µ¹±úÁü", "images/ÀÌÆÑÆ®È¿°ú/animation_rock.bmp", 336, 48, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("¹°¶³¾îÁü", "images/ÀÌÆÑÆ®È¿°ú/animation_water.bmp", 480, 48, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("³ª¹µÀÙ", "images/ÀÌÆÑÆ®È¿°ú/animation_removeTree.bmp", 2800, 160, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addImage("È£¹ÌÁú", "images/ÀÌÆÑÆ®È¿°ú/animation_hoe.bmp", 336, 48, true, RGB(255, 0, 255));

	 //»ç¿îµå
	 SOUNDMANAGER->addSound("ÀÎÆ®·Î", "sound/01 - Stardew Valley Overture.mp3", true, true);
	 SOUNDMANAGER->addSound("¸¶À»", "sound/05 - Spring (It's A Big World Outside).mp3", true, true);
	 SOUNDMANAGER->addSound("-", "sound/06 - Spring (The Valley Comes Alive).mp3", true, true);
	 SOUNDMANAGER->addSound("µ¿±¼", "sound/58 - Mines (Star Lumpy).mp3", true, true);

	 SOUNDMANAGER->addSound("³ª¹«»Ñ½É", "sound/³ª¹«¸¦ »Ñ½Ã´Â ¼Ò¸®.mp3", true, true);
	 SOUNDMANAGER->addSound("µµ³¢ºÎ½É", "sound/µµ³¢ºÎ½É.mp3", true, true);
	 SOUNDMANAGER->addSound("µ¹±ú´Â ¼Ò¸®", "sound/µ¹±ú´Â ¼Ò¸®.mp3", true, true);
	 SOUNDMANAGER->addSound("¸ó½ºÅÍ Á×´Â ¼Ò¸®", "sound/¸ó½ºÅÍ Á×´Â ¼Ò¸®.mp3", true, true);
	 SOUNDMANAGER->addSound("¹°»Ñ¸®´Â ¼Ò¸®", "sound/¹°»Ñ¸®´Â ¼Ò¸®.mp3", true, true);
	 SOUNDMANAGER->addSound("Ä®Áú", "sound/Ä®Áú.mp3", true, true);
	 SOUNDMANAGER->addSound("È£¹Ì»Ñ½É", "sound/È£¹Ì»Ñ½É.mp3", true, true);

}



#include "stdafx.h"
#include "mainGame.h"

/*
�̹��� ����
*/

void mainGame::maingameimg()
{
	//���� UI
	IMAGEMANAGER->addImage("����", "images/����/����UI/maptool2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/����/����UI/Ui_menuKinds.bmp", 18 * 3, 18 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "images/����/����UI/Ui_maptool_beforeButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "images/����/����UI/Ui_maptool_nextButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "images/����/����UI/Ui_cancelButton.bmp", 26 * 2, 12 * 2, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����", "images/����/����UI/Ui_maptool_erase.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ε�", "images/����/����UI/Ui_maptool_load.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/����/����UI/Ui_maptool_save.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ��", "images/����/����UI/Ui_maptool_tile.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ʈ", "images/����/����UI/Ui_maptool_object.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));


	//���� �̹���
	IMAGEMANAGER->addFrameImage("���ٴ�", "images/����/maptool_tile1_spring.bmp", 600, 600, 12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��", "images/����/maptool_tile2_spring.bmp", 600, 600,12, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/����/mine.bmp", 256, 208, 12, 12, true, RGB(255, 0, 255));


	//�÷��̾� �� 
	IMAGEMANAGER->addFrameImage("�Ӹ�", "images/cloth/�Ӹ�.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ĵ�Ƽ", "images/cloth/�ĵ�Ƽ.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));

	//��Ʈ�� ��
	IMAGEMANAGER->addImage("����ȭ��", "images/introscene/title_backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����1", "images/introscene/title_cloud1.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����2", "images/introscene/title_cloud2.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����3", "images/introscene/title_cloud3.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����4", "images/introscene/title_cloud4.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����5", "images/introscene/title_cloud5.bmp", WINSIZEX*2 , WINSIZEY*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����6", "images/introscene/title_cloud10.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����7", "images/introscene/title_cloud6.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "images/introscene/��������.bmp",600, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/introscene/����.bmp", 148*3, 58*3, 2, 1,true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ư", "images/introscene/map.bmp", 148*3, 58*3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������ư", "images/introscene/������.bmp", 148*3, 58*3, 2, 1, true, RGB(255, 0, 255));
	
}



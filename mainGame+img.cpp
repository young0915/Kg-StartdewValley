#include "stdafx.h"
#include "mainGame.h"

/*
�̹��� ����
*/

void mainGame::maingameimg()
{
	//����
	IMAGEMANAGER->addImage("����", "images/����/maptool2.bmp", /*800, 500*/WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/����/Ui_menuKinds.bmp", 18*3, 18*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "images/����/Ui_maptool_beforeButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "images/����/Ui_maptool_nextButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "images/����/Ui_cancelButton.bmp", 26 * 2, 12 * 2, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����", "images/����/Ui_maptool_erase.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ε�", "images/����/Ui_maptool_load.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/����/Ui_maptool_save.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ��", "images/����/Ui_maptool_tile.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ʈ", "images/����/Ui_maptool_object.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));

	//�÷��̾� �� 
	IMAGEMANAGER->addFrameImage("�Ӹ�", "images/cloth/�Ӹ�.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ĵ�Ƽ", "images/cloth/�ĵ�Ƽ.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));
}



